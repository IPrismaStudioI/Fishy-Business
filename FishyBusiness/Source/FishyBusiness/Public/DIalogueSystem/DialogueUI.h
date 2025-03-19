// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
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
	UButton* _xContinueBtn;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* _xSentence;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* _xName;
	UPROPERTY(meta = (BindWidget))
	UVerticalBox* _xChoiceContainter;
	
private:
	void ChangeSentence();
	void ChangeName();
	void HideDialogue();
	void ShowDialogue();
	void ShowChoices();
	void HideChoices();
	void FillChoiceContainter();

public:
	UDialogueUI();
};
