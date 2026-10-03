// Copyright Epic Games, Inc. All Rights Reserved.

#include "EndlessCoin.h"
#include "EndlessGameMode.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "Engine/CollisionProfile.h"
#include "Engine/World.h"
#include "GameFramework/Pawn.h"
#include "UObject/ConstructorHelpers.h"

AEndlessCoin::AEndlessCoin()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = false;

	PickupSphere = CreateDefaultSubobject<USphereComponent>(TEXT("PickupSphere"));
	SetRootComponent(PickupSphere);
	PickupSphere->SetSphereRadius(160.0f);
	PickupSphere->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	PickupSphere->SetCollisionObjectType(ECC_WorldDynamic);
	PickupSphere->SetCollisionResponseToAllChannels(ECR_Ignore);
	PickupSphere->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	PickupSphere->SetCollisionResponseToChannel(ECC_Vehicle, ECR_Overlap);
	PickupSphere->SetCollisionResponseToChannel(ECC_PhysicsBody, ECR_Overlap);
	PickupSphere->SetGenerateOverlapEvents(true);

	CoinMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CoinMesh"));
	CoinMesh->SetupAttachment(PickupSphere);
	CoinMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	CoinMesh->SetGenerateOverlapEvents(false);

	// a flat cylinder standing on its edge
	CoinMesh->SetRelativeRotation(FRotator(0.0f, 0.0f, 90.0f));
	CoinMesh->SetRelativeScale3D(FVector(0.9f, 0.9f, 0.12f));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CylinderMesh(TEXT("/Engine/BasicShapes/Cylinder.Cylinder"));
	if (CylinderMesh.Succeeded())
	{
		CoinMesh->SetStaticMesh(CylinderMesh.Object);
	}

	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
}

void AEndlessCoin::Activate(const FVector& Location, UMaterialInterface* Material)
{
	bActive = true;

	if (Material)
	{
		CoinMesh->SetMaterial(0, Material);
	}

	SetActorLocation(Location, false, nullptr, ETeleportType::TeleportPhysics);
	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);
	SetActorTickEnabled(true);
}

void AEndlessCoin::Deactivate()
{
	bActive = false;

	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
	SetActorTickEnabled(false);
}

void AEndlessCoin::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	AddActorWorldRotation(FRotator(0.0f, SpinSpeed * DeltaSeconds, 0.0f));
}

void AEndlessCoin::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	if (!bActive)
	{
		return;
	}

	// only the player's car collects coins
	const APawn* Pawn = Cast<APawn>(OtherActor);
	if (!Pawn || !Pawn->IsPlayerControlled())
	{
		return;
	}

	if (AEndlessGameMode* GameMode = GetWorld()->GetAuthGameMode<AEndlessGameMode>())
	{
		GameMode->AddCoins(Value);
	}

	// stay hidden until the streamer recycles us
	bActive = false;
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
	SetActorTickEnabled(false);
}
