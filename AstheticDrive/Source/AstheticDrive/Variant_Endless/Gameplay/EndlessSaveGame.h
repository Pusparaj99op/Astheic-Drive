// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "EndlessSaveGame.generated.h"

/**
 *  Persistent progress for the endless driving mode
 */
UCLASS()
class UEndlessSaveGame : public USaveGame
{
	GENERATED_BODY()

public:

	/** Save slot name */
	static const TCHAR* SlotName;

	/** Best score of a single run */
	UPROPERTY(VisibleAnywhere, Category="Progress")
	int32 BestScore = 0;

	/** Longest single run in meters */
	UPROPERTY(VisibleAnywhere, Category="Progress")
	float BestDistanceMeters = 0.0f;

	/** Coins collected over all runs. The future garage spends these */
	UPROPERTY(VisibleAnywhere, Category="Progress")
	int32 TotalCoins = 0;

	/** Best near miss combo */
	UPROPERTY(VisibleAnywhere, Category="Progress")
	int32 BestCombo = 0;

	/** Number of finished runs */
	UPROPERTY(VisibleAnywhere, Category="Progress")
	int32 RunsPlayed = 0;
};
