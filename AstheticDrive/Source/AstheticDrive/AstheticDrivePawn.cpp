// Copyright Epic Games, Inc. All Rights Reserved.

#include "AstheticDrivePawn.h"
#include "AstheticDriveWheelFront.h"
#include "AstheticDriveWheelRear.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "ChaosWheeledVehicleMovementComponent.h"
#include "AstheticDrive.h"
#include "TimerManager.h"

#define LOCTEXT_NAMESPACE "VehiclePawn"

AAstheticDrivePawn::AAstheticDrivePawn()
{
	// construct the front camera boom
	FrontSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Front Spring Arm"));
	FrontSpringArm->SetupAttachment(GetMesh());
	FrontSpringArm->TargetArmLength = 0.0f;
	FrontSpringArm->bDoCollisionTest = false;
	FrontSpringArm->bEnableCameraRotationLag = true;
	FrontSpringArm->CameraRotationLagSpeed = 15.0f;
	FrontSpringArm->SetRelativeLocation(FVector(30.0f, 0.0f, 120.0f));

	FrontCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Front Camera"));
	FrontCamera->SetupAttachment(FrontSpringArm);
	FrontCamera->bAutoActivate = false;

	// construct the back camera boom
	BackSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Back Spring Arm"));
	BackSpringArm->SetupAttachment(GetMesh());
	BackSpringArm->TargetArmLength = 650.0f;
	BackSpringArm->SocketOffset.Z = 150.0f;
	BackSpringArm->bDoCollisionTest = false;
	BackSpringArm->bInheritPitch = false;
	BackSpringArm->bInheritRoll = false;
	BackSpringArm->bEnableCameraRotationLag = true;
	BackSpringArm->CameraRotationLagSpeed = 2.0f;
	BackSpringArm->CameraLagMaxDistance = 50.0f;

	BackCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Back Camera"));
	BackCamera->SetupAttachment(BackSpringArm);

	// Configure the car mesh
	GetMesh()->SetSimulatePhysics(true);
	GetMesh()->SetCollisionProfileName(FName("Vehicle"));

	// get the Chaos Wheeled movement component
	ChaosVehicleMovement = CastChecked<UChaosWheeledVehicleMovementComponent>(GetVehicleMovement());

}

