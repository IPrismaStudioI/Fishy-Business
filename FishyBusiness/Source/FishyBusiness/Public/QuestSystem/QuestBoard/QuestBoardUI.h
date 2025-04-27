// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "QuestBulletinUI.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/CanvasPanel.h"
#include "EventManager/EventWrapper.h"
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
	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UButton* _xExitBtn;
	
public:
	UPROPERTY()
	TArray<UQuestBulletinUI*> xQuestItemUIList;
	
public:
	virtual void NativeConstruct() override;

	void OpenBoard(EventParameters parameters);
	
	UFUNCTION()
	void CloseBoard();
};
