// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ButtonDialogueTriggerBase.h"
#include "Blueprint/UserWidget.h"
#include "Components/SizeBox.h"
#include "Components/TextBlock.h"
#include "ChoiceButton.generated.h"

/**
 * 
 */
UCLASS()
class FISHYBUSINESS_API UChoiceButton : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(meta = (BindWidget))
	USizeBox* _xCanvas;
	UPROPERTY(meta = (BindWidget))
	UButtonDialogueTriggerBase* xDialogueTriggerBtn;
	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UTextBlock* _xChoiceLabel;
	
public:
	virtual void NativeConstruct() override;
};
