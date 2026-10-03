// Copyright Epic Games, Inc. All Rights Reserved.

#include "EndlessRoadGenerator.h"

FEndlessRoadGenerator::FEndlessRoadGenerator(int32 InSeed, const FEndlessRoadGeneratorSettings& InSettings)
	: Settings(InSettings)
{
	Reset(InSeed);
}

void FEndlessRoadGenerator::Reset(int32 InSeed)
{
	Seed = InSeed;
	Stream.Initialize(Seed);

	Segments.Reset();
	PendingPlans.Reset();
	PendingIndex = 0;

	EndPos = FVector2D::ZeroVector;
	EndHeading = 0.0;
	EndZ = Settings.StartElevation;
	EndDistance = 0.0;
	bLastWasBridge = false;

	// always start with a long, flat straight so the car can get up to speed
	FSegmentPlan RunUp;
	RunUp.Type = EEndlessSegmentType::Straight;
	RunUp.Length = Settings.InitialStraightLength;
	AppendFromPlan(RunUp);
}

void FEndlessRoadGenerator::EnsureGeneratedTo(double Distance)
{
	// guard against runaway loops from bad input
	int32 Safety = 100000;

	while (EndDistance < Distance && Safety-- > 0)
	{
		GenerateNext();
	}
}

FEndlessRoadSample FEndlessRoadGenerator::SampleAtDistance(double Distance)
{
	EnsureGeneratedTo(Distance + 1.0);

	const int32 Index = FindSegmentIndex(Distance);
	const FEndlessRoadSegment& Segment = Segments[Index];

	FEndlessRoadSample Sample = EvaluateSegment(Segment, Distance - Segment.StartDistance);
	Sample.Distance = FMath::Max(Distance, Segment.StartDistance);
	return Sample;
}

void FEndlessRoadGenerator::PruneBefore(double Distance)
{
	int32 NumToRemove = 0;

	// always keep at least the last segment
	while (NumToRemove < Segments.Num() - 1 && Segments[NumToRemove].GetEndDistance() < Distance)
	{
		++NumToRemove;
	}

	if (NumToRemove > 0)
	{
		Segments.RemoveAt(0, NumToRemove);
	}
}

FEndlessRoadSample FEndlessRoadGenerator::EvaluateSegment(const FEndlessRoadSegment& Segment, double S)
{
	const double L = FMath::Max(Segment.Length, 1.0);
	S = FMath::Clamp(S, 0.0, L);
	const double T = S / L;

	// heading and planar position along a constant curvature arc
	const double H0 = Segment.StartHeading;
	const double K = Segment.Curvature;
	const double H = H0 + K * S;

	FVector2D Pos;
	if (FMath::Abs(K) < 1e-9)
	{
		Pos = Segment.StartPos + FVector2D(FMath::Cos(H0), FMath::Sin(H0)) * S;
	}
	else
	{
		Pos = Segment.StartPos + FVector2D(FMath::Sin(H) - FMath::Sin(H0), FMath::Cos(H0) - FMath::Cos(H)) / K;
	}

	// smoothstep elevation blend, zero grade at both ends keeps joins smooth
	const double Smooth = T * T * (3.0 - 2.0 * T);
	const double Z = FMath::Lerp(Segment.StartZ, Segment.EndZ, Smooth);
	const double Grade = (Segment.EndZ - Segment.StartZ) * 6.0 * T * (1.0 - T) / L;

	// bank eases in and out so it is zero at the segment joins
	const double BankDeg = Segment.MaxBankDeg * FMath::Sin(UE_DOUBLE_PI * T);
	const double BankRad = FMath::DegreesToRadians(BankDeg);

	FEndlessRoadSample Sample;
	Sample.Location = FVector(Pos.X, Pos.Y, Z);
	Sample.Heading = H;
	Sample.BankDeg = BankDeg;
	Sample.bIsBridge = Segment.bIsBridge;
	Sample.Distance = Segment.StartDistance + S;

	Sample.Forward = FVector(FMath::Cos(H), FMath::Sin(H), Grade).GetSafeNormal();
	Sample.RightFlat = FVector(-FMath::Sin(H), FMath::Cos(H), 0.0);

	// a positive bank lowers the right edge
	const FVector RightBanked = Sample.RightFlat * FMath::Cos(BankRad) - FVector::UpVector * FMath::Sin(BankRad);
	Sample.Right = (RightBanked - Sample.Forward * FVector::DotProduct(RightBanked, Sample.Forward)).GetSafeNormal();
	Sample.Up = FVector::CrossProduct(Sample.Forward, Sample.Right).GetSafeNormal();

	return Sample;
}

