// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/CanvasPanel.h"
#include "Components/TextBlock.h"
#include "EventManager/EventWrapper.h"
#include "TaskUI.generated.h"

/**
 * 
 */
UCLASS()
class FISHYBUSINESS_API UTaskUI : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(meta = (BindWidget))
	UCanvasPanel* xCanvas;
	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UTextBlock* xTaskDescription;

private:
	void ChangeTaskDescription(EventParameters parameters);
	void NativeConstruct();
};
