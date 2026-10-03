// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EndlessRoadGenerator.h"
#include "EndlessRoadChunk.h"
#include "EndlessRoadStreamer.generated.h"

class UEndlessBiomeData;
class UStaticMeshComponent;
class UMaterialInterface;
class UMaterialInstanceDynamic;
class AEndlessCoin;

/**
 *  Streams the endless road around the player.
 *  Owns the seeded road generator and a pool of road chunks: chunks are built ahead of the car
 *  and recycled behind it. Also keeps an ocean plane under the car and places coin rows.
 */
UCLASS()
class AEndlessRoadStreamer : public AActor
{
	GENERATED_BODY()

	/** Ocean surface that follows the player */
	UPROPERTY(VisibleAnywhere, Category="Components", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UStaticMeshComponent> OceanMesh;

protected:

	/** Road seed. 0 picks a random seed every play session */
	UPROPERTY(EditAnywhere, Category="Road")
	int32 Seed = 0;

	/** Length of each streamed chunk */
	UPROPERTY(EditAnywhere, Category="Road", meta=(ClampMin=1000, Units="cm"))
	float ChunkLength = 5000.0f;

	/** Chunks kept built in front of the player */
	UPROPERTY(EditAnywhere, Category="Road", meta=(ClampMin=2))
	int32 ChunksAhead = 12;

	/** Chunks kept built behind the player */
	UPROPERTY(EditAnywhere, Category="Road", meta=(ClampMin=1))
	int32 ChunksBehind = 3;

	/** Max chunks built per frame while streaming, to avoid hitches */
	UPROPERTY(EditAnywhere, Category="Road", meta=(ClampMin=1))
	int32 MaxBuildsPerTick = 2;

	/** Optional biome look. Empty uses tinted basic shapes */
	UPROPERTY(EditAnywhere, Category="Road")
	TObjectPtr<UEndlessBiomeData> Biome;

	/** Chance for a chunk to carry a row of coins */
	UPROPERTY(EditAnywhere, Category="Coins", meta=(ClampMin=0, ClampMax=1))
	float CoinRowChance = 0.35f;

	/** Coins per row */
	UPROPERTY(EditAnywhere, Category="Coins", meta=(ClampMin=1))
	int32 CoinsPerRow = 5;

	/** Spacing between coins in a row */
	UPROPERTY(EditAnywhere, Category="Coins", meta=(Units="cm"))
	float CoinSpacing = 700.0f;

	/** Size of the ocean plane */
	UPROPERTY(EditAnywhere, Category="Ocean", meta=(Units="cm"))
	float OceanSize = 400000.0f;

	/** Base material used for tinted geometry. Needs a vector parameter named "Color" */
	UPROPERTY(EditAnywhere, Category="Materials")
	TObjectPtr<UMaterialInterface> BaseMaterial;

	/** Shared materials and meshes handed to the chunks */
	UPROPERTY(Transient)
	FEndlessChunkAssets ChunkAssets;

	/** Coin material */
	UPROPERTY(Transient)
	TObjectPtr<UMaterialInterface> CoinMaterial;

	/** Built chunks keyed by chunk index */
	UPROPERTY(Transient)
	TMap<int32, TObjectPtr<AEndlessRoadChunk>> ActiveChunks;

	/** Pooled chunks ready for reuse */
	UPROPERTY(Transient)
	TArray<TObjectPtr<AEndlessRoadChunk>> FreeChunks;

	/** Pooled coins ready for reuse */
	UPROPERTY(Transient)
	TArray<TObjectPtr<AEndlessCoin>> FreeCoins;

	/** The road centerline generator */
	FEndlessRoadGenerator Generator;

	/** Player distance along the road, updated every frame */
	double PlayerDistance = 0.0;

	/** True once the road has been initialized */
	bool bInitialized = false;

public:

	AEndlessRoadStreamer();

	/** Sets the seed and biome. Call before InitializeRoad */
	void Configure(int32 InSeed, UEndlessBiomeData* InBiome);

	/** Generates the road and synchronously builds the chunks around the start. Call before spawning the player */
	void InitializeRoad();

	/** Samples the road centerline at a distance */
	FEndlessRoadSample SampleAtDistance(double Distance) { return Generator.SampleAtDistance(Distance); }

	/** Returns a transform on the road surface at a distance, offset sideways and lifted along the surface normal */
	FTransform GetTransformAtDistance(double Distance, double LateralOffset = 0.0, double Lift = 0.0);

	/** Finds the road distance closest to a location, searching around a hint distance */
	double FindDistanceNear(const FVector& Location, double HintDistance);

	/** Returns the signed lateral offset of a location from the road center at a given distance. Positive = right */
	double GetLateralOffset(const FVector& Location, double Distance);

	/** Returns the player's current distance along the road */
	double GetPlayerDistance() const { return PlayerDistance; }

	/** Overrides the tracked player distance, e.g. after teleporting the car */
	void SetPlayerDistance(double Distance);

	/** Returns the spawn transform at the start of the road */
	FTransform GetStartTransform();

	/** Returns the sea surface height. The generator builds the road relative to a sea at Z = 0 */
	double GetSeaLevel() const { return 0.0; }

protected:

	virtual void Tick(float DeltaSeconds) override;

	/** Builds missing chunks and recycles distant ones */
	void UpdateStreaming(bool bBuildAll);

	/** Builds a chunk at the given index, reusing a pooled one if possible */
	void BuildChunk(int32 Index);

	/** Returns a chunk and its coins to the pools */
	void RecycleChunk(AEndlessRoadChunk* Chunk);

	/** Places a coin row on a freshly built chunk */
	void PlaceCoins(AEndlessRoadChunk* Chunk, int32 Index);

	/** Creates the shared materials from the biome or the base material */
	void CreateAssets();

	/** Returns a material: the override if set, otherwise a tinted instance of the base material */
	UMaterialInterface* MakeMaterial(UMaterialInterface* Override, const FLinearColor& Color);
};
