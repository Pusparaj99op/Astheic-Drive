// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/RandomStream.h"
#include "EndlessTrafficManager.generated.h"

class AEndlessRoadStreamer;
class AEndlessTrafficCar;

/**
 *  Keeps a pool of kinematic traffic cars driving around the player on the endless road,
 *  and detects near misses when the player passes a car closely at speed.
 */
UCLASS()
class AEndlessTrafficManager : public AActor
{
	GENERATED_BODY()

protected:

	/** Number of traffic cars kept around the player */
	UPROPERTY(EditAnywhere, Category="Traffic", meta=(ClampMin=0))
	int32 NumCars = 14;

	/** Closest distance ahead of the player where new cars appear */
	UPROPERTY(EditAnywhere, Category="Traffic", meta=(Units="cm"))
	float SpawnAheadMin = 25000.0f;

	/** Farthest distance ahead of the player where new cars appear */
	UPROPERTY(EditAnywhere, Category="Traffic", meta=(Units="cm"))
	float SpawnAheadMax = 60000.0f;

	/** Cars further behind the player than this are respawned ahead */
	UPROPERTY(EditAnywhere, Category="Traffic", meta=(Units="cm"))
	float DespawnBehind = 12000.0f;

	/** Cars further ahead than this are respawned closer */
	UPROPERTY(EditAnywhere, Category="Traffic", meta=(Units="cm"))
	float DespawnAhead = 80000.0f;

	/** Chance for a new car to be oncoming traffic */
	UPROPERTY(EditAnywhere, Category="Traffic", meta=(ClampMin=0, ClampMax=1))
	float OncomingChance = 0.4f;

	/** Speed range of traffic driving with the player, km/h */
	UPROPERTY(EditAnywhere, Category="Traffic")
	FVector2D SameDirectionSpeedKmh = FVector2D(60.0, 95.0);

	/** Speed range of oncoming traffic, km/h */
	UPROPERTY(EditAnywhere, Category="Traffic")
	FVector2D OncomingSpeedKmh = FVector2D(70.0, 100.0);

	/** Minimum gap kept between cars in the same lane */
	UPROPERTY(EditAnywhere, Category="Traffic", meta=(Units="cm"))
	float MinLaneGap = 2500.0f;

	/** Max center-to-center lateral distance that still counts as a near miss */
	UPROPERTY(EditAnywhere, Category="Near Miss", meta=(Units="cm"))
	float NearMissLateral = 340.0f;

	/** Minimum player speed for a near miss, km/h */
	UPROPERTY(EditAnywhere, Category="Near Miss")
	float NearMissMinSpeedKmh = 60.0f;

	/** Paint colors picked at random for traffic */
	UPROPERTY(EditAnywhere, Category="Traffic")
	TArray<FLinearColor> PaintColors;

	/** Pooled cars */
	UPROPERTY(Transient)
	TArray<TObjectPtr<AEndlessTrafficCar>> Cars;

	/** Road to drive on */
	UPROPERTY(Transient)
	TObjectPtr<AEndlessRoadStreamer> Streamer;

	/** Random stream for spawning */
	FRandomStream Random;

public:

	AEndlessTrafficManager();

	/** Spawns the cars on the given road */
	void Initialize(AEndlessRoadStreamer* InStreamer);

	/** Moves any car within Radius of the given road distance far ahead, e.g. after respawning the player */
	void ClearAround(double Distance, double Radius);

protected:

	virtual void Tick(float DeltaSeconds) override;

	/** Places a car at a new spot ahead of the player */
	void RespawnCar(AEndlessTrafficCar* Car, double PlayerDistance, double MinAhead, double MaxAhead);

	/** Returns true if a lane spot is free of other cars */
	bool IsSpotFree(const AEndlessTrafficCar* Ignore, double Distance, double Lateral) const;

	/** Moves a car to its current road distance */
	void PlaceCar(AEndlessTrafficCar* Car, bool bTeleport);
};
