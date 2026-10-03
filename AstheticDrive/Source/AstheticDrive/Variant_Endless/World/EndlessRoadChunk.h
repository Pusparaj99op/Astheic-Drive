// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EndlessRoadTypes.h"
#include "EndlessRoadChunk.generated.h"

class FEndlessRoadGenerator;
class UProceduralMeshComponent;
class UInstancedStaticMeshComponent;
class UMaterialInterface;
class UStaticMesh;
class AEndlessCoin;

/** Shared materials and meshes handed to every chunk by the streamer */
USTRUCT()
struct FEndlessChunkAssets
{
	GENERATED_BODY()

	UPROPERTY() TObjectPtr<UMaterialInterface> Road;
	UPROPERTY() TObjectPtr<UMaterialInterface> Shoulder;
	UPROPERTY() TObjectPtr<UMaterialInterface> Terrain;
	UPROPERTY() TObjectPtr<UMaterialInterface> Rail;
	UPROPERTY() TObjectPtr<UMaterialInterface> Marking;
	UPROPERTY() TObjectPtr<UMaterialInterface> Concrete;
	UPROPERTY() TObjectPtr<UMaterialInterface> PalmTrunk;
	UPROPERTY() TObjectPtr<UMaterialInterface> PalmLeaves;
	UPROPERTY() TObjectPtr<UMaterialInterface> LampPost;

	UPROPERTY() TObjectPtr<UStaticMesh> Cylinder;
	UPROPERTY() TObjectPtr<UStaticMesh> Sphere;
	UPROPERTY() TObjectPtr<UStaticMesh> Cube;

	/** Optional biome meshes, replace the basic shape props when set */
	UPROPERTY() TObjectPtr<UStaticMesh> PalmMesh;
	UPROPERTY() TObjectPtr<UStaticMesh> LampMesh;

	UPROPERTY() float PalmSpacing = 2500.0f;
	UPROPERTY() float LampSpacing = 5000.0f;
	UPROPERTY() float PillarSpacing = 3000.0f;

	/** World seed, used to scatter props deterministically */
	UPROPERTY() int32 Seed = 0;
};

/**
 *  One pooled slice of the endless road.
 *  Builds the asphalt, shoulders, guard rails, terrain skirt, bridge deck and lane markings
 *  as a procedural mesh, and scatters props with instanced meshes.
 */
UCLASS(NotBlueprintable)
class AEndlessRoadChunk : public AActor
{
	GENERATED_BODY()

	/** Road surface, terrain and rails */
	UPROPERTY(VisibleAnywhere, Category="Components", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UProceduralMeshComponent> RoadMesh;

	/** Palm trunks, or full palms when the biome provides a palm mesh */
	UPROPERTY(VisibleAnywhere, Category="Components", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UInstancedStaticMeshComponent> PalmTrunks;

	/** Palm canopies */
	UPROPERTY(VisibleAnywhere, Category="Components", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UInstancedStaticMeshComponent> PalmLeaves;

	/** Street lamp posts, or full lamps when the biome provides a lamp mesh */
	UPROPERTY(VisibleAnywhere, Category="Components", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UInstancedStaticMeshComponent> LampPosts;

	/** Street lamp heads */
	UPROPERTY(VisibleAnywhere, Category="Components", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UInstancedStaticMeshComponent> LampHeads;

	/** Bridge pillars */
	UPROPERTY(VisibleAnywhere, Category="Components", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UInstancedStaticMeshComponent> Pillars;

	/** Bridge cross beams */
	UPROPERTY(VisibleAnywhere, Category="Components", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UInstancedStaticMeshComponent> Beams;

public:

	AEndlessRoadChunk();

	/** Builds the chunk covering [Index * Length, (Index + 1) * Length) along the road */
	void Build(FEndlessRoadGenerator& Generator, int32 Index, double Length, const FEndlessChunkAssets& Assets);

	/** Hides the chunk and frees its geometry so it can be pooled */
	void Deactivate();

	/** Returns the chunk index along the road */
	int32 GetChunkIndex() const { return ChunkIndex; }

	/** Coins currently placed on this chunk. Managed by the streamer */
	UPROPERTY(Transient)
	TArray<TObjectPtr<AEndlessCoin>> Coins;

private:

	/** Applies the shared materials and meshes to the components */
	void ApplyAssets(const FEndlessChunkAssets& Assets);

	/** Scatters props along the chunk */
	void BuildProps(FEndlessRoadGenerator& Generator, double StartDistance, double Length, const FEndlessChunkAssets& Assets);

	int32 ChunkIndex = INDEX_NONE;
};
