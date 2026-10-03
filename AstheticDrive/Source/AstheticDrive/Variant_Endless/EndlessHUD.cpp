// Copyright Epic Games, Inc. All Rights Reserved.

#include "EndlessHUD.h"
#include "EndlessGameMode.h"
#include "EndlessSaveGame.h"
#include "Engine/Canvas.h"
#include "Engine/Engine.h"
#include "Engine/Font.h"
#include "Engine/World.h"

void AEndlessHUD::DrawHUD()
{
	Super::DrawHUD();

	const AEndlessGameMode* GameMode = GetWorld()->GetAuthGameMode<AEndlessGameMode>();
	if (!GameMode || !Canvas || !GEngine)
	{
		return;
	}

	UFont* BigFont = GEngine->GetLargeFont();
	UFont* SmallFont = GEngine->GetMediumFont();

	const float Scale = TextScale * Canvas->ClipY / 1080.0f;
	const float Margin = 40.0f * Scale;
	const float Width = Canvas->ClipX;
	const float Height = Canvas->ClipY;

	const FEndlessRunStats& Stats = GameMode->GetRunStats();
	const UEndlessSaveGame* Save = GameMode->GetSaveData();

	const FLinearColor White(1.0f, 1.0f, 1.0f, 0.95f);
	const FLinearColor Dim(0.8f, 0.8f, 0.8f, 0.85f);
	const FLinearColor Gold(1.0f, 0.75f, 0.1f);

	// run stats, top left
	float Y = Margin;
	DrawShadowedText(FText::AsNumber(Stats.Score).ToString(), White, Margin, Y, BigFont, 2.4f * Scale);
	Y += 52.0f * Scale;
	DrawShadowedText(FString::Printf(TEXT("x%.1f"), Stats.Multiplier), Dim, Margin, Y, SmallFont, 1.4f * Scale);
	Y += 30.0f * Scale;
	DrawShadowedText(FString::Printf(TEXT("%.2f km"), Stats.DistanceMeters / 1000.0f), White, Margin, Y, SmallFont, 1.6f * Scale);
	Y += 32.0f * Scale;
	DrawShadowedText(FString::Printf(TEXT("%d coins"), Stats.Coins), Gold, Margin, Y, SmallFont, 1.6f * Scale);

	// best, top right
	if (Save)
	{
		DrawShadowedText(FString::Printf(TEXT("BEST  %s"), *FText::AsNumber(Save->BestScore).ToString()), Dim, Width - Margin, Margin, SmallFont, 1.5f * Scale, 1.0f);
		DrawShadowedText(FString::Printf(TEXT("TOTAL COINS  %d"), Save->TotalCoins), Gold, Width - Margin, Margin + 30.0f * Scale, SmallFont, 1.3f * Scale, 1.0f);
	}

	// combo, top center
	if (Stats.Combo > 1)
	{
		DrawShadowedText(FString::Printf(TEXT("COMBO x%d"), Stats.Combo), FLinearColor(0.2f, 0.9f, 1.0f), Width * 0.5f, Margin, BigFont, 1.8f * Scale, 0.5f);
	}

	// popups, stacked above the center of the screen, fading out
	float PopupY = Height * 0.28f;
	const TArray<FEndlessPopup>& Popups = GameMode->GetPopups();
	for (int32 i = Popups.Num() - 1; i >= 0; --i)
	{
		const FEndlessPopup& Popup = Popups[i];
		FLinearColor Color = Popup.Color;
		Color.A = FMath::Clamp(Popup.TimeLeft / 0.4f, 0.0f, 1.0f);

		DrawShadowedText(Popup.Text, Color, Width * 0.5f, PopupY, BigFont, 1.6f * Scale, 0.5f);
		PopupY += 40.0f * Scale;
	}

	// run over panel
	if (!GameMode->IsRunActive())
	{
		const float PanelW = 620.0f * Scale;
		const float PanelH = 300.0f * Scale;
		const float PanelX = (Width - PanelW) * 0.5f;
		const float PanelY = (Height - PanelH) * 0.5f;

		DrawRect(FLinearColor(0.0f, 0.0f, 0.0f, 0.6f), PanelX, PanelY, PanelW, PanelH);

		float LineY = PanelY + 24.0f * Scale;
		DrawShadowedText(TEXT("CRASHED"), FLinearColor(1.0f, 0.3f, 0.2f), Width * 0.5f, LineY, BigFont, 2.4f * Scale, 0.5f);
		LineY += 70.0f * Scale;

		DrawShadowedText(FString::Printf(TEXT("SCORE  %s"), *FText::AsNumber(Stats.Score).ToString()), White, Width * 0.5f, LineY, SmallFont, 1.8f * Scale, 0.5f);
		LineY += 38.0f * Scale;

		DrawShadowedText(FString::Printf(TEXT("%.2f km   |   %d near misses   |   best combo x%d"), Stats.DistanceMeters / 1000.0f, Stats.NearMisses, Stats.BestCombo), Dim, Width * 0.5f, LineY, SmallFont, 1.3f * Scale, 0.5f);
		LineY += 38.0f * Scale;

		if (GameMode->IsNewBest())
		{
			DrawShadowedText(TEXT("NEW BEST!"), Gold, Width * 0.5f, LineY, BigFont, 1.6f * Scale, 0.5f);
		}

		LineY += 44.0f * Scale;
		DrawShadowedText(FString::Printf(TEXT("next run in %.1f"), FMath::Max(GameMode->GetRestartCountdown(), 0.0f)), Dim, Width * 0.5f, LineY, SmallFont, 1.2f * Scale, 0.5f);
	}
}

void AEndlessHUD::DrawShadowedText(const FString& Text, const FLinearColor& Color, float X, float Y, UFont* Font, float Scale, float Alignment)
{
	float TextW = 0.0f;
	float TextH = 0.0f;
	GetTextSize(Text, TextW, TextH, Font, Scale);

	const float DrawX = X - TextW * Alignment;
	const float Offset = FMath::Max(1.0f, 2.0f * Scale * 0.5f);

	DrawText(Text, FLinearColor(0.0f, 0.0f, 0.0f, Color.A * 0.7f), DrawX + Offset, Y + Offset, Font, Scale);
	DrawText(Text, Color, DrawX, Y, Font, Scale);
}
