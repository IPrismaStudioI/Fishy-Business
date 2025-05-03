// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/RichTextBlock.h"
#include "QuestModuleUI.generated.h"

/**
 * 
 */
UCLASS()
class FISHYBUSINESS_API UQuestModuleUI : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(meta = (BindWidget))
	URichTextBlock* _xQuestTaskDescription;
	UPROPERTY(meta = (BindWidget))
	URichTextBlock* _xQuestTaskCurrentAmount;
	UPROPERTY(meta = (BindWidget))
	URichTextBlock* _xQuestTaskTotalAmount;
	
public:
	virtual void NativeConstruct() override;
};
