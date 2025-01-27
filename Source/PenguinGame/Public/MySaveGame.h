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

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FString SaveSlotName;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int32 UserIndex;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UWorld* WorldContextObject;

	// Player
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int32 playerMoney;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int32 penguinPoints;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool hasPortableShop;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int32 fishingPoints;

	// Fishing Character
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float fishValueMultiplier;

	// Shop
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int32 itemsToShow;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int32 totalMoney;

	// Placed Items
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TArray<TSubclassOf<AActor>> savedClasses;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TArray<FTransform> savedTransforms;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TArray<float> savedUpgradeLevels;
	

	UMySaveGame();


	
};
