// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EndlessTrafficCar.generated.h"

class UBoxComponent;
class USkeletalMeshComponent;
class UStaticMeshComponent;

/**
 *  A kinematic traffic car driven along the endless road by the traffic manager.
 *  Built from the template sports car meshes, attached to the wheel bones the same way as the player car.
 */
UCLASS()
class AEndlessTrafficCar : public AActor
{
	GENERATED_BODY()

	/** Collision volume, the kinematic body the player can crash into */
	UPROPERTY(VisibleAnywhere, Category="Components", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UBoxComponent> CollisionBox;

	/** Skeleton used only to place the wheels on their bones */
	UPROPERTY(VisibleAnywhere, Category="Components", meta=(AllowPrivateAccess="true"))
	TObjectPtr<USkeletalMeshComponent> Skeleton;

	/** Car body */
	UPROPERTY(VisibleAnywhere, Category="Components", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UStaticMeshComponent> Body;

	/** Car glass */
	UPROPERTY(VisibleAnywhere, Category="Components", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UStaticMeshComponent> Glass;

	/** Wheels: FL, FR, BL, BR */
	UPROPERTY(VisibleAnywhere, Category="Components", meta=(AllowPrivateAccess="true"))
	TArray<TObjectPtr<UStaticMeshComponent>> Wheels;

public:

	/** Distance along the road */
	double RoadDistance = 0.0;

	/** Lateral offset from the road center. Positive = right */
	double LateralOffset = 0.0;

	/** Cruise speed in cm/s */
	double CruiseSpeed = 2500.0;

	/** Current speed in cm/s, can drop below cruise when stuck behind another car */
	double CurrentSpeed = 2500.0;

	/** +1 drives with the player, -1 is oncoming traffic */
	int32 Direction = 1;

	/** Along-road offset of the player relative to this car, last frame */
	double PreviousRelative = 0.0;

	/** True if the player already hit this car since it spawned */
	bool bHitByPlayer = false;

	/** True once a near miss has been awarded for this car */
	bool bNearMissAwarded = false;

	/** Half height of the collision box, used to lift the car onto the road */
	static constexpr double HalfHeight = 70.0;

public:

	AEndlessTrafficCar();

	/** Sets a random paint color */
	void SetPaint(const FLinearColor& Color);

	/** Returns the car's world velocity */
	FVector GetTrafficVelocity() const { return GetActorForwardVector() * CurrentSpeed; }
};
