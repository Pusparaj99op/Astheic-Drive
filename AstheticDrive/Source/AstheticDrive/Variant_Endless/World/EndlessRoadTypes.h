// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

/** Road cross-section dimensions (cm). Shared by the chunk mesher and gameplay code */
namespace EndlessRoadLayout
{
	/** Width of one lane */
	constexpr double LaneWidth = 350.0;

	/** Half width of the asphalt (4 lanes) */
	constexpr double RoadHalfWidth = 700.0;

	/** Lateral position of the inner face of the guard rails */
	constexpr double RailOffset = 1000.0;

	/** Lane centers. Positive = right side = player's direction of travel */
	constexpr double LaneCenters[4] = { -525.0, -175.0, 175.0, 525.0 };
}

/** Kind of road piece emitted by the endless road generator */
enum class EEndlessSegmentType : uint8
{
	Straight,
	Curve,
	Hill,
	Hairpin,
	Bridge
};

/**
 *  One analytic piece of the endless road.
 *  The centerline is a constant-curvature arc in XY (a straight line when Curvature is zero),
 *  with a smoothstep elevation blend and a bank that eases in and out at both ends.
 *  All distances are in Unreal units (cm), angles in radians unless noted.
 */
struct FEndlessRoadSegment
{
	/** Segment kind */
	EEndlessSegmentType Type = EEndlessSegmentType::Straight;

	/** Distance along the road where this segment starts */
	double StartDistance = 0.0;

	/** Length of the segment along the centerline */
	double Length = 0.0;

	/** XY position of the segment start */
	FVector2D StartPos = FVector2D::ZeroVector;

	/** Yaw of the centerline at the segment start. 0 = +X, positive turns towards +Y (right) */
	double StartHeading = 0.0;

	/** Signed curvature (1 / radius). Positive turns right */
	double Curvature = 0.0;

	/** Road surface height at the segment start */
	double StartZ = 0.0;

	/** Road surface height at the segment end */
	double EndZ = 0.0;

	/** Peak bank angle in degrees. Positive lowers the right edge */
	double MaxBankDeg = 0.0;

	/** True if this piece is an elevated bridge over the sea */
	bool bIsBridge = false;

	/** True if this piece belongs to a switchback (paired U-turns) */
	bool bInSwitchback = false;

	/** Distance along the road where this segment ends */
	double GetEndDistance() const { return StartDistance + Length; }

	/** Heading at the segment end */
	double GetEndHeading() const { return StartHeading + Curvature * Length; }
};

/** A sampled point on the road centerline */
struct FEndlessRoadSample
{
	/** World location of the road surface centerline */
	FVector Location = FVector::ZeroVector;

	/** Unit forward direction, follows the road grade */
	FVector Forward = FVector::ForwardVector;

	/** Unit right direction, includes bank */
	FVector Right = FVector::RightVector;

	/** Unit up direction (surface normal) */
	FVector Up = FVector::UpVector;

	/** Horizontal right direction, no bank */
	FVector RightFlat = FVector::RightVector;

	/** Yaw of the road in radians */
	double Heading = 0.0;

	/** Current bank in degrees */
	double BankDeg = 0.0;

	/** Distance along the road */
	double Distance = 0.0;

	/** True if this point is on a bridge */
	bool bIsBridge = false;

	/** Returns a transform on the road surface, offset laterally by LateralOffset (positive = right) */
	FTransform ToTransform(double LateralOffset = 0.0) const
	{
		const FRotator Rot = FRotationMatrix::MakeFromXY(Forward, Right).Rotator();
		return FTransform(Rot, Location + Right * LateralOffset);
	}
};
