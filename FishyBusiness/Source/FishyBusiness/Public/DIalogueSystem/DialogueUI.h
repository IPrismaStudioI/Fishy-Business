// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ObserverManager.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/CanvasPanel.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "DialogueUI.generated.h"

/**
 * 
 */
UCLASS()
class FISHYBUSINESS_API UDialogueUI : public UUserWidget
{
	GENERATED_BODY()
private:
	UPROPERTY(meta = (BindWidget))
	UCanvasPanel* _xCanvas;
	UPROPERTY(meta = (BindWidget))
	UButton* _xContinueBtn;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* _xSentence;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* _xName;
	UPROPERTY(meta = (BindWidget))
	UVerticalBox* _xChoiceContainer;

private:
	void ChangeSentence(EventParameters parameters);
	void ChangeName(EventParameters parameters);
	void HideDialogue(EventParameters parameters);
	void ShowDialogue(EventParameters parameters);
	void ShowChoices(EventParameters parameters);
	void HideChoices(EventParameters parameters);
	void FillChoiceContainer(EventParameters parameters);

public:
	virtual void NativeConstruct() override;
};
