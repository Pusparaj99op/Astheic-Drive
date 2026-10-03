// Copyright Epic Games, Inc. All Rights Reserved.

#include "EndlessRoadGenerator.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

namespace EndlessRoadTests
{
	/** Length of road the tests generate (cm) */
	constexpr double TestLength = 5000000.0; // 50 km

	/** Max allowed position mismatch at segment joins (cm) */
	constexpr double JoinTolerance = 0.5;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FEndlessRoadDeterminismTest, "AstheticDrive.Endless.RoadGenerator.Determinism",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ClientContext | EAutomationTestFlags::EngineFilter)

bool FEndlessRoadDeterminismTest::RunTest(const FString& Parameters)
{
	FEndlessRoadGenerator A(4242);
	FEndlessRoadGenerator B(4242);
	FEndlessRoadGenerator C(4243);

	bool bAnyDifferent = false;

	for (double Distance = 0.0; Distance < 1000000.0; Distance += 777.0)
	{
		const FEndlessRoadSample SA = A.SampleAtDistance(Distance);
		const FEndlessRoadSample SB = B.SampleAtDistance(Distance);
		const FEndlessRoadSample SC = C.SampleAtDistance(Distance);

		if (!SA.Location.Equals(SB.Location, 1e-6) || !SA.Forward.Equals(SB.Forward, 1e-9))
		{
			AddError(FString::Printf(TEXT("Same seed diverged at distance %.0f"), Distance));
			return false;
		}

		bAnyDifferent |= !SA.Location.Equals(SC.Location, 100.0);
	}

	TestTrue(TEXT("Different seeds produce different roads"), bAnyDifferent);

	// sampling order must not matter
	FEndlessRoadGenerator D(4242);
	const FEndlessRoadSample Far = D.SampleAtDistance(800000.0);
	const FEndlessRoadSample Near = D.SampleAtDistance(1000.0);
	TestTrue(TEXT("Out of order sampling matches (far)"), Far.Location.Equals(A.SampleAtDistance(800000.0).Location, 1e-6));
	TestTrue(TEXT("Out of order sampling matches (near)"), Near.Location.Equals(A.SampleAtDistance(1000.0).Location, 1e-6));

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FEndlessRoadContinuityTest, "AstheticDrive.Endless.RoadGenerator.Continuity",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ClientContext | EAutomationTestFlags::EngineFilter)

bool FEndlessRoadContinuityTest::RunTest(const FString& Parameters)
{
	for (const int32 Seed : { 1, 99, 2024, 777777 })
	{
		FEndlessRoadGenerator Generator(Seed);
		Generator.EnsureGeneratedTo(EndlessRoadTests::TestLength);

		const TArray<FEndlessRoadSegment>& Segments = Generator.GetSegments();
		TestTrue(TEXT("Generated segments"), Segments.Num() > 10);

		for (int32 i = 1; i < Segments.Num(); ++i)
		{
			const FEndlessRoadSegment& Prev = Segments[i - 1];
			const FEndlessRoadSegment& Next = Segments[i];

			const FEndlessRoadSample End = FEndlessRoadGenerator::EvaluateSegment(Prev, Prev.Length);
			const FEndlessRoadSample Start = FEndlessRoadGenerator::EvaluateSegment(Next, 0.0);

			if (!End.Location.Equals(Start.Location, EndlessRoadTests::JoinTolerance))
			{
				AddError(FString::Printf(TEXT("Seed %d: position gap of %.3f cm at segment %d"), Seed, FVector::Dist(End.Location, Start.Location), i));
				return false;
			}

			if (!FMath::IsNearlyEqual(Prev.GetEndHeading(), Next.StartHeading, 1e-6))
			{
				AddError(FString::Printf(TEXT("Seed %d: heading jump at segment %d"), Seed, i));
				return false;
			}

			if (!FMath::IsNearlyEqual(Prev.GetEndDistance(), Next.StartDistance, 1e-6))
			{
				AddError(FString::Printf(TEXT("Seed %d: distance gap at segment %d"), Seed, i));
				return false;
			}
		}
	}

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FEndlessRoadBoundsTest, "AstheticDrive.Endless.RoadGenerator.Bounds",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ClientContext | EAutomationTestFlags::EngineFilter)

