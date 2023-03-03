// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ball.generated.h"

UCLASS()
class PONGGAME_API ABall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABall();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "My Actor")
		USceneComponent* StaticMeshRoot;

	UPROPERTY(EditAnywhere, Category = "My Actor")
		UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Actor")
		class USphereComponent* CollisionSphere;

	UPROPERTY(EditAnywhere, Category = "My Actor")
		float Speed = 10.0;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
		void OnActorOverlapBegin(AActor* OverlappedActor, AActor* OtherActor);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	FVector SpawnLocation;
	FVector CurrentLocation;
	bool XDirection = true;
	bool YDirection = true;
	int32 blueScore = 0;
	int32 redScore = 0;
};
