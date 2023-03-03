// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"



UCLASS()
class PONGGAME_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	APlayerPawn();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "My Pawn")
		USceneComponent* StaticMeshRoot;

	UPROPERTY(EditAnywhere, Category = "My Pawn")
		UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(EditAnywhere, Category = "My Pawn")
		class UCameraComponent* CameraComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Pawn")
		class UBoxComponent* CollisionBox;

	class UFloatingPawnMovement* FloatingPawnMovement;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	/*The Pawns Move Forward Amount per frame*/
	float MoveUpAmount = 0;

	/*The Callback function for the MoveForward Input Axis Event*/
	virtual void MoveUp(float Amount);

};
