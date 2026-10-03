// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AstheticDrivePlayerController.h"
#include "EndlessPlayerController.generated.h"

/**
 *  Player controller for the endless mode.
 *  Reuses the template vehicle controller (input mappings, touch controls, speedometer),
 *  configured in C++ so no Blueprint is needed, and adds the driving feel:
 *  speed FOV kick, motion blur, haptics, optional tilt steering and falling-off recovery.
 */
UCLASS(Config="Game")
class AEndlessPlayerController : public AAstheticDrivePlayerController
{
	GENERATED_BODY()

protected:

	/** Chase camera FOV when standing still */
	UPROPERTY(EditAnywhere, Category="Endless|Camera")
	float BaseFOV = 90.0f;

	/** Chase camera FOV at TopFOVSpeedKmh */
	UPROPERTY(EditAnywhere, Category="Endless|Camera")
	float MaxFOV = 108.0f;

	/** Speed at which the FOV reaches MaxFOV */
	UPROPERTY(EditAnywhere, Category="Endless|Camera")
	float TopFOVSpeedKmh = 240.0f;

	/** How fast the FOV follows the speed */
	UPROPERTY(EditAnywhere, Category="Endless|Camera")
	float FOVInterpSpeed = 3.0f;

	/** Camera motion blur amount */
	UPROPERTY(EditAnywhere, Category="Endless|Camera")
	float MotionBlurAmount = 0.6f;

	/** Steer by tilting the device. Experimental, off by default */
	UPROPERTY(EditAnywhere, Config, Category="Endless|Tilt")
	bool bUseTiltSteering = false;

	/** Tilt steering sensitivity */
	UPROPERTY(EditAnywhere, Config, Category="Endless|Tilt")
	float TiltSensitivity = 2.0f;

	/** Tilt below this (after sensitivity) is ignored */
	UPROPERTY(EditAnywhere, Config, Category="Endless|Tilt")
	float TiltDeadZone = 0.05f;

	/** Flip the tilt direction */
	UPROPERTY(EditAnywhere, Config, Category="Endless|Tilt")
	bool bInvertTilt = false;

	/** Car below the sea by this much counts as fallen off */
	UPROPERTY(EditAnywhere, Category="Endless|Recovery", meta=(Units="cm"))
	float FallDepth = 300.0f;

	/** Seconds between two crash reports from continuous contact */
	float CrashCooldown = 0.0f;

public:

	AEndlessPlayerController();

	virtual void Tick(float DeltaSeconds) override;

protected:

	virtual void BeginPlay() override;

	virtual void OnPossess(APawn* InPawn) override;

	/** Reports crashes into traffic */
	UFUNCTION()
	void OnVehicleHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	/** Haptics on near miss */
	UFUNCTION()
	void OnNearMiss(int32 Combo);

	/** Haptics on crash */
	UFUNCTION()
	void OnCrash(bool bRunOver);

	/** Plays a short vibration on gamepads and phones */
	void PlayHaptics(float Intensity, float Duration);
};
