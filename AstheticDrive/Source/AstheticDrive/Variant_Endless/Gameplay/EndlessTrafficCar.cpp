// Copyright Epic Games, Inc. All Rights Reserved.

#include "EndlessTrafficCar.h"
#include "Components/BoxComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/SkeletalMesh.h"
#include "Engine/StaticMesh.h"
#include "Engine/CollisionProfile.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "UObject/ConstructorHelpers.h"

AEndlessTrafficCar::AEndlessTrafficCar()
{
	PrimaryActorTick.bCanEverTick = false;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	SetRootComponent(CollisionBox);
	CollisionBox->SetBoxExtent(FVector(230.0f, 100.0f, HalfHeight));
	CollisionBox->SetMobility(EComponentMobility::Movable);
	CollisionBox->SetSimulatePhysics(false);
	CollisionBox->SetCollisionProfileName(UCollisionProfile::BlockAllDynamic_ProfileName);
	CollisionBox->SetGenerateOverlapEvents(false);
	CollisionBox->SetCanEverAffectNavigation(false);

	Skeleton = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Skeleton"));
	Skeleton->SetupAttachment(CollisionBox);
	Skeleton->SetRelativeLocation(FVector(0.0f, 0.0f, -HalfHeight));
	Skeleton->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Skeleton->SetGenerateOverlapEvents(false);
	Skeleton->bEnableUpdateRateOptimizations = true;
	Skeleton->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::OnlyTickPoseWhenRendered;

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SkeletonMesh(TEXT("/Game/Vehicles/SportsCar/SKM_SportsCar.SKM_SportsCar"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> BodyMesh(TEXT("/Game/Vehicles/SportsCar/SM_SportsCar.SM_SportsCar"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> GlassMesh(TEXT("/Game/Vehicles/SportsCar/SM_SportsCar_Glass.SM_SportsCar_Glass"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> WheelMesh(TEXT("/Game/Vehicles/SportsCar/SM_SportsCar_Wheel.SM_SportsCar_Wheel"));

	if (SkeletonMesh.Succeeded())
	{
		Skeleton->SetSkeletalMeshAsset(SkeletonMesh.Object);
	}

	auto SetupVisual = [](UStaticMeshComponent* Component, USceneComponent* Parent, FName Socket, UStaticMesh* Mesh)
	{
		Component->SetupAttachment(Parent, Socket);
		Component->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		Component->SetGenerateOverlapEvents(false);
		Component->SetCanEverAffectNavigation(false);
		Component->SetStaticMesh(Mesh);
	};

	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	SetupVisual(Body, Skeleton, NAME_None, BodyMesh.Object);

	Glass = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Glass"));
	SetupVisual(Glass, Skeleton, NAME_None, GlassMesh.Object);

	// wheels sit on the physics wheel bones, rotated like in BP_SportsCar_Pawn
	const FName WheelBones[4] = { FName("Phys_Wheel_FL"), FName("Phys_Wheel_FR"), FName("Phys_Wheel_BL"), FName("Phys_Wheel_BR") };
	const float WheelYaw[4] = { -90.0f, 90.0f, -90.0f, 90.0f };

	for (int32 i = 0; i < 4; ++i)
	{
		UStaticMeshComponent* Wheel = CreateDefaultSubobject<UStaticMeshComponent>(*FString::Printf(TEXT("Wheel%d"), i));
		SetupVisual(Wheel, Skeleton, WheelBones[i], WheelMesh.Object);
		Wheel->SetRelativeRotation(FRotator(0.0f, WheelYaw[i], 0.0f));
		Wheels.Add(Wheel);
	}
}

void AEndlessTrafficCar::SetPaint(const FLinearColor& Color)
{
	// tint every body material slot. Slots without the parameter ignore it
	for (int32 Index = 0; Index < Body->GetNumMaterials(); ++Index)
	{
		if (UMaterialInstanceDynamic* Material = Body->CreateDynamicMaterialInstance(Index))
		{
			Material->SetVectorParameterValue(TEXT("Paint Tint"), Color);
		}
	}
}
