// Copyright Epic Games, Inc. All Rights Reserved.

#include "AstheticDriveWheelFront.h"
#include "UObject/ConstructorHelpers.h"

UAstheticDriveWheelFront::UAstheticDriveWheelFront()
{
	AxleType = EAxleType::Front;
	bAffectedBySteering = true;
	MaxSteerAngle = 40.f;
}