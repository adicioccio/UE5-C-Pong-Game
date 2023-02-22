// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerAI.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
APlayerAI::APlayerAI()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StaticMeshRoot = CreateDefaultSubobject<USceneComponent>(TEXT("StaticMeshRoot"));
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));

	CollisionBox->SetSimulatePhysics(true);
	CollisionBox->SetCollisionProfileName("Pawn");
	CollisionBox->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	SetRootComponent(CollisionBox);
	StaticMeshRoot->SetupAttachment(RootComponent);
	StaticMeshComponent->SetupAttachment(StaticMeshRoot);

	StaticMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	StaticMeshComponent->SetCollisionProfileName(TEXT("IgnoreAll"));
}

// Called when the game starts or when spawned
void APlayerAI::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation();
	FVector BallLocation = Ball->GetActorLocation();

	if (CurrentLocation.X < BallLocation.X) {
		CurrentLocation.X += 1 * Speed;
	}
	if (CurrentLocation.X > BallLocation.X) {
		CurrentLocation.X -= 1 * Speed;
	}
	SetActorLocation(CurrentLocation);


	
}

