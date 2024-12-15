// Fill out your copyright notice in the Description page of Project Settings.


#include "ConveyorBelt.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AConveyorBelt::AConveyorBelt()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DefaultRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultRoot"));
	SetRootComponent(DefaultRoot);
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	Mesh->SetupAttachment(DefaultRoot);

	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("Sphere Collider"));
	BoxCollider->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	BoxCollider->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	BoxCollider->SetupAttachment(Mesh);

	

}

// Called when the game starts or when spawned
void AConveyorBelt::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AConveyorBelt::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (canMove == false) {
		return;
	}
	FRotator MeshRotation = Mesh->GetComponentRotation();
	FVector MeshForwardVector = UKismetMathLibrary::GetForwardVector(MeshRotation);
	FVector MoveAmount = MeshForwardVector * (speed * DeltaTime);
	TArray<AActor*> Result;
	BoxCollider->GetOverlappingActors(Result);
	for (AActor* Actor : Result) {
		Actor->AddActorWorldOffset(MoveAmount);

	}
	
}

void AConveyorBelt::EnableActor_Implementation()
{
	canMove = true;
}

void AConveyorBelt::DisableActor_Implementation()
{
	canMove = false;
}



