// Fill out your copyright notice in the Description page of Project Settings.


#include "PenguinGenerator.h"
#include "MyPenguin.h"
#include "PenguinManager.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
APenguinGenerator::APenguinGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APenguinGenerator::BeginPlay()
{
	Super::BeginPlay();

	spawnTime2 = spawnTime;
	
	GetWorldTimerManager().SetTimer(SpawnerHandle, this, &APenguinGenerator::SpawnPenguin, spawnTime, true);


	// Max Penguins Code
	/*TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APenguinManager::StaticClass(), FoundActors);

	if (sizeof(FoundActors) > 0) {
		penguinManager = Cast<APenguinManager>(FoundActors[0]);
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Purple, TEXT("No Penguin Managers Found"));
	}*/
}

// Called every frame
void APenguinGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APenguinGenerator::SpawnPenguin()
{
	// Try and spawn a penguin
	if (PenguinClass != nullptr)
	{
		UWorld* const World = GetWorld();
		if (World != nullptr)
		{
			// Rotation to use when spawning penguin is the same as the actor's rotation
			const FRotator SpawnRotation = this->GetActorRotation();

			// Actor Spawn Location
			
			const FVector SpawnLocation = this->GetActorLocation() + Offset;

			//Set Spawn Collision Handling Override
			FActorSpawnParameters ActorSpawnParams;
			ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;
			World->SpawnActor<AMyPenguin>(PenguinClass, SpawnLocation, SpawnRotation, ActorSpawnParams);


			// MAX PENGUINS CODE
			/*if (penguinManager != nullptr)
			{
				// If the current amount of penguins is less than the max amount, spawn more penguins
				if (penguinManager->getCurrentPenguins() < penguinManager->getMaxPenguins()) {
					// Spawn the projectile at the muzzle
					World->SpawnActor<AMyPenguin>(PenguinClass, SpawnLocation, SpawnRotation, ActorSpawnParams);
					penguinManager->increaseCurrentPenguins();
				}
				else {
					GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, TEXT("Max Penguins Reached"));

				}
			}
			else
			{
				GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, TEXT("Penguin Manager is nullptr"));

			}*/
			
			
		}
		else {
			GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, TEXT("World is nullptr"));

		}
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, TEXT("Penguin is nullptr"));

	}
	

	// Stop the timer
	/*if (loops >= 3)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Stop"));
		GetWorldTimerManager().ClearTimer(SpawnerHandle);
	}*/
}

void APenguinGenerator::stopSpawning()
{
	spawnTime = 0.f;
	GetWorldTimerManager().SetTimer(SpawnerHandle, this, &APenguinGenerator::SpawnPenguin, spawnTime, true);
}

void APenguinGenerator::resetSpawnTime()
{
	spawnTime = spawnTime2;
	GetWorldTimerManager().SetTimer(SpawnerHandle, this, &APenguinGenerator::SpawnPenguin, spawnTime, true);
}

