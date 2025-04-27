// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/CanvasPanel.h"
#include "Components/RichTextBlock.h"
#include "QuestItemFocusedUI.generated.h"

/**
 * 
 */
UCLASS()
class FISHYBUSINESS_API UQuestItemFocusedUI : public UUserWidget
{
	GENERATED_BODY()
	
private:
	UPROPERTY(meta = (BindWidget))
	UCanvasPanel* _xCanvas;
	UPROPERTY(meta = (BindWidget))
	URichTextBlock* _xQuestName;
	UPROPERTY(meta = (BindWidget))
	URichTextBlock* _xQuestDescription;
	UPROPERTY(meta = (BindWidget))
	URichTextBlock* _xQuestGiver;
	UPROPERTY(meta = (BindWidget))
	UButton* _xQuestExitBtn;
	UPROPERTY(meta = (BindWidget))
	UButton* _xQuestAcceptBtn;
	
public:
	virtual void NativeConstruct() override;
};