void FEndlessRoadGenerator::GenerateNext()
{
	if (PendingIndex >= PendingPlans.Num())
	{
		PendingPlans.Reset();
		PendingIndex = 0;
		PlanNextFeature(EndHeading, EndZ, bLastWasBridge);
	}

	AppendFromPlan(PendingPlans[PendingIndex++]);
}

void FEndlessRoadGenerator::PlanNextFeature(double CurrentHeading, double CurrentZ, bool bAfterBridge)
{
	const double MaxDrift = Settings.MaxHeadingDriftDeg;
	double HeadingDeg = FMath::RadiansToDegrees(CurrentHeading);

	// picks a turn direction that keeps the heading inside the drift band, biased back towards +X
	auto PickTurn = [&](double AngleDeg) -> double
	{
		double Dir = Stream.FRand() < 0.5f ? -1.0 : 1.0;

		if (FMath::Abs(HeadingDeg) > 45.0 && Stream.FRand() < 0.75f)
		{
			Dir = HeadingDeg > 0.0 ? -1.0 : 1.0;
		}

		if (FMath::Abs(HeadingDeg + Dir * AngleDeg) > MaxDrift)
		{
			Dir = -Dir;
		}

		// still too far? shrink the turn so it ends on the band edge
		double Signed = Dir * AngleDeg;
		if (FMath::Abs(HeadingDeg + Signed) > MaxDrift)
		{
			Signed = FMath::Clamp(HeadingDeg + Signed, -MaxDrift, MaxDrift) - HeadingDeg;
		}

		HeadingDeg += Signed;
		return Signed;
	};

	auto ClampLand = [&](double Z)
	{
		return FMath::Clamp(Z, Settings.MinLandElevation, Settings.MaxLandElevation);
	};

	const bool bCanSwitchback = FMath::Abs(HeadingDeg) < 12.0;

	const double WStraight = Settings.WeightStraight;
	const double WCurve = Settings.WeightCurve;
	const double WHill = Settings.WeightHill;
	const double WBridge = bAfterBridge ? 0.0 : Settings.WeightBridge;
	const double WSwitch = bCanSwitchback ? Settings.WeightSwitchback : 0.0;
	const double Total = WStraight + WCurve + WHill + WBridge + WSwitch;

	double Pick = Stream.FRandRange(0.0f, 1.0f) * Total;

	if ((Pick -= WStraight) < 0.0)
	{
		FSegmentPlan Plan;
		Plan.Type = EEndlessSegmentType::Straight;
		Plan.Length = Stream.FRandRange(12000.0f, 35000.0f);
		PendingPlans.Add(Plan);
	}
	else if ((Pick -= WCurve) < 0.0)
	{
		// single curve, sometimes followed by a reverse curve (S bend)
		const int32 NumCurves = Stream.FRand() < 0.4f ? 2 : 1;
		double LastDir = 0.0;

		for (int32 i = 0; i < NumCurves; ++i)
		{
			const double Radius = Stream.FRandRange(25000.0f, 90000.0f);
			const double AngleDeg = Stream.FRandRange(15.0f, 65.0f);

			double SignedDeg;
			if (i > 0 && FMath::Abs(HeadingDeg - LastDir * AngleDeg) <= MaxDrift)
			{
				// reverse the previous bend
				SignedDeg = -LastDir * AngleDeg;
				HeadingDeg += SignedDeg;
			}
			else
			{
				SignedDeg = PickTurn(AngleDeg);
			}

			LastDir = FMath::Sign(SignedDeg);

			FSegmentPlan Plan;
			Plan.Type = EEndlessSegmentType::Curve;
			Plan.TurnAngle = FMath::DegreesToRadians(SignedDeg);
			Plan.Length = FMath::Max(Radius * FMath::Abs(Plan.TurnAngle), 5000.0);

			// tighter curves get more bank
			const double Tightness = 1.0 - (Radius - 25000.0) / 65000.0;
			Plan.MaxBankDeg = LastDir * FMath::Lerp(2.5, 7.0, Tightness);

			// curves may also climb or dip a little
			Plan.bKeepZ = false;
			Plan.TargetZ = ClampLand(CurrentZ + Stream.FRandRange(-400.0f, 400.0f));
			CurrentZ = Plan.TargetZ;

			PendingPlans.Add(Plan);
		}
	}
	else if ((Pick -= WHill) < 0.0)
	{
		FSegmentPlan Plan;
		Plan.Type = EEndlessSegmentType::Hill;
		Plan.Length = Stream.FRandRange(18000.0f, 32000.0f);
		Plan.TurnAngle = FMath::DegreesToRadians(PickTurn(Stream.FRandRange(0.0f, 12.0f)));
		Plan.MaxBankDeg = FMath::Sign(Plan.TurnAngle) * 1.5;
		Plan.bKeepZ = false;
		Plan.TargetZ = ClampLand(CurrentZ + Stream.FRandRange(-900.0f, 900.0f));
		PendingPlans.Add(Plan);
	}
	else if ((Pick -= WBridge) < 0.0)
	{
		// ramp up, bridge deck over the sea, ramp down
		FSegmentPlan RampUp;
		RampUp.Type = EEndlessSegmentType::Hill;
		RampUp.Length = 30000.0;
		RampUp.bKeepZ = false;
		RampUp.TargetZ = Settings.BridgeElevation;
		PendingPlans.Add(RampUp);

		FSegmentPlan Deck;
		Deck.Type = EEndlessSegmentType::Bridge;
		Deck.Length = Stream.FRandRange(30000.0f, 60000.0f);
		Deck.TurnAngle = FMath::DegreesToRadians(PickTurn(Stream.FRandRange(0.0f, 20.0f)));
		Deck.MaxBankDeg = FMath::Sign(Deck.TurnAngle) * 2.0;
		Deck.bIsBridge = true;
		PendingPlans.Add(Deck);

		FSegmentPlan RampDown;
		RampDown.Type = EEndlessSegmentType::Hill;
		RampDown.Length = 30000.0;
		RampDown.bKeepZ = false;
		RampDown.TargetZ = Stream.FRandRange(float(Settings.MinLandElevation + 200.0), float(Settings.MaxLandElevation - 400.0));
		PendingPlans.Add(RampDown);
	}
	else
	{
		// switchback: long approach, U-turn, short return leg, U-turn back, exit straight.
		// The switchback only reaches back about 300 m, less than the 500 m approach, and older road
		// always lies further back along +X, so the legs never cross it.
		const double Dir = Stream.FRand() < 0.5f ? -1.0 : 1.0;
		const double Radius = Stream.FRandRange(8500.0f, 10500.0f);

		FSegmentPlan Approach;
		Approach.Type = EEndlessSegmentType::Straight;
		Approach.Length = 50000.0;
		Approach.bInSwitchback = true;
		PendingPlans.Add(Approach);

		FSegmentPlan TurnA;
		TurnA.Type = EEndlessSegmentType::Hairpin;
		TurnA.TurnAngle = Dir * UE_DOUBLE_PI;
		TurnA.Length = Radius * UE_DOUBLE_PI;
		TurnA.MaxBankDeg = Dir * 8.0;
		TurnA.bInSwitchback = true;
		PendingPlans.Add(TurnA);

		FSegmentPlan Return;
		Return.Type = EEndlessSegmentType::Straight;
		Return.Length = Stream.FRandRange(12000.0f, 18000.0f);
		Return.bInSwitchback = true;
		PendingPlans.Add(Return);

		FSegmentPlan TurnB = TurnA;
		TurnB.TurnAngle = -TurnA.TurnAngle;
		TurnB.MaxBankDeg = -TurnA.MaxBankDeg;
		PendingPlans.Add(TurnB);

		FSegmentPlan Exit;
		Exit.Type = EEndlessSegmentType::Straight;
		Exit.Length = 25000.0;
		Exit.bInSwitchback = true;
		PendingPlans.Add(Exit);
	}
}

