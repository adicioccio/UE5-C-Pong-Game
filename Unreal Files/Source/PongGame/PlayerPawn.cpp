// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerPawn.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include <Kismet/GameplayStatics.h>

// Sets default values
APlayerPawn::APlayerPawn()
{
	StaticMeshRoot = CreateDefaultSubobject<USceneComponent>(TEXT("StaticMeshRoot"));
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	FloatingPawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Movement"));
	
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
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (PlayerInputComponent != nullptr) {
		PlayerInputComponent->BindAxis("MoveUp", this, &APlayerPawn::MoveUp);

	}

}

void APlayerPawn::MoveUp(float Amount)
{
	FloatingPawnMovement->AddInputVector(GetActorForwardVector() * Amount);
}

