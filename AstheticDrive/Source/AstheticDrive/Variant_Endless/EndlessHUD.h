// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "EndlessHUD.generated.h"

/**
 *  Canvas HUD for the endless mode: score, distance, coins, combo, near miss popups and the run over panel.
 *  Drawn in C++ so it works without any widget asset. Swap for a UMG widget later.
 */
UCLASS()
class AEndlessHUD : public AHUD
{
	GENERATED_BODY()

protected:

	/** Overall text scale at 1080p */
	UPROPERTY(EditAnywhere, Category="HUD")
	float TextScale = 1.0f;

public:

	virtual void DrawHUD() override;

protected:

	/** Draws text with a drop shadow. Alignment: 0 = left, 0.5 = centered, 1 = right */
	void DrawShadowedText(const FString& Text, const FLinearColor& Color, float X, float Y, UFont* Font, float Scale, float Alignment = 0.0f);
};
