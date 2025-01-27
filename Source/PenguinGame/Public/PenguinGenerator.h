// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnableDisableInterface.h"
#include "Components/AudioComponent.h"
#include "PenguinGenerator.generated.h"

UCLASS()
class PENGUINGAME_API APenguinGenerator : public AActor, public IEnableDisableInterface
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
	int32 loops = 0;

	/** Penguin class to spawn */
	UPROPERTY(EditAnywhere, Category = Penguin, meta = (AllowPrivateAccess = "True"))
	TSubclassOf<class AMyPenguin> PenguinClass;

	UFUNCTION(BlueprintCallable)
	int GetCost() { return cost; }

	UFUNCTION(BlueprintCallable)
	float getSpawnTime() { return spawnTime; }

	UFUNCTION(BlueprintCallable)
	void setSpawnTime(float newTime) { spawnTime = newTime; GetWorldTimerManager().SetTimer(SpawnerHandle, this, &APenguinGenerator::SpawnPenguin, spawnTime, true);
	}

	UFUNCTION(BlueprintCallable)
	void stopSpawning();

	UFUNCTION(BlueprintCallable)
	float getUpgradeLevel() {return upgradeLevel;}

	UFUNCTION(BlueprintCallable)
	void setUpgradeLevel(float value) { upgradeLevel = value; }

	UFUNCTION(BlueprintCallable)
	void resetSpawnTime();
	

private:
	UPROPERTY(EditAnywhere, Category = Penguin, meta = (AllowPrivateAccess = "True"))
	FVector Offset = FVector(0, 0, 230);

	UPROPERTY(EditAnywhere, Category = Penguin, meta = (AllowPrivateAccess = "True"))
	float spawnTime = 0.f;
	
	float spawnTime2 = 0.f;

	UPROPERTY(EditAnywhere, Category = Penguin, meta = (AllowPrivateAccess = "True"))
	int cost = 0;

	UPROPERTY(EditAnywhere, Category = Penguin, meta = (AllowPrivateAccess = "True"))
	int upgradeLevel = 1;

	class APenguinManager* penguinManager;

	void EnableActor_Implementation() override;

	void DisableActor_Implementation() override;

	UPROPERTY(EditAnywhere, Category = "Sound")
	USoundBase* GeneratorSound;

	UPROPERTY(EditAnywhere, Category = "Sound")
	USoundAttenuation* GeneratorAttenuation;


};
