// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EndlessEnvironment.generated.h"

class UDirectionalLightComponent;
class USkyAtmosphereComponent;
class USkyLightComponent;
class UExponentialHeightFogComponent;
class UPostProcessComponent;

/**
 *  Self contained dusk lighting rig for the endless mode:
 *  a low warm sun, sky atmosphere, real time sky light, height fog and a global post process.
 *  Spawned by the game mode when the level has no lighting of its own.
 *  All values are exposed so they can be tuned in the details panel during Play.
 */
UCLASS()
class AEndlessEnvironment : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, Category="Components", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UDirectionalLightComponent> Sun;

	UPROPERTY(VisibleAnywhere, Category="Components", meta=(AllowPrivateAccess="true"))
	TObjectPtr<USkyAtmosphereComponent> SkyAtmosphere;

	UPROPERTY(VisibleAnywhere, Category="Components", meta=(AllowPrivateAccess="true"))
	TObjectPtr<USkyLightComponent> SkyLight;

	UPROPERTY(VisibleAnywhere, Category="Components", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UExponentialHeightFogComponent> HeightFog;

	UPROPERTY(VisibleAnywhere, Category="Components", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UPostProcessComponent> PostProcess;

protected:

	/** Sun elevation above the horizon in degrees. Small values give the dusk look */
	UPROPERTY(EditAnywhere, Category="Dusk")
	float SunElevation = 6.0f;

	/** Sun compass direction in degrees. 0 puts the sun ahead of the road start */
	UPROPERTY(EditAnywhere, Category="Dusk")
	float SunAzimuth = 0.0f;

	/** Sun illuminance in lux */
	UPROPERTY(EditAnywhere, Category="Dusk")
	float SunIntensity = 10.0f;

	/** Sun color */
	UPROPERTY(EditAnywhere, Category="Dusk")
	FLinearColor SunColor = FLinearColor(1.0f, 0.62f, 0.38f);

	/** Sky light intensity */
	UPROPERTY(EditAnywhere, Category="Dusk")
	float SkyLightIntensity = 1.0f;

	/** Fog density */
	UPROPERTY(EditAnywhere, Category="Dusk")
	float FogDensity = 0.015f;

	/** Manual exposure compensation (EV) */
	UPROPERTY(EditAnywhere, Category="Post Process")
	float ExposureBias = 0.0f;

	/** Bloom intensity */
	UPROPERTY(EditAnywhere, Category="Post Process")
	float BloomIntensity = 0.8f;

	/** Global motion blur amount */
	UPROPERTY(EditAnywhere, Category="Post Process")
	float MotionBlurAmount = 0.5f;

	/** Vignette intensity */
	UPROPERTY(EditAnywhere, Category="Post Process")
	float VignetteIntensity = 0.45f;

	/** Warm color grade */
	UPROPERTY(EditAnywhere, Category="Post Process")
	FLinearColor SceneTint = FLinearColor(1.0f, 0.93f, 0.86f);

public:

	AEndlessEnvironment();

	virtual void OnConstruction(const FTransform& Transform) override;

	virtual void BeginPlay() override;

protected:

	/** Pushes the tunables into the components */
	void ApplySettings();
};
