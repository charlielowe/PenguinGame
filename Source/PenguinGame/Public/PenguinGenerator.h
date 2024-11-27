// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PenguinGenerator.generated.h"

UCLASS()
class PENGUINGAME_API APenguinGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APenguinGenerator();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	float timer = 0.f;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Spawner Handle
	FTimerHandle SpawnerHandle;
	
	// Function that gets called when the timer time outs
	void SpawnPenguin();
	int32 loops= 0;

	/** Penguin class to spawn */
	UPROPERTY(EditAnywhere, Category = Penguin, meta = (AllowPrivateAccess = "True"))
	TSubclassOf<class AMyPenguin> PenguinClass;

private:
	UPROPERTY(EditAnywhere, Category = Penguin, meta = (AllowPrivateAccess = "True"))
	FVector Offset = FVector(0, 0, 230);

	UPROPERTY(EditAnywhere, Category = Penguin, meta = (AllowPrivateAccess = "True"))
	float spawnTime = 0.f;

	class APenguinManager* penguinManager;
};
