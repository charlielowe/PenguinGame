// Fill out your copyright notice in the Description page of Project Settings.


#include "SellCircle.h"
#include "PenguinGameCharacter.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ASellCircle::ASellCircle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	RootComponent = mesh;
	mesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	mesh->OnComponentBeginOverlap.AddDynamic(this, &ASellCircle::OnCharacterEnter);
}

// Called when the game starts or when spawned
void ASellCircle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASellCircle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASellCircle::OnCharacterEnter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	APenguinGameCharacter* charRef = Cast<APenguinGameCharacter>(OtherActor);
	if (charRef != nullptr) {
		charRef->ModifyMoney(charRef->getPenguinPoints());
		charRef->ModifyPenguinPoints(-charRef->getPenguinPoints());
	}
}

