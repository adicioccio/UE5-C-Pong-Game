// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"
#include "PongGameGameModeBase.h"
#include "MyPlayerController.h"
#include "PongHUD.h"
#include "Components/TextBlock.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include <string> 

// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionSphere"));
	StaticMeshRoot = CreateDefaultSubobject<USceneComponent>(TEXT("StaticMeshRoot"));
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	
	CollisionSphere->SetSimulatePhysics(true);
	CollisionSphere->SetCollisionProfileName("Pawn");
	CollisionSphere->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	SetRootComponent(CollisionSphere);
	StaticMeshRoot->SetupAttachment(RootComponent);
	StaticMeshComponent->SetupAttachment(StaticMeshRoot);

	OnActorBeginOverlap.AddDynamic(this, &ABall::OnActorOverlapBegin);
}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();
	SpawnLocation = GetActorLocation();
	CurrentLocation = GetActorLocation();
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (XDirection) {
		CurrentLocation.X += Speed * DeltaTime;
	}
	else {
		CurrentLocation.X -= Speed * DeltaTime;
	}
	if (YDirection) {
		CurrentLocation.Y += Speed * DeltaTime;
	}
	else {
		CurrentLocation.Y -= Speed * DeltaTime;
	}
	SetActorLocation(CurrentLocation);

}

void ABall::OnActorOverlapBegin(AActor* OverlappedActor, AActor* OtherActor) {
	//FString Message = FString("OnActorOverlapBegin: ") + OtherActor->GetName();
	//GEngine->AddOnScreenDebugMessage(2, 10.f, FColor::Red, Message);
	if (OtherActor->GetName().Contains("BP_Wall")) {
		XDirection = !XDirection;
	}
	if (OtherActor->GetName().Contains("BP_Player")) {
		YDirection = !YDirection;
	}
	if (OtherActor->GetName().Contains("BP_Blue")) {
		GEngine->AddOnScreenDebugMessage(2, 10.f, FColor::Red, "Red Team scored!!");
		CurrentLocation = SpawnLocation;
		XDirection = true;
		YDirection = true;
		redScore += 1;
		SetActorLocation(SpawnLocation);
	}
	if (OtherActor->GetName().Contains("BP_Red")) {
		GEngine->AddOnScreenDebugMessage(2, 10.f, FColor::Blue, "Blue Team scored!!");
		CurrentLocation = SpawnLocation;
		XDirection = true;
		YDirection = true;
		blueScore += 1;
		SetActorLocation(SpawnLocation);
	}
	AMyPlayerController* MyPC = Cast<AMyPlayerController>(GetWorld()->GetFirstPlayerController());
	FText BlueText = FText::FromString(FString::FromInt(blueScore));
	FText RedText = FText::FromString(FString::FromInt(redScore));
	MyPC->MyHud->BlueScore->SetText(BlueText);
	MyPC->MyHud->RedScore->SetText(RedText);
}

