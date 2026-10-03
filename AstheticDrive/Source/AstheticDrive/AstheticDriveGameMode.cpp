// Copyright Epic Games, Inc. All Rights Reserved.

#include "AstheticDriveGameMode.h"
#include "AstheticDrivePlayerController.h"

AAstheticDriveGameMode::AAstheticDriveGameMode()
{
	PlayerControllerClass = AAstheticDrivePlayerController::StaticClass();
}
