// Copyright Epic Games, Inc. All Rights Reserved.

#include "AstheticDriveWheelRear.h"
#include "UObject/ConstructorHelpers.h"

UAstheticDriveWheelRear::UAstheticDriveWheelRear()
{
	AxleType = EAxleType::Rear;
	bAffectedByHandbrake = true;
	bAffectedByEngine = true;
}