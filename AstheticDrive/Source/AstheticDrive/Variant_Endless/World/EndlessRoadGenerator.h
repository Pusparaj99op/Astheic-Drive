// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/RandomStream.h"
#include "EndlessRoadTypes.h"

/** Tunables for the endless road generator. All lengths in cm */
struct FEndlessRoadGeneratorSettings
{
	/** Height of the road above the sea (Z = 0) when the run starts */
	double StartElevation = 1200.0;

	/** Lowest allowed land road height */
	double MinLandElevation = 600.0;

	/** Highest allowed land road height */
	double MaxLandElevation = 2200.0;

	/** Deck height of bridges */
	double BridgeElevation = 2800.0;

	/** Max angle the road heading may drift away from +X (outside switchbacks), in degrees.
	 *  Keeping this below 90 means the road always makes progress along +X, so it can never cross itself */
	double MaxHeadingDriftDeg = 75.0;

	/** Length of the straight run-up before the first generated feature */
	double InitialStraightLength = 30000.0;

	/** Relative weights for picking the next feature */
	double WeightStraight = 25.0;
	double WeightCurve = 42.0;
	double WeightHill = 18.0;
	double WeightBridge = 9.0;
	double WeightSwitchback = 6.0;
};

/**
 *  Deterministic, seeded generator of an infinite road centerline.
 *  Segments are generated lazily when sampling further along the road, and old ones can be pruned.
 *  Plain C++ (no UObject) so it can be unit tested and run off the game thread if needed.
 */
class FEndlessRoadGenerator
{
public:

	explicit FEndlessRoadGenerator(int32 InSeed = 1337, const FEndlessRoadGeneratorSettings& InSettings = FEndlessRoadGeneratorSettings());

	/** Restarts the road from the origin with a new seed */
	void Reset(int32 InSeed);

	/** Generates segments until the road reaches at least Distance */
	void EnsureGeneratedTo(double Distance);

	/** Samples the road centerline at the given distance. Generates more road as needed */
	FEndlessRoadSample SampleAtDistance(double Distance);

	/** Drops segments that end before Distance. Sampling before the first kept segment clamps to it */
	void PruneBefore(double Distance);

	/** Returns the currently cached segments */
	const TArray<FEndlessRoadSegment>& GetSegments() const { return Segments; }

	/** Returns the seed in use */
	int32 GetSeed() const { return Seed; }

	/** Returns the settings in use */
	const FEndlessRoadGeneratorSettings& GetSettings() const { return Settings; }

	/** Evaluates a sample inside a single segment at local distance S (0..Length) */
	static FEndlessRoadSample EvaluateSegment(const FEndlessRoadSegment& Segment, double S);

private:

	/** A planned piece of road, before it is placed at the end of the previous segment */
	struct FSegmentPlan
	{
		EEndlessSegmentType Type = EEndlessSegmentType::Straight;
		double Length = 10000.0;
		double TurnAngle = 0.0;
		double TargetZ = -1.0;
		double MaxBankDeg = 0.0;
		bool bIsBridge = false;
		bool bInSwitchback = false;
		bool bKeepZ = true;
	};

	/** Appends one more segment, refilling the plan queue when it runs dry */
	void GenerateNext();

	/** Fills the plan queue with the next feature */
	void PlanNextFeature(double CurrentHeading, double CurrentZ, bool bLastWasBridge);

	/** Places a plan at the end of the road */
	void AppendFromPlan(const FSegmentPlan& Plan);

	/** Finds the cached segment containing Distance */
	int32 FindSegmentIndex(double Distance) const;

	int32 Seed = 0;
	FEndlessRoadGeneratorSettings Settings;
	FRandomStream Stream;
	TArray<FEndlessRoadSegment> Segments;
	TArray<FSegmentPlan> PendingPlans;
	int32 PendingIndex = 0;

	/** End state of the last generated segment */
	FVector2D EndPos = FVector2D::ZeroVector;
	double EndHeading = 0.0;
	double EndZ = 0.0;
	double EndDistance = 0.0;
	bool bLastWasBridge = false;
};
