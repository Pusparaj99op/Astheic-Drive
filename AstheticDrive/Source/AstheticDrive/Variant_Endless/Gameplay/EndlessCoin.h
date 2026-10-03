// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EndlessCoin.generated.h"

class USphereComponent;
class UStaticMeshComponent;
class UMaterialInterface;

/**
 *  A spinning collectible coin placed on the endless road.
 *  Pooled by the road streamer, collected by driving through it.
 */
UCLASS()
class AEndlessCoin : public AActor
{
	GENERATED_BODY()

	/** Pickup volume */
	UPROPERTY(VisibleAnywhere, Category="Components", meta=(AllowPrivateAccess="true"))
	TObjectPtr<USphereComponent> PickupSphere;

	/** Visual mesh */
	UPROPERTY(VisibleAnywhere, Category="Components", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UStaticMeshComponent> CoinMesh;

protected:

	/** Spin speed in degrees per second */
	UPROPERTY(EditAnywhere, Category="Coin")
	float SpinSpeed = 180.0f;

	/** Coins awarded on pickup */
	UPROPERTY(EditAnywhere, Category="Coin")
	int32 Value = 1;

	/** True while placed on the road and collectible */
	bool bActive = false;

public:

	AEndlessCoin();

	/** Places the coin and makes it collectible */
	void Activate(const FVector& Location, UMaterialInterface* Material);

	/** Hides the coin and returns it to the pool */
	void Deactivate();

	/** Returns true if the coin is placed and not collected */
	bool IsActive() const { return bActive; }

protected:

	virtual void Tick(float DeltaSeconds) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
};
