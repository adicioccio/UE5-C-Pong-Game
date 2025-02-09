// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class PONGGAME_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, Category = HUD)
		TSubclassOf<class UPongHUD> WBP_PongHUD;

	class UPongHUD* MyHud;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
