// Copyright Epic Games, Inc. All Rights Reserved.

#include "EndlessTrafficManager.h"
#include "EndlessTrafficCar.h"
#include "EndlessRoadStreamer.h"
#include "EndlessRoadChunk.h"
#include "EndlessGameMode.h"
#include "Engine/World.h"
#include "GameFramework/Pawn.h"
#include "Kismet/GameplayStatics.h"

namespace
{
	constexpr double KmhToCms = 100000.0 / 3600.0;
}

AEndlessTrafficManager::AEndlessTrafficManager()
{
	PrimaryActorTick.bCanEverTick = true;

	USceneComponent* Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	PaintColors = {
		FLinearColor(0.6f, 0.02f, 0.02f),
		FLinearColor(0.02f, 0.05f, 0.4f),
		FLinearColor(0.8f, 0.8f, 0.8f),
		FLinearColor(0.02f, 0.02f, 0.02f),
		FLinearColor(0.25f, 0.25f, 0.27f),
		FLinearColor(0.9f, 0.45f, 0.02f),
		FLinearColor(0.05f, 0.25f, 0.1f)
	};
}

void AEndlessTrafficManager::Initialize(AEndlessRoadStreamer* InStreamer)
{
	Streamer = InStreamer;
	Random.Initialize(FMath::Rand());

	FActorSpawnParameters Params;
	Params.Owner = this;
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	for (int32 i = 0; i < NumCars; ++i)
	{
		AEndlessTrafficCar* Car = GetWorld()->SpawnActor<AEndlessTrafficCar>(AEndlessTrafficCar::StaticClass(), FTransform::Identity, Params);

		if (!Car)
		{
			continue;
		}

		if (PaintColors.Num() > 0)
		{
			Car->SetPaint(PaintColors[Random.RandRange(0, PaintColors.Num() - 1)]);
		}

		Cars.Add(Car);

		// spread the first wave out so the road isn't empty at the start
		RespawnCar(Car, Streamer ? Streamer->GetPlayerDistance() : 0.0, 15000.0, SpawnAheadMax);
	}
}

void AEndlessTrafficManager::ClearAround(double Distance, double Radius)
{
	for (AEndlessTrafficCar* Car : Cars)
	{
		if (Car && FMath::Abs(Car->RoadDistance - Distance) < Radius)
		{
			RespawnCar(Car, Distance, SpawnAheadMin, SpawnAheadMax);
		}
	}
}

void AEndlessTrafficManager::RespawnCar(AEndlessTrafficCar* Car, double PlayerDistance, double MinAhead, double MaxAhead)
{
	using namespace EndlessRoadLayout;

	const bool bOncoming = Random.FRand() < OncomingChance;
	const FVector2D SpeedRange = bOncoming ? OncomingSpeedKmh : SameDirectionSpeedKmh;

	Car->Direction = bOncoming ? -1 : 1;
	Car->CruiseSpeed = Random.FRandRange(float(SpeedRange.X), float(SpeedRange.Y)) * KmhToCms;
	Car->CurrentSpeed = Car->CruiseSpeed;
	Car->bHitByPlayer = false;
	Car->bNearMissAwarded = false;

	// try a few spots, keep the last one even if crowded
	for (int32 Attempt = 0; Attempt < 6; ++Attempt)
	{
		const int32 Lane = bOncoming ? Random.RandRange(0, 1) : Random.RandRange(2, 3);
		Car->LateralOffset = LaneCenters[Lane];
		Car->RoadDistance = PlayerDistance + Random.FRandRange(float(MinAhead), float(MaxAhead));

		if (IsSpotFree(Car, Car->RoadDistance, Car->LateralOffset))
		{
			break;
		}
	}

	Car->PreviousRelative = PlayerDistance - Car->RoadDistance;
	PlaceCar(Car, true);
}

