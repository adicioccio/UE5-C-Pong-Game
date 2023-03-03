// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PongHUD.generated.h"

/**
 * 
 */
UCLASS()
class PONGGAME_API UPongHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	void NativeConstruct() override;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UTextBlock* BlueScore = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UTextBlock* RedScore = nullptr;
};