void AAstheticDrivePawn::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// steering 
		EnhancedInputComponent->BindAction(SteeringAction, ETriggerEvent::Triggered, this, &AAstheticDrivePawn::Steering);
		EnhancedInputComponent->BindAction(SteeringAction, ETriggerEvent::Completed, this, &AAstheticDrivePawn::Steering);

		// throttle 
		EnhancedInputComponent->BindAction(ThrottleAction, ETriggerEvent::Triggered, this, &AAstheticDrivePawn::Throttle);
		EnhancedInputComponent->BindAction(ThrottleAction, ETriggerEvent::Completed, this, &AAstheticDrivePawn::Throttle);

		// break 
		EnhancedInputComponent->BindAction(BrakeAction, ETriggerEvent::Triggered, this, &AAstheticDrivePawn::Brake);
		EnhancedInputComponent->BindAction(BrakeAction, ETriggerEvent::Started, this, &AAstheticDrivePawn::StartBrake);
		EnhancedInputComponent->BindAction(BrakeAction, ETriggerEvent::Completed, this, &AAstheticDrivePawn::StopBrake);

		// handbrake 
		EnhancedInputComponent->BindAction(HandbrakeAction, ETriggerEvent::Started, this, &AAstheticDrivePawn::StartHandbrake);
		EnhancedInputComponent->BindAction(HandbrakeAction, ETriggerEvent::Completed, this, &AAstheticDrivePawn::StopHandbrake);

		// look around 
		EnhancedInputComponent->BindAction(LookAroundAction, ETriggerEvent::Triggered, this, &AAstheticDrivePawn::LookAround);

		// toggle camera 
		EnhancedInputComponent->BindAction(ToggleCameraAction, ETriggerEvent::Triggered, this, &AAstheticDrivePawn::ToggleCamera);

		// reset the vehicle 
		EnhancedInputComponent->BindAction(ResetVehicleAction, ETriggerEvent::Triggered, this, &AAstheticDrivePawn::ResetVehicle);
	}
	else
	{
		UE_LOG(LogAstheticDrive, Error, TEXT("'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

void AAstheticDrivePawn::BeginPlay()
{
	Super::BeginPlay();

	// set up the flipped check timer
	GetWorld()->GetTimerManager().SetTimer(FlipCheckTimer, this, &AAstheticDrivePawn::FlippedCheck, FlipCheckTime, true);
}

void AAstheticDrivePawn::EndPlay(EEndPlayReason::Type EndPlayReason)
{
	// clear the flipped check timer
	GetWorld()->GetTimerManager().ClearTimer(FlipCheckTimer);

	Super::EndPlay(EndPlayReason);
}

void AAstheticDrivePawn::Tick(float Delta)
{
	Super::Tick(Delta);

	// add some angular damping if the vehicle is in midair
	bool bMovingOnGround = ChaosVehicleMovement->IsMovingOnGround();
	GetMesh()->SetAngularDamping(bMovingOnGround ? 0.0f : 3.0f);

	// realign the camera yaw to face front
	float CameraYaw = BackSpringArm->GetRelativeRotation().Yaw;
	CameraYaw = FMath::FInterpTo(CameraYaw, 0.0f, Delta, 1.0f);

	BackSpringArm->SetRelativeRotation(FRotator(0.0f, CameraYaw, 0.0f));
}

void AAstheticDrivePawn::Steering(const FInputActionValue& Value)
{
	// route the input
	DoSteering(Value.Get<float>());
}

void AAstheticDrivePawn::Throttle(const FInputActionValue& Value)
{
	// route the input
	DoThrottle(Value.Get<float>());
}

void AAstheticDrivePawn::Brake(const FInputActionValue& Value)
{
	// route the input
	DoBrake(Value.Get<float>());
}

void AAstheticDrivePawn::StartBrake(const FInputActionValue& Value)
{
	// route the input
	DoBrakeStart();
}

void AAstheticDrivePawn::StopBrake(const FInputActionValue& Value)
{
	// route the input
	DoBrakeStop();
}

void AAstheticDrivePawn::StartHandbrake(const FInputActionValue& Value)
{
	// route the input
	DoHandbrakeStart();
}

void AAstheticDrivePawn::StopHandbrake(const FInputActionValue& Value)
{
	// route the input
	DoHandbrakeStop();
}

void AAstheticDrivePawn::LookAround(const FInputActionValue& Value)
{
	// route the input
	DoLookAround(Value.Get<float>());
}

void AAstheticDrivePawn::ToggleCamera(const FInputActionValue& Value)
{
	// route the input
	DoToggleCamera();
}

void AAstheticDrivePawn::ResetVehicle(const FInputActionValue& Value)
{
	// route the input
	DoResetVehicle();
}

void AAstheticDrivePawn::DoSteering(float SteeringValue)
{
	// add the input
	ChaosVehicleMovement->SetSteeringInput(SteeringValue);
}

void AAstheticDrivePawn::DoThrottle(float ThrottleValue)
{
	// add the input
	ChaosVehicleMovement->SetThrottleInput(ThrottleValue);

	// reset the brake input
	ChaosVehicleMovement->SetBrakeInput(0.0f);
}

void AAstheticDrivePawn::DoBrake(float BrakeValue)
{
	// add the input
	ChaosVehicleMovement->SetBrakeInput(BrakeValue);

	// reset the throttle input
	ChaosVehicleMovement->SetThrottleInput(0.0f);
}

void AAstheticDrivePawn::DoBrakeStart()
{
	// call the Blueprint hook for the brake lights
	BrakeLights(true);
}

void AAstheticDrivePawn::DoBrakeStop()
{
	// call the Blueprint hook for the brake lights
	BrakeLights(false);

	// reset brake input to zero
	ChaosVehicleMovement->SetBrakeInput(0.0f);
}

void AAstheticDrivePawn::DoHandbrakeStart()
{
	// add the input
	ChaosVehicleMovement->SetHandbrakeInput(true);

	// call the Blueprint hook for the break lights
	BrakeLights(true);
}

void AAstheticDrivePawn::DoHandbrakeStop()
{
	// add the input
	ChaosVehicleMovement->SetHandbrakeInput(false);

	// call the Blueprint hook for the break lights
	BrakeLights(false);
}

void AAstheticDrivePawn::DoLookAround(float YawDelta)
{
	// rotate the spring arm
	BackSpringArm->AddLocalRotation(FRotator(0.0f, YawDelta, 0.0f));
}

void AAstheticDrivePawn::DoToggleCamera()
{
	// toggle the active camera flag
	bFrontCameraActive = !bFrontCameraActive;

	FrontCamera->SetActive(bFrontCameraActive);
	BackCamera->SetActive(!bFrontCameraActive);
}

void AAstheticDrivePawn::DoResetVehicle()
{
	// reset to a location slightly above our current one
	FVector ResetLocation = GetActorLocation() + FVector(0.0f, 0.0f, 50.0f);

	// reset to our yaw. Ignore pitch and roll
	FRotator ResetRotation = GetActorRotation();
	ResetRotation.Pitch = 0.0f;
	ResetRotation.Roll = 0.0f;

	// teleport the actor to the reset spot and reset physics
	SetActorTransform(FTransform(ResetRotation, ResetLocation, FVector::OneVector), false, nullptr, ETeleportType::TeleportPhysics);

	GetMesh()->SetPhysicsAngularVelocityInDegrees(FVector::ZeroVector);
	GetMesh()->SetPhysicsLinearVelocity(FVector::ZeroVector);
}

void AAstheticDrivePawn::FlippedCheck()
{
	// check the difference in angle between the mesh's up vector and world up
	const float UpDot = FVector::DotProduct(FVector::UpVector, GetMesh()->GetUpVector());

	if (UpDot < FlipCheckMinDot)
	{
		// is this the second time we've checked that the vehicle is still flipped?
		if (bPreviousFlipCheck)
		{
			// reset the vehicle to upright
			DoResetVehicle();
		}
		
		// set the flipped check flag so the next check resets the car
		bPreviousFlipCheck = true;

	} else {

		// we're upright. reset the flipped check flag
		bPreviousFlipCheck = false;
	}
}

#undef LOCTEXT_NAMESPACE