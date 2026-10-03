// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AstheticDrivePawn.h"
#include "AstheticDriveSportsCar.generated.h"

/**
 *  Sports car wheeled vehicle implementation
 */
UCLASS(abstract)
class AAstheticDriveSportsCar : public AAstheticDrivePawn
{
	GENERATED_BODY()
	
public:

	AAstheticDriveSportsCar();
};
