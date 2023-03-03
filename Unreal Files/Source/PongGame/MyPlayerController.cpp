// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "PongHUD.h"

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (WBP_PongHUD) {
		MyHud = CreateWidget<UPongHUD>(GetWorld(), WBP_PongHUD);
		MyHud->AddToViewport();
	}
}