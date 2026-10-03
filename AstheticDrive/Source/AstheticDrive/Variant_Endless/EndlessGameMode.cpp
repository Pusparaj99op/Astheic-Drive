// Copyright Epic Games, Inc. All Rights Reserved.

#include "EndlessGameMode.h"
#include "EndlessPlayerController.h"
#include "EndlessHUD.h"
#include "EndlessEnvironment.h"
#include "EndlessRoadStreamer.h"
#include "EndlessRoadChunk.h"
#include "EndlessTrafficManager.h"
#include "EndlessSaveGame.h"
#include "EndlessBiomeData.h"
#include "AstheticDrive.h"
#include "Components/PrimitiveComponent.h"
#include "Engine/DirectionalLight.h"
#include "Engine/World.h"
#include "EngineUtils.h"
#include "GameFramework/Pawn.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

AEndlessGameMode::AEndlessGameMode()
{
	PrimaryActorTick.bCanEverTick = true;

	// the template sports car, configured in its Blueprint
	static ConstructorHelpers::FClassFinder<APawn> SportsCarClass(TEXT("/Game/VehicleTemplate/Blueprints/SportsCar/BP_SportsCar_Pawn"));
	if (SportsCarClass.Succeeded())
	{
		DefaultPawnClass = SportsCarClass.Class;
	}

	PlayerControllerClass = AEndlessPlayerController::StaticClass();
	HUDClass = AEndlessHUD::StaticClass();
}

void AEndlessGameMode::StartPlay()
{
	EnsureWorldSpawned();

	Super::StartPlay();
}

void AEndlessGameMode::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	SaveProgress();

	Super::EndPlay(EndPlayReason);
}

void AEndlessGameMode::EnsureWorldSpawned()
{
	if (Streamer)
	{
		return;
	}

	LoadProgress();

	UWorld* World = GetWorld();

	FActorSpawnParameters Params;
	Params.Owner = this;
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	// only bring our own lighting into levels that have none
	if (bSpawnEnvironment)
	{
		const bool bHasSun = static_cast<bool>(TActorIterator<ADirectionalLight>(World));

		if (!bHasSun)
		{
			World->SpawnActor<AEndlessEnvironment>(AEndlessEnvironment::StaticClass(), FTransform::Identity, Params);
		}
	}

	Streamer = World->SpawnActor<AEndlessRoadStreamer>(AEndlessRoadStreamer::StaticClass(), FTransform::Identity, Params);

	if (!Streamer)
	{
		UE_LOG(LogAstheticDrive, Error, TEXT("Endless: could not spawn the road streamer."));
		return;
	}

	Streamer->Configure(RoadSeed, Biome);
	Streamer->InitializeRoad();

	if (bSpawnTraffic)
	{
		Traffic = World->SpawnActor<AEndlessTrafficManager>(AEndlessTrafficManager::StaticClass(), FTransform::Identity, Params);

		if (Traffic)
		{
			Traffic->Initialize(Streamer);
		}
	}

	RunStartDistance = 0.0;
	FurthestDistance = 0.0;
}

void AEndlessGameMode::RestartPlayer(AController* NewPlayer)
{
	if (!NewPlayer || NewPlayer->IsPendingKillPending())
	{
		return;
	}

	EnsureWorldSpawned();

	if (Streamer)
	{
		// the level has no PlayerStart, spawn on the road
		RestartPlayerAtTransform(NewPlayer, Streamer->GetStartTransform());
	}
	else
	{
		Super::RestartPlayer(NewPlayer);
	}
}

void AEndlessGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	// age HUD messages
	for (int32 i = Popups.Num() - 1; i >= 0; --i)
	{
		Popups[i].TimeLeft -= DeltaSeconds;

		if (Popups[i].TimeLeft <= 0.0f)
		{
			Popups.RemoveAt(i);
		}
	}

	if (!bRunActive)
	{
		RestartCountdown -= DeltaSeconds;

		if (RestartCountdown <= 0.0f)
		{
			StartRun();
		}

		return;
	}

	const APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);
	if (!PlayerPawn || !Streamer)
	{
		return;
	}

	// faster driving scores more per meter
	const double SpeedKmh = PlayerPawn->GetVelocity().Size() * 0.036;
	Stats.Multiplier = 1.0f + FMath::Clamp(float(SpeedKmh) / DoubleMultiplierSpeedKmh, 0.0f, 3.0f);

	// only new ground counts, so driving back and forth doesn't farm points
	const double Distance = Streamer->GetPlayerDistance();
	if (Distance > FurthestDistance)
	{
		const double GainedMeters = (Distance - FurthestDistance) / 100.0;
		FurthestDistance = Distance;
		ScoreRemainder += GainedMeters * Stats.Multiplier;
	}

	Stats.DistanceMeters = float((FurthestDistance - RunStartDistance) / 100.0);

	const int32 WholePoints = FMath::FloorToInt32(ScoreRemainder);
	Stats.Score += WholePoints;
	ScoreRemainder -= WholePoints;

	// combos expire
	TimeSinceNearMiss += DeltaSeconds;
	if (Stats.Combo > 0 && TimeSinceNearMiss > ComboTimeout)
	{
		Stats.Combo = 0;
	}
}

void AEndlessGameMode::AddCoins(int32 Amount)
{
	Stats.Coins += Amount;

	if (bRunActive)
	{
		Stats.Score += CoinPoints * Amount;
	}

	if (SaveData)
	{
		SaveData->TotalCoins += Amount;
	}

	AddPopup(FString::Printf(TEXT("+%d"), CoinPoints * Amount), FLinearColor(1.0f, 0.75f, 0.1f), 0.8f);
}

