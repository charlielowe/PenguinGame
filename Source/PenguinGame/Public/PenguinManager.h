// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PenguinManager.generated.h"

UCLASS()
class PENGUINGAME_API APenguinManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APenguinManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	int32 getMaxPenguins() { return maxPenguins; }
	int32 getCurrentPenguins() { return currentPenguins; }
	void increaseCurrentPenguins() { currentPenguins++; }
	UFUNCTION(BlueprintCallable)
	void decreaseCurrentPenguins() { currentPenguins--; }

private:

	UPROPERTY(EditAnywhere, Category = "Manager")
	int32 maxPenguins = 10;

	int32 currentPenguins = 0;
};