void FEndlessRoadGenerator::AppendFromPlan(const FSegmentPlan& Plan)
{
	FEndlessRoadSegment Segment;
	Segment.Type = Plan.Type;
	Segment.StartDistance = EndDistance;
	Segment.Length = FMath::Max(Plan.Length, 100.0);
	Segment.StartPos = EndPos;
	Segment.StartHeading = EndHeading;
	Segment.Curvature = Plan.TurnAngle / Segment.Length;
	Segment.StartZ = EndZ;
	Segment.EndZ = Plan.bKeepZ ? EndZ : Plan.TargetZ;
	Segment.MaxBankDeg = Plan.MaxBankDeg;
	Segment.bIsBridge = Plan.bIsBridge;
	Segment.bInSwitchback = Plan.bInSwitchback;

	// compute the end state from the analytic curve so joins are exact
	const FEndlessRoadSample End = EvaluateSegment(Segment, Segment.Length);
	EndPos = FVector2D(End.Location.X, End.Location.Y);
	EndHeading = Segment.GetEndHeading();
	EndZ = Segment.EndZ;
	EndDistance = Segment.GetEndDistance();
	bLastWasBridge = Segment.bIsBridge;

	Segments.Add(Segment);
}

int32 FEndlessRoadGenerator::FindSegmentIndex(double Distance) const
{
	// binary search for the last segment starting at or before Distance
	int32 Low = 0;
	int32 High = Segments.Num() - 1;

	while (Low < High)
	{
		const int32 Mid = (Low + High + 1) / 2;

		if (Segments[Mid].StartDistance <= Distance)
		{
			Low = Mid;
		}
		else
		{
			High = Mid - 1;
		}
	}

	return Low;
}