void AEndlessGameMode::RegisterNearMiss(bool bOncoming, double LateralGap)
{
	if (!bRunActive)
	{
		return;
	}

	++Stats.Combo;
	++Stats.NearMisses;
	Stats.BestCombo = FMath::Max(Stats.BestCombo, Stats.Combo);
	TimeSinceNearMiss = 0.0f;

	// closer and oncoming passes are worth more
	float Bonus = bOncoming ? OncomingBonus : 1.0f;
	if (LateralGap < 260.0)
	{
		Bonus *= 1.5f;
	}

	const int32 Points = FMath::RoundToInt32(NearMissPoints * Stats.Combo * Bonus);
	Stats.Score += Points;

	const FString Label = bOncoming ? TEXT("ONCOMING NEAR MISS") : TEXT("NEAR MISS");
	AddPopup(FString::Printf(TEXT("%s  x%d   +%d"), *Label, Stats.Combo, Points), FLinearColor(0.2f, 0.9f, 1.0f), 1.6f);

	OnNearMiss.Broadcast(Stats.Combo);
}

void AEndlessGameMode::RegisterCrash(float ImpactSpeedKmh)
{
	if (!bRunActive)
	{
		return;
	}

	if (ImpactSpeedKmh >= RunEndingImpactKmh)
	{
		OnCrash.Broadcast(true);
		EndRun();
	}
	else
	{
		if (Stats.Combo > 0)
		{
			AddPopup(TEXT("COMBO LOST"), FLinearColor(1.0f, 0.3f, 0.2f), 1.2f);
		}

		Stats.Combo = 0;
		OnCrash.Broadcast(false);
	}
}

void AEndlessGameMode::HandleFellOff()
{
	if (bRunActive)
	{
		if (Stats.Combo > 0)
		{
			AddPopup(TEXT("COMBO LOST"), FLinearColor(1.0f, 0.3f, 0.2f), 1.2f);
		}

		Stats.Combo = 0;
		AddPopup(TEXT("BACK ON THE ROAD"), FLinearColor::White, 1.5f);
	}

	RespawnPlayerOnRoad(0.0);
}

void AEndlessGameMode::RespawnPlayerOnRoad(double ExtraDistance)
{
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);
	if (!PlayerPawn || !Streamer)
	{
		return;
	}

	const double Distance = Streamer->GetPlayerDistance() + ExtraDistance;

	// make sure the road exists before dropping the car on it
	Streamer->SetPlayerDistance(Distance);

	if (Traffic)
	{
		Traffic->ClearAround(Distance, 8000.0);
	}

	const FTransform Spot = Streamer->GetTransformAtDistance(Distance, EndlessRoadLayout::LaneCenters[2], 80.0);
	PlayerPawn->SetActorTransform(Spot, false, nullptr, ETeleportType::TeleportPhysics);

	if (UPrimitiveComponent* Root = Cast<UPrimitiveComponent>(PlayerPawn->GetRootComponent()))
	{
		Root->SetPhysicsLinearVelocity(FVector::ZeroVector);
		Root->SetPhysicsAngularVelocityInDegrees(FVector::ZeroVector);
	}

	// teleporting forward doesn't score
	FurthestDistance = FMath::Max(FurthestDistance, Distance);
}

void AEndlessGameMode::EndRun()
{
	bRunActive = false;
	RestartCountdown = RestartDelay;
	bNewBest = false;

	if (SaveData)
	{
		++SaveData->RunsPlayed;

		if (Stats.Score > SaveData->BestScore)
		{
			SaveData->BestScore = Stats.Score;
			bNewBest = true;
		}

		SaveData->BestDistanceMeters = FMath::Max(SaveData->BestDistanceMeters, Stats.DistanceMeters);
		SaveData->BestCombo = FMath::Max(SaveData->BestCombo, Stats.BestCombo);
	}

	SaveProgress();
}

void AEndlessGameMode::StartRun()
{
	RespawnPlayerOnRoad(1500.0);

	Stats = FEndlessRunStats();
	RunStartDistance = Streamer ? Streamer->GetPlayerDistance() : 0.0;
	FurthestDistance = RunStartDistance;
	ScoreRemainder = 0.0;
	TimeSinceNearMiss = 0.0f;
	bRunActive = true;
	bNewBest = false;

	AddPopup(TEXT("GO!"), FLinearColor(0.4f, 1.0f, 0.4f), 1.2f);
}

void AEndlessGameMode::AddPopup(const FString& Text, const FLinearColor& Color, float Duration)
{
	FEndlessPopup& Popup = Popups.AddDefaulted_GetRef();
	Popup.Text = Text;
	Popup.Color = Color;
	Popup.TimeLeft = Duration;

	// keep the list short
	while (Popups.Num() > 5)
	{
		Popups.RemoveAt(0);
	}
}

void AEndlessGameMode::LoadProgress()
{
	if (SaveData)
	{
		return;
	}

	if (UGameplayStatics::DoesSaveGameExist(UEndlessSaveGame::SlotName, 0))
	{
		SaveData = Cast<UEndlessSaveGame>(UGameplayStatics::LoadGameFromSlot(UEndlessSaveGame::SlotName, 0));
	}

	if (!SaveData)
	{
		SaveData = Cast<UEndlessSaveGame>(UGameplayStatics::CreateSaveGameObject(UEndlessSaveGame::StaticClass()));
	}
}

void AEndlessGameMode::SaveProgress()
{
	if (SaveData)
	{
		UGameplayStatics::SaveGameToSlot(SaveData, UEndlessSaveGame::SlotName, 0);
	}
}
