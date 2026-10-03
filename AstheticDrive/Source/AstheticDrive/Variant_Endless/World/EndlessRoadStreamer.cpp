// Copyright Epic Games, Inc. All Rights Reserved.

#include "EndlessRoadStreamer.h"
#include "EndlessBiomeData.h"
#include "EndlessCoin.h"
#include "AstheticDrive.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "Engine/World.h"
#include "GameFramework/Pawn.h"
#include "Kismet/GameplayStatics.h"
#include "Materials/MaterialInterface.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Math/RandomStream.h"
#include "UObject/ConstructorHelpers.h"

AEndlessRoadStreamer::AEndlessRoadStreamer()
{
	PrimaryActorTick.bCanEverTick = true;

	USceneComponent* Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	OceanMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OceanMesh"));
	OceanMesh->SetupAttachment(Root);
	OceanMesh->SetMobility(EComponentMobility::Movable);
	OceanMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	OceanMesh->SetGenerateOverlapEvents(false);
	OceanMesh->SetCastShadow(false);
	OceanMesh->SetAbsolute(true, true, true);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> PlaneMesh(TEXT("/Engine/BasicShapes/Plane.Plane"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CylinderMesh(TEXT("/Engine/BasicShapes/Cylinder.Cylinder"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMesh(TEXT("/Engine/BasicShapes/Sphere.Sphere"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMesh(TEXT("/Engine/BasicShapes/Cube.Cube"));
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> BasicMaterial(TEXT("/Engine/BasicShapes/BasicShapeMaterial.BasicShapeMaterial"));

	if (PlaneMesh.Succeeded())
	{
		OceanMesh->SetStaticMesh(PlaneMesh.Object);
	}

	ChunkAssets.Cylinder = CylinderMesh.Object;
	ChunkAssets.Sphere = SphereMesh.Object;
	ChunkAssets.Cube = CubeMesh.Object;
	BaseMaterial = BasicMaterial.Object;
}

void AEndlessRoadStreamer::Configure(int32 InSeed, UEndlessBiomeData* InBiome)
{
	// keep the values set on the actor when the game mode has nothing to override
	if (InSeed != 0)
	{
		Seed = InSeed;
	}

	if (InBiome)
	{
		Biome = InBiome;
	}
}

void AEndlessRoadStreamer::InitializeRoad()
{
	if (bInitialized)
	{
		return;
	}

	bInitialized = true;

	const int32 UsedSeed = Seed != 0 ? Seed : FMath::RandRange(1, MAX_int32 - 1);
	Generator.Reset(UsedSeed);
	ChunkAssets.Seed = UsedSeed;

	UE_LOG(LogAstheticDrive, Log, TEXT("Endless road seed: %d"), UsedSeed);

	CreateAssets();

	OceanMesh->SetWorldScale3D(FVector(OceanSize / 100.0f, OceanSize / 100.0f, 1.0f));
	OceanMesh->SetWorldLocation(FVector(0.0, 0.0, GetSeaLevel()));

	PlayerDistance = 0.0;
	UpdateStreaming(true);
}

UMaterialInterface* AEndlessRoadStreamer::MakeMaterial(UMaterialInterface* Override, const FLinearColor& Color)
{
	if (Override)
	{
		return Override;
	}

	if (!BaseMaterial)
	{
		return nullptr;
	}

	UMaterialInstanceDynamic* Material = UMaterialInstanceDynamic::Create(BaseMaterial, this);
	Material->SetVectorParameterValue(TEXT("Color"), Color);
	return Material;
}

void AEndlessRoadStreamer::CreateAssets()
{
	// use a default constructed biome for colors when none is set
	const UEndlessBiomeData* Look = Biome ? Biome.Get() : GetDefault<UEndlessBiomeData>();

	ChunkAssets.Road = MakeMaterial(Look->RoadMaterial, Look->RoadColor);
	ChunkAssets.Shoulder = MakeMaterial(Look->ShoulderMaterial, Look->ShoulderColor);
	ChunkAssets.Terrain = MakeMaterial(Look->TerrainMaterial, Look->TerrainColor);
	ChunkAssets.Rail = MakeMaterial(Look->RailMaterial, Look->RailColor);
	ChunkAssets.Marking = MakeMaterial(Look->MarkingMaterial, Look->MarkingColor);
	ChunkAssets.Concrete = MakeMaterial(Look->ConcreteMaterial, Look->ConcreteColor);
	ChunkAssets.PalmTrunk = MakeMaterial(nullptr, Look->PalmTrunkColor);
	ChunkAssets.PalmLeaves = MakeMaterial(nullptr, Look->PalmLeavesColor);
	ChunkAssets.LampPost = MakeMaterial(nullptr, Look->LampPostColor);
	ChunkAssets.PalmMesh = Look->PalmMesh;
	ChunkAssets.LampMesh = Look->LampMesh;
	ChunkAssets.PalmSpacing = Look->PalmSpacing;
	ChunkAssets.LampSpacing = Look->LampSpacing;
	ChunkAssets.PillarSpacing = Look->PillarSpacing;

	CoinMaterial = MakeMaterial(nullptr, FLinearColor(1.0f, 0.62f, 0.05f));

	OceanMesh->SetMaterial(0, MakeMaterial(Look->OceanMaterial, Look->OceanColor));
}

FTransform AEndlessRoadStreamer::GetTransformAtDistance(double Distance, double LateralOffset, double Lift)
{
	const FEndlessRoadSample Sample = Generator.SampleAtDistance(Distance);
	FTransform Transform = Sample.ToTransform(LateralOffset);
	Transform.AddToTranslation(Sample.Up * Lift);
	return Transform;
}

double AEndlessRoadStreamer::FindDistanceNear(const FVector& Location, double HintDistance)
{
	auto DistSq = [&](double Distance)
	{
		return FVector::DistSquared(Generator.SampleAtDistance(FMath::Max(Distance, 0.0)).Location, Location);
	};

	// coarse search in a window around the hint, biased forward
	double BestDistance = FMath::Max(HintDistance, 0.0);
	double BestDistSq = DistSq(BestDistance);

	for (double Distance = HintDistance - 3000.0; Distance <= HintDistance + 6000.0; Distance += 200.0)
	{
		const double D = DistSq(Distance);
		if (D < BestDistSq)
		{
			BestDistSq = D;
			BestDistance = FMath::Max(Distance, 0.0);
		}
	}

	// refine around the best coarse hit
	const double Coarse = BestDistance;
	for (double Distance = Coarse - 200.0; Distance <= Coarse + 200.0; Distance += 20.0)
	{
		const double D = DistSq(Distance);
		if (D < BestDistSq)
		{
			BestDistSq = D;
			BestDistance = FMath::Max(Distance, 0.0);
		}
	}

	return BestDistance;
}

double AEndlessRoadStreamer::GetLateralOffset(const FVector& Location, double Distance)
{
	const FEndlessRoadSample Sample = Generator.SampleAtDistance(Distance);
	return FVector::DotProduct(Location - Sample.Location, Sample.RightFlat);
}

void AEndlessRoadStreamer::SetPlayerDistance(double Distance)
{
	PlayerDistance = FMath::Max(Distance, 0.0);
	UpdateStreaming(true);
}

FTransform AEndlessRoadStreamer::GetStartTransform()
{
	// spawn in the player's direction of travel, right hand lane, slightly above the road
	return GetTransformAtDistance(2000.0, EndlessRoadLayout::LaneCenters[2], 60.0);
}

void AEndlessRoadStreamer::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (!bInitialized)
	{
		return;
	}

	const APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);
	if (!PlayerPawn)
	{
		return;
	}

	const FVector PlayerLocation = PlayerPawn->GetActorLocation();
	PlayerDistance = FindDistanceNear(PlayerLocation, PlayerDistance);

	UpdateStreaming(false);

	// keep the ocean under the car, snapped to a grid so it doesn't swim
	const double Snap = 10000.0;
	OceanMesh->SetWorldLocation(FVector(FMath::GridSnap(PlayerLocation.X, Snap), FMath::GridSnap(PlayerLocation.Y, Snap), GetSeaLevel()));
}

void AEndlessRoadStreamer::UpdateStreaming(bool bBuildAll)
{
	const int32 CenterIndex = FMath::FloorToInt32(PlayerDistance / ChunkLength);
	const int32 MinIndex = FMath::Max(0, CenterIndex - ChunksBehind);
	const int32 MaxIndex = CenterIndex + ChunksAhead;

	// recycle chunks that fell out of the window
	for (auto It = ActiveChunks.CreateIterator(); It; ++It)
	{
		if (It.Key() < MinIndex || It.Key() > MaxIndex)
		{
			RecycleChunk(It.Value());
			It.RemoveCurrent();
		}
	}

	// build missing chunks, nearest to the player first
	int32 Builds = 0;
	for (int32 Offset = 0; Offset <= FMath::Max(ChunksAhead, ChunksBehind); ++Offset)
	{
		for (const int32 Index : { CenterIndex + Offset, CenterIndex - Offset })
		{
			if (Index < MinIndex || Index > MaxIndex || ActiveChunks.Contains(Index))
			{
				continue;
			}

			if (!bBuildAll && Builds >= MaxBuildsPerTick)
			{
				return;
			}

			BuildChunk(Index);
			++Builds;
		}
	}

	// forget road far behind the player
	Generator.PruneBefore(MinIndex * ChunkLength - 40000.0);
}

void AEndlessRoadStreamer::BuildChunk(int32 Index)
{
	AEndlessRoadChunk* Chunk = nullptr;

	if (FreeChunks.Num() > 0)
	{
		Chunk = FreeChunks.Pop();
	}
	else
	{
		FActorSpawnParameters Params;
		Params.Owner = this;
		Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		Chunk = GetWorld()->SpawnActor<AEndlessRoadChunk>(AEndlessRoadChunk::StaticClass(), FTransform::Identity, Params);
	}

	if (!Chunk)
	{
		return;
	}

	Chunk->Build(Generator, Index, ChunkLength, ChunkAssets);
	ActiveChunks.Add(Index, Chunk);

	PlaceCoins(Chunk, Index);
}

void AEndlessRoadStreamer::RecycleChunk(AEndlessRoadChunk* Chunk)
{
	if (!Chunk)
	{
		return;
	}

	for (AEndlessCoin* Coin : Chunk->Coins)
	{
		if (Coin)
		{
			Coin->Deactivate();
			FreeCoins.Add(Coin);
		}
	}

	Chunk->Coins.Reset();
	Chunk->Deactivate();
	FreeChunks.Add(Chunk);
}

void AEndlessRoadStreamer::PlaceCoins(AEndlessRoadChunk* Chunk, int32 Index)
{
	// keep the start of the road clear
	if (Index < 4)
	{
		return;
	}

	// deterministic per chunk so the same seed gives the same coins
	FRandomStream Random(int32(uint32(ChunkAssets.Seed) * 31337u + uint32(Index) * 104729u));

	if (Random.FRand() > CoinRowChance)
	{
		return;
	}

	// coins go on the player's side of the road
	const double Lane = Random.FRand() < 0.5f ? EndlessRoadLayout::LaneCenters[2] : EndlessRoadLayout::LaneCenters[3];
	const double RowLength = (CoinsPerRow - 1) * CoinSpacing;
	const double RowStart = Index * ChunkLength + Random.FRandRange(0.0f, float(FMath::Max(double(ChunkLength) - RowLength, 0.0)));

	for (int32 i = 0; i < CoinsPerRow; ++i)
	{
		AEndlessCoin* Coin = nullptr;

		if (FreeCoins.Num() > 0)
		{
			Coin = FreeCoins.Pop();
		}
		else
		{
			FActorSpawnParameters Params;
			Params.Owner = this;
			Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
			Coin = GetWorld()->SpawnActor<AEndlessCoin>(AEndlessCoin::StaticClass(), FTransform::Identity, Params);
		}

		if (!Coin)
		{
			continue;
		}

		const FTransform Spot = GetTransformAtDistance(RowStart + i * CoinSpacing, Lane, 90.0);
		Coin->Activate(Spot.GetLocation(), CoinMaterial);
		Chunk->Coins.Add(Coin);
	}
}
