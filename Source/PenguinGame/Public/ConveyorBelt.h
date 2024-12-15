// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnableDisableInterface.h"
#include "ConveyorBelt.generated.h"

UCLASS()
class PENGUINGAME_API AConveyorBelt : public AActor, public IEnableDisableInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AConveyorBelt();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere, Category = Penguin, meta = (AllowPrivateAccess = "True"))
	float speed = 250.f;

	UPROPERTY(EditAnywhere, Category = Penguin, meta = (AllowPrivateAccess = "True"))
	bool canMove = false;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UBoxComponent* BoxCollider;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UStaticMeshComponent* Mesh;

private:
	void EnableActor_Implementation() override;

	void DisableActor_Implementation() override;

	UPROPERTY(EditAnywhere)
	USceneComponent* DefaultRoot = nullptr;
};
