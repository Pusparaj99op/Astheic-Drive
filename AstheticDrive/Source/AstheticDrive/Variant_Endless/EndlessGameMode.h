// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "EndlessGameMode.generated.h"

class AEndlessRoadStreamer;
class AEndlessTrafficManager;
class AEndlessEnvironment;
class UEndlessSaveGame;
class UEndlessBiomeData;

/** Score state of the current run */
USTRUCT(BlueprintType)
struct FEndlessRunStats
{
	GENERATED_BODY()

	/** Distance driven this run, meters */
	UPROPERTY(BlueprintReadOnly, Category="Run")
	float DistanceMeters = 0.0f;

	/** Score this run */
	UPROPERTY(BlueprintReadOnly, Category="Run")
	int32 Score = 0;

	/** Coins collected this run */
	UPROPERTY(BlueprintReadOnly, Category="Run")
	int32 Coins = 0;

	/** Current near miss combo */
	UPROPERTY(BlueprintReadOnly, Category="Run")
	int32 Combo = 0;

	/** Best combo this run */
	UPROPERTY(BlueprintReadOnly, Category="Run")
	int32 BestCombo = 0;

	/** Near misses this run */
	UPROPERTY(BlueprintReadOnly, Category="Run")
	int32 NearMisses = 0;

	/** Current speed based score multiplier */
	UPROPERTY(BlueprintReadOnly, Category="Run")
	float Multiplier = 1.0f;
};

/** A short message shown by the HUD, e.g. "NEAR MISS x3" */
USTRUCT(BlueprintType)
struct FEndlessPopup
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category="Popup")
	FString Text;

	UPROPERTY(BlueprintReadOnly, Category="Popup")
	FLinearColor Color = FLinearColor::White;

	/** Seconds left on screen */
	UPROPERTY(BlueprintReadOnly, Category="Popup")
	float TimeLeft = 0.0f;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEndlessNearMissDelegate, int32, Combo);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEndlessCrashDelegate, bool, bRunOver);

/**
 *  Game mode for the endless coastal highway.
 *  Spawns the streamed road, traffic and dusk environment, places the player on the road
 *  and runs the score loop: distance x speed multiplier, near miss combos, coins, crashes.
 *  Works without any Blueprint subclass: drop it on an empty level (or name the level Lvl_Endless...).
 */
UCLASS()
class AEndlessGameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:

	/** Optional biome look passed to the road streamer */
	UPROPERTY(EditAnywhere, Category="Endless|World")
	TObjectPtr<UEndlessBiomeData> Biome;

	/** Road seed. 0 = random every session */
	UPROPERTY(EditAnywhere, Category="Endless|World")
	int32 RoadSeed = 0;

	/** Spawn the dusk lighting rig when the level has no directional light */
	UPROPERTY(EditAnywhere, Category="Endless|World")
	bool bSpawnEnvironment = true;

	/** Spawn traffic */
	UPROPERTY(EditAnywhere, Category="Endless|World")
	bool bSpawnTraffic = true;

	/** Impact speed that ends the run, km/h. Softer hits only break the combo */
	UPROPERTY(EditAnywhere, Category="Endless|Rules")
	float RunEndingImpactKmh = 45.0f;

	/** Seconds before a new run starts after a crash */
	UPROPERTY(EditAnywhere, Category="Endless|Rules")
	float RestartDelay = 3.0f;

	/** Seconds without a near miss before the combo resets */
	UPROPERTY(EditAnywhere, Category="Endless|Rules")
	float ComboTimeout = 5.0f;

	/** Base points for a near miss, multiplied by the combo */
	UPROPERTY(EditAnywhere, Category="Endless|Rules")
	int32 NearMissPoints = 100;

	/** Extra multiplier for near missing oncoming traffic */
	UPROPERTY(EditAnywhere, Category="Endless|Rules")
	float OncomingBonus = 1.5f;

	/** Points per coin */
	UPROPERTY(EditAnywhere, Category="Endless|Rules")
	int32 CoinPoints = 50;

	/** Speed at which the score multiplier reaches 2x, km/h */
	UPROPERTY(EditAnywhere, Category="Endless|Rules")
	float DoubleMultiplierSpeedKmh = 150.0f;

	/** Road streamer */
	UPROPERTY(Transient)
	TObjectPtr<AEndlessRoadStreamer> Streamer;

	/** Traffic */
	UPROPERTY(Transient)
	TObjectPtr<AEndlessTrafficManager> Traffic;

	/** Save data */
	UPROPERTY(Transient)
	TObjectPtr<UEndlessSaveGame> SaveData;

	/** Current run */
	FEndlessRunStats Stats;

	/** HUD messages */
	TArray<FEndlessPopup> Popups;

	/** Road distance where the run started */
	double RunStartDistance = 0.0;

	/** Furthest road distance reached this run */
	double FurthestDistance = 0.0;

	/** Fractional score carried between frames */
	double ScoreRemainder = 0.0;

	/** Time since the last near miss */
	float TimeSinceNearMiss = 0.0f;

	/** True while a run is in progress */
	bool bRunActive = true;

	/** Seconds until the next run starts while the run over screen shows */
	float RestartCountdown = 0.0f;

	/** True if the last run set a new best score */
	bool bNewBest = false;

public:

	/** Broadcast on every near miss */
	UPROPERTY(BlueprintAssignable, Category="Endless")
	FEndlessNearMissDelegate OnNearMiss;

	/** Broadcast on every crash with traffic */
	UPROPERTY(BlueprintAssignable, Category="Endless")
	FEndlessCrashDelegate OnCrash;

public:

	AEndlessGameMode();

	virtual void StartPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	/** Spawns the player on the road instead of at a PlayerStart */
	virtual void RestartPlayer(AController* NewPlayer) override;

	/** Adds collected coins */
	void AddCoins(int32 Amount);

	/** Called by the traffic manager when the player closely passes a car */
	void RegisterNearMiss(bool bOncoming, double LateralGap);

	/** Called when the player hits a traffic car */
	void RegisterCrash(float ImpactSpeedKmh);

	/** Called when the player falls off the road */
	void HandleFellOff();

	/** Places the player's car back on the road at its current distance */
	void RespawnPlayerOnRoad(double ExtraDistance = 0.0);

	/** Shows a HUD message */
	void AddPopup(const FString& Text, const FLinearColor& Color, float Duration = 1.5f);

	UFUNCTION(BlueprintPure, Category="Endless")
	const FEndlessRunStats& GetRunStats() const { return Stats; }

	UFUNCTION(BlueprintPure, Category="Endless")
	bool IsRunActive() const { return bRunActive; }

	UFUNCTION(BlueprintPure, Category="Endless")
	float GetRestartCountdown() const { return RestartCountdown; }

	UFUNCTION(BlueprintPure, Category="Endless")
	bool IsNewBest() const { return bNewBest; }

	const TArray<FEndlessPopup>& GetPopups() const { return Popups; }
	const UEndlessSaveGame* GetSaveData() const { return SaveData; }
	AEndlessRoadStreamer* GetStreamer() const { return Streamer; }

protected:

	/** Spawns the road, traffic and environment once */
	void EnsureWorldSpawned();

	/** Ends the current run and schedules a new one */
	void EndRun();

	/** Starts a new run from the player's current position */
	void StartRun();

	/** Loads or creates the save data */
	void LoadProgress();

	/** Writes the save data */
	void SaveProgress();
};