bool AEndlessTrafficManager::IsSpotFree(const AEndlessTrafficCar* Ignore, double Distance, double Lateral) const
{
	for (const AEndlessTrafficCar* Other : Cars)
	{
		if (Other && Other != Ignore && FMath::IsNearlyEqual(Other->LateralOffset, Lateral, 10.0) && FMath::Abs(Other->RoadDistance - Distance) < MinLaneGap * 2.0)
		{
			return false;
		}
	}

	return true;
}

void AEndlessTrafficManager::PlaceCar(AEndlessTrafficCar* Car, bool bTeleport)
{
	FTransform Transform = Streamer->GetTransformAtDistance(Car->RoadDistance, Car->LateralOffset, AEndlessTrafficCar::HalfHeight + 2.0);

	// oncoming cars face the other way
	if (Car->Direction < 0)
	{
		Transform.SetRotation(Transform.GetRotation() * FQuat(FVector::UpVector, UE_DOUBLE_PI));
	}

	Car->SetActorTransform(Transform, false, nullptr, bTeleport ? ETeleportType::TeleportPhysics : ETeleportType::None);
}

void AEndlessTrafficManager::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	const APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);

	if (!Streamer || !PlayerPawn)
	{
		return;
	}

	const double PlayerDistance = Streamer->GetPlayerDistance();
	const FVector PlayerLocation = PlayerPawn->GetActorLocation();
	const double PlayerSpeedKmh = PlayerPawn->GetVelocity().Size() / KmhToCms;

	AEndlessGameMode* GameMode = GetWorld()->GetAuthGameMode<AEndlessGameMode>();

	for (AEndlessTrafficCar* Car : Cars)
	{
		if (!Car)
		{
			continue;
		}

		// slow down behind a slower car in the same lane
		double TargetSpeed = Car->CruiseSpeed;
		for (const AEndlessTrafficCar* Other : Cars)
		{
			if (Other && Other != Car && Other->Direction == Car->Direction && FMath::IsNearlyEqual(Other->LateralOffset, Car->LateralOffset, 10.0))
			{
				const double Gap = (Other->RoadDistance - Car->RoadDistance) * Car->Direction;

				if (Gap > 0.0 && Gap < MinLaneGap)
				{
					TargetSpeed = FMath::Min(TargetSpeed, Other->CurrentSpeed * FMath::Clamp(Gap / MinLaneGap, 0.0, 1.0));
				}
			}
		}

		Car->CurrentSpeed = FMath::FInterpTo(Car->CurrentSpeed, TargetSpeed, double(DeltaSeconds), 2.0);
		Car->RoadDistance += Car->Direction * Car->CurrentSpeed * DeltaSeconds;

		// recycle cars that fell out of the window around the player
		const double Ahead = Car->RoadDistance - PlayerDistance;
		if (Ahead < -DespawnBehind || Ahead > DespawnAhead)
		{
			RespawnCar(Car, PlayerDistance, SpawnAheadMin, SpawnAheadMax);
			continue;
		}

		PlaceCar(Car, false);

		// near miss: the player just moved from behind the car to in front of it, close beside it
		const FEndlessRoadSample Sample = Streamer->SampleAtDistance(Car->RoadDistance);
		const FVector ToPlayer = PlayerLocation - Car->GetActorLocation();
		const double Relative = FVector::DotProduct(ToPlayer, Sample.Forward);

		if (Car->PreviousRelative < 0.0 && Relative >= 0.0 && !Car->bHitByPlayer && !Car->bNearMissAwarded)
		{
			const double Lateral = FMath::Abs(FVector::DotProduct(ToPlayer, Sample.Right));

			if (Lateral < NearMissLateral && PlayerSpeedKmh >= NearMissMinSpeedKmh && GameMode)
			{
				Car->bNearMissAwarded = true;
				GameMode->RegisterNearMiss(Car->Direction < 0, Lateral);
			}
		}

		Car->PreviousRelative = Relative;
	}
}
