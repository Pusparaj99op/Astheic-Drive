// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EndlessBiomeData.generated.h"

class UMaterialInterface;
class UStaticMesh;

/**
 *  Look and dressing of one biome of the endless road.
 *  Every asset slot is optional: when left empty the road falls back to engine basic shapes
 *  tinted with the colors below, so the game runs without any purchased content.
 *  Create one in the editor (Miscellaneous > Data Asset > EndlessBiomeData) to swap in Fab assets.
 */
UCLASS(BlueprintType)
class UEndlessBiomeData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:

	/** Asphalt material. Leave empty to use a tinted basic material */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Materials")
	TObjectPtr<UMaterialInterface> RoadMaterial;

	/** Shoulder material */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Materials")
	TObjectPtr<UMaterialInterface> ShoulderMaterial;

	/** Terrain (verge and slope down to the sea) material */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Materials")
	TObjectPtr<UMaterialInterface> TerrainMaterial;

	/** Guard rail material */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Materials")
	TObjectPtr<UMaterialInterface> RailMaterial;

	/** Lane marking material */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Materials")
	TObjectPtr<UMaterialInterface> MarkingMaterial;

	/** Bridge deck and pillar material */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Materials")
	TObjectPtr<UMaterialInterface> ConcreteMaterial;

	/** Ocean surface material */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Materials")
	TObjectPtr<UMaterialInterface> OceanMaterial;

	/** Fallback colors, used with the basic material when no material is set */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Colors")
	FLinearColor RoadColor = FLinearColor(0.025f, 0.025f, 0.028f);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Colors")
	FLinearColor ShoulderColor = FLinearColor(0.06f, 0.055f, 0.05f);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Colors")
	FLinearColor TerrainColor = FLinearColor(0.16f, 0.12f, 0.07f);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Colors")
	FLinearColor RailColor = FLinearColor(0.35f, 0.35f, 0.37f);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Colors")
	FLinearColor MarkingColor = FLinearColor(0.8f, 0.8f, 0.75f);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Colors")
	FLinearColor ConcreteColor = FLinearColor(0.22f, 0.21f, 0.2f);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Colors")
	FLinearColor OceanColor = FLinearColor(0.01f, 0.035f, 0.07f);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Colors")
	FLinearColor PalmTrunkColor = FLinearColor(0.12f, 0.08f, 0.05f);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Colors")
	FLinearColor PalmLeavesColor = FLinearColor(0.03f, 0.09f, 0.03f);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Colors")
	FLinearColor LampPostColor = FLinearColor(0.1f, 0.1f, 0.11f);

	/** Optional palm mesh. Pivot at the base. Replaces the trunk + canopy basic shapes */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Props")
	TObjectPtr<UStaticMesh> PalmMesh;

	/** Optional street lamp mesh. Pivot at the base */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Props")
	TObjectPtr<UStaticMesh> LampMesh;

	/** Average spacing between palms along each side of the road (cm) */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Props", meta=(ClampMin=500, Units="cm"))
	float PalmSpacing = 2500.0f;

	/** Spacing between street lamps (cm) */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Props", meta=(ClampMin=1000, Units="cm"))
	float LampSpacing = 5000.0f;

	/** Spacing between bridge pillars (cm) */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Props", meta=(ClampMin=1000, Units="cm"))
	float PillarSpacing = 3000.0f;
};
