// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "MySaveGame.generated.h"

/**
 * 
 */
UCLASS()
class PENGUINGAME_API UMySaveGame : public USaveGame
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere)
	FString SaveSlotName;

	UPROPERTY(VisibleAnywhere)
	int32 UserIndex;

	// Player
	UPROPERTY(VisibleAnywhere)
	int32 playerMoney;

	UPROPERTY(VisibleAnywhere)
	int32 penguinPoints;

	UPROPERTY(VisibleAnywhere)
	bool hasPortableShop;

	UPROPERTY(VisibleAnywhere)
	int32 fishingPoints;

	// Fishing Character
	UPROPERTY(VisibleAnywhere)
	float fishValueMultiplier;

	// Shop
	UPROPERTY(VisibleAnywhere)
	int32 itemsToShow;

	UPROPERTY(VisibleAnywhere)
	int32 totalMoney;

	UMySaveGame();
	
};