bool FEndlessRoadBoundsTest::RunTest(const FString& Parameters)
{
	for (const int32 Seed : { 3, 1234, 98765 })
	{
		FEndlessRoadGenerator Generator(Seed);
		const FEndlessRoadGeneratorSettings& Settings = Generator.GetSettings();
		Generator.EnsureGeneratedTo(EndlessRoadTests::TestLength);

		const double MaxDrift = FMath::DegreesToRadians(Settings.MaxHeadingDriftDeg) + 1e-6;
		const double MinZ = FMath::Min(Settings.MinLandElevation, Settings.StartElevation) - 1.0;
		const double MaxZ = Settings.BridgeElevation + 1.0;

		const TArray<FEndlessRoadSegment>& Segments = Generator.GetSegments();

		for (int32 Index = 0; Index < Segments.Num(); ++Index)
		{
			const FEndlessRoadSegment& Segment = Segments[Index];

			// heading stays in the drift band, except inside switchbacks which turn back on themselves
			if (!Segment.bInSwitchback)
			{
				if (FMath::Abs(Segment.StartHeading) > MaxDrift || FMath::Abs(Segment.GetEndHeading()) > MaxDrift)
				{
					AddError(FString::Printf(TEXT("Seed %d: heading out of band at distance %.0f"), Seed, Segment.StartDistance));
					return false;
				}
			}

			if (Segment.StartZ < MinZ || Segment.StartZ > MaxZ || Segment.EndZ < MinZ || Segment.EndZ > MaxZ)
			{
				AddError(FString::Printf(TEXT("Seed %d: elevation out of range at distance %.0f"), Seed, Segment.StartDistance));
				return false;
			}

			// every hairpin is part of a switchback: paired with an opposite hairpin two segments away
			if (Segment.Type == EEndlessSegmentType::Hairpin)
			{
				TestTrue(TEXT("Hairpins are part of a switchback"), Segment.bInSwitchback);

				auto IsPartner = [&](int32 Other)
				{
					return Segments.IsValidIndex(Other) && Segments[Other].Type == EEndlessSegmentType::Hairpin && Segments[Other].Curvature * Segment.Curvature < 0.0;
				};

				// the generator may stop in the middle of a switchback, so a missing partner past the end is fine
				const bool bPaired = IsPartner(Index + 2) || IsPartner(Index - 2) || Index + 2 >= Segments.Num();
				if (!bPaired)
				{
					AddError(FString::Printf(TEXT("Seed %d: unpaired hairpin at distance %.0f"), Seed, Segment.StartDistance));
					return false;
				}
			}

			if (Segment.bIsBridge)
			{
				TestTrue(TEXT("Bridges sit at bridge height"), FMath::IsNearlyEqual(Segment.StartZ, Settings.BridgeElevation, 1.0) && FMath::IsNearlyEqual(Segment.EndZ, Settings.BridgeElevation, 1.0));
			}
		}

		// sample the whole road for NaNs and unit vectors
		for (double Distance = 0.0; Distance < EndlessRoadTests::TestLength; Distance += 997.0)
		{
			const FEndlessRoadSample S = Generator.SampleAtDistance(Distance);

			if (S.Location.ContainsNaN() || S.Forward.ContainsNaN() || S.Right.ContainsNaN() || S.Up.ContainsNaN())
			{
				AddError(FString::Printf(TEXT("Seed %d: NaN at distance %.0f"), Seed, Distance));
				return false;
			}

			if (!S.Forward.IsNormalized() || !S.Right.IsNormalized() || !S.Up.IsNormalized() || S.Up.Z <= 0.5)
			{
				AddError(FString::Printf(TEXT("Seed %d: bad basis at distance %.0f"), Seed, Distance));
				return false;
			}
		}
	}

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FEndlessRoadPruneTest, "AstheticDrive.Endless.RoadGenerator.Prune",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ClientContext | EAutomationTestFlags::EngineFilter)

bool FEndlessRoadPruneTest::RunTest(const FString& Parameters)
{
	FEndlessRoadGenerator Reference(55);
	FEndlessRoadGenerator Pruned(55);

	// stream forward while pruning, like the game does, and compare against an unpruned road
	for (double Distance = 0.0; Distance < 2000000.0; Distance += 5000.0)
	{
		const FEndlessRoadSample A = Reference.SampleAtDistance(Distance);
		const FEndlessRoadSample B = Pruned.SampleAtDistance(Distance);

		if (!A.Location.Equals(B.Location, 1e-6))
		{
			AddError(FString::Printf(TEXT("Pruned road diverged at %.0f"), Distance));
			return false;
		}

		Pruned.PruneBefore(Distance - 40000.0);
	}

	TestTrue(TEXT("Pruning keeps the cache small"), Pruned.GetSegments().Num() < Reference.GetSegments().Num());
	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
