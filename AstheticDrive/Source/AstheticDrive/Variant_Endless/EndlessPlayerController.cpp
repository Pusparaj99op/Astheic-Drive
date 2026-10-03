// Copyright Epic Games, Inc. All Rights Reserved.

#include "EndlessPlayerController.h"
#include "EndlessGameMode.h"
#include "EndlessRoadStreamer.h"
#include "EndlessTrafficCar.h"
#include "AstheticDrivePawn.h"
#include "AstheticDriveUI.h"
#include "Blueprint/UserWidget.h"
#include "Camera/CameraComponent.h"
#include "ChaosWheeledVehicleMovementComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/World.h"
#include "InputMappingContext.h"
#include "UObject/ConstructorHelpers.h"

AEndlessPlayerController::AEndlessPlayerController()
{
	PrimaryActorTick.bCanEverTick = true;

	// same setup as BP_VehicleAdvPlayerController
	static ConstructorHelpers::FObjectFinder<UInputMappingContext> DefaultContext(TEXT("/Game/VehicleTemplate/Input/IMC_Vehicle_Default.IMC_Vehicle_Default"));
	static ConstructorHelpers::FObjectFinder<UInputMappingContext> MouseLookContext(TEXT("/Game/VehicleTemplate/Input/IMC_Vehicle_MouseLook.IMC_Vehicle_MouseLook"));
	static ConstructorHelpers::FClassFinder<UUserWidget> TouchControls(TEXT("/Game/VehicleTemplate/Input/UI_Touch_Vehicle"));
	static ConstructorHelpers::FClassFinder<UAstheticDriveUI> Speedometer(TEXT("/Game/VehicleTemplate/Blueprints/UI/BP_VehicleAdvUI"));
	static ConstructorHelpers::FClassFinder<AAstheticDrivePawn> SportsCar(TEXT("/Game/VehicleTemplate/Blueprints/SportsCar/BP_SportsCar_Pawn"));

	if (DefaultContext.Succeeded())
	{
		DefaultMappingContexts.Add(DefaultContext.Object);
	}

	if (MouseLookContext.Succeeded())
	{
		MobileExcludedMappingContexts.Add(MouseLookContext.Object);
	}

	MobileControlsWidgetClass = TouchControls.Class;
	VehicleUIClass = Speedometer.Class;
	VehiclePawnClass = SportsCar.Class;
}

void AEndlessPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (AEndlessGameMode* GameMode = GetWorld()->GetAuthGameMode<AEndlessGameMode>())
	{
		GameMode->OnNearMiss.AddUniqueDynamic(this, &AEndlessPlayerController::OnNearMiss);
		GameMode->OnCrash.AddUniqueDynamic(this, &AEndlessPlayerController::OnCrash);
	}
}

void AEndlessPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if (!VehiclePawn)
	{
		return;
	}

	// hit events for crash detection, overlaps for coins
	USkeletalMeshComponent* CarMesh = VehiclePawn->GetMesh();
	CarMesh->SetNotifyRigidBodyCollision(true);
	CarMesh->SetGenerateOverlapEvents(true);
	CarMesh->OnComponentHit.AddUniqueDynamic(this, &AEndlessPlayerController::OnVehicleHit);

	// speed feel on the chase camera
	if (UCameraComponent* Camera = VehiclePawn->GetBackCamera())
	{
		Camera->PostProcessSettings.bOverride_MotionBlurAmount = true;
		Camera->PostProcessSettings.MotionBlurAmount = MotionBlurAmount;
		Camera->PostProcessSettings.bOverride_MotionBlurMax = true;
		Camera->PostProcessSettings.MotionBlurMax = 6.0f;
		Camera->PostProcessBlendWeight = 1.0f;
		Camera->SetFieldOfView(BaseFOV);
	}
}

void AEndlessPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	CrashCooldown = FMath::Max(0.0f, CrashCooldown - DeltaSeconds);

	if (!IsValid(VehiclePawn))
	{
		return;
	}

	const float SpeedKmh = FMath::Abs(VehiclePawn->GetChaosVehicleMovement()->GetForwardSpeed()) * 0.036f;

	// FOV kick with speed
	if (UCameraComponent* Camera = VehiclePawn->GetBackCamera())
	{
		const float Alpha = FMath::Clamp(SpeedKmh / TopFOVSpeedKmh, 0.0f, 1.0f);
		const float TargetFOV = FMath::Lerp(BaseFOV, MaxFOV, Alpha * Alpha);
		Camera->SetFieldOfView(FMath::FInterpTo(Camera->FieldOfView, TargetFOV, DeltaSeconds, FOVInterpSpeed));
	}

	// tilt steering
	if (bUseTiltSteering)
	{
		FVector Tilt, RotationRate, Gravity, Acceleration;
		GetInputMotionState(Tilt, RotationRate, Gravity, Acceleration);

		float Steering = FMath::Clamp(float(Tilt.Y) * TiltSensitivity, -1.0f, 1.0f);
		if (FMath::Abs(Steering) < TiltDeadZone)
		{
			Steering = 0.0f;
		}

		VehiclePawn->DoSteering(bInvertTilt ? -Steering : Steering);
	}

	// fell into the sea? put the car back on the road
	if (AEndlessGameMode* GameMode = GetWorld()->GetAuthGameMode<AEndlessGameMode>())
	{
		const AEndlessRoadStreamer* Streamer = GameMode->GetStreamer();
		const double SeaLevel = Streamer ? Streamer->GetSeaLevel() : 0.0;

		if (VehiclePawn->GetActorLocation().Z < SeaLevel - FallDepth)
		{
			GameMode->HandleFellOff();
		}
	}
}

void AEndlessPlayerController::OnVehicleHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	AEndlessTrafficCar* Car = Cast<AEndlessTrafficCar>(OtherActor);

	if (!Car || CrashCooldown > 0.0f || !IsValid(VehiclePawn))
	{
		return;
	}

	CrashCooldown = 0.75f;
	Car->bHitByPlayer = true;

	const float ImpactKmh = float((VehiclePawn->GetVelocity() - Car->GetTrafficVelocity()).Size() * 0.036);

	if (AEndlessGameMode* GameMode = GetWorld()->GetAuthGameMode<AEndlessGameMode>())
	{
		GameMode->RegisterCrash(ImpactKmh);
	}
}

void AEndlessPlayerController::OnNearMiss(int32 Combo)
{
	PlayHaptics(FMath::Min(0.25f + 0.08f * Combo, 0.7f), 0.12f);
}

void AEndlessPlayerController::OnCrash(bool bRunOver)
{
	PlayHaptics(bRunOver ? 1.0f : 0.5f, bRunOver ? 0.5f : 0.2f);
}

void AEndlessPlayerController::PlayHaptics(float Intensity, float Duration)
{
	PlayDynamicForceFeedback(Intensity, Duration, true, true, true, true, EDynamicForceFeedbackAction::Start);
}
