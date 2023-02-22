// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Ball.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlayerAI.generated.h"

UCLASS()
class PONGGAME_API APlayerAI : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlayerAI();
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "My Actor")
		USceneComponent* StaticMeshRoot;

	UPROPERTY(EditAnywhere, Category = "My Actor")
		UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Actor")
		class UBoxComponent* CollisionBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Actor")
		ABall* Ball;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Actor")
		float Speed = 2.0;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
