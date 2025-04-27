// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "QuestItemUI.h"
#include "Blueprint/UserWidget.h"
#include "Components/CanvasPanel.h"
#include "QuestBoardUI.generated.h"

/**
 * 
 */
UCLASS()
class FISHYBUSINESS_API UQuestBoardUI : public UUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(meta = (BindWidget))
	UCanvasPanel* _xCanvas;
	UPROPERTY(meta = (BindWidget))
	UCanvasPanel* _xCanvasBulletin;
	
public:
	UPROPERTY()
	TArray<UQuestItemUI*> xQuestItemUIList;
	
public:
	virtual void NativeConstruct() override;

};
