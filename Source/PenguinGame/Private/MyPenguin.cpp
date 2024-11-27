// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPenguin.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "PenguinGameCharacter.h"

// Sets default values
AMyPenguin::AMyPenguin()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

	collider = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Collider"));
	RootComponent = collider;

	collider->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	collider->InitSphereRadius(37.f);
	collider->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	collider->SetSimulatePhysics(true);

	collider->OnComponentBeginOverlap.AddDynamic(this, &AMyPenguin::OnPickup);

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	mesh->SetupAttachment(collider);
	//mesh->AttachToComponent(collider, FAttachmentTransformRules::KeepWorldTransform);


}

// Called when the game starts or when spawned
void AMyPenguin::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPenguin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyPenguin::OnPickup(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	APenguinGameCharacter* charRef = Cast<APenguinGameCharacter>(OtherActor);
	if (charRef != nullptr) {
		charRef->collectPenguin(value);
		
		Destroy();
	}
}

