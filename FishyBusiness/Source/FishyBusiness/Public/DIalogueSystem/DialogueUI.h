// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/CanvasPanel.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "DialogueTriggers/ChoiceButton.h"
#include "EventManager/EventWrapper.h"
#include "EventManager/ObserverManager.h"
#include "DialogueUI.generated.h"

/**
 * 
 */
UCLASS()
class FISHYBUSINESS_API UDialogueUI : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(meta = (BindWidget))
	UCanvasPanel* _xCanvas;
	UPROPERTY(meta = (BindWidget))
	UCanvasPanel* _xCanvasChoices;
	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UCanvasPanel* _xCanvasDialogue;
	UPROPERTY(meta = (BindWidget))
	UButton* _xContinueBtn;
	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UTextBlock* _xSentence;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* _xName;
	UPROPERTY(meta = (BindWidget))
	UVerticalBox* _xChoiceContainer;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UChoiceButton> xChoiceButton;

private:
	/// <summary>
	/// Changes the dialogue sentence displayed in the UI.
	/// </summary>
	/// <param name="param">Array where the first element is the sentence (string).</param>
	void ChangeSentence(EventParameters parameters);

	/// <summary>
	/// Updates the character name displayed in the UI.
	/// </summary>
	/// <param name="param">Array where the first element is the name (string).</param>
	void ChangeName(EventParameters parameters);

	/// <summary>
	/// Hides all dialogue-related UI elements.
	/// </summary>
	/// <param name="param">Optional parameter (not used).</param>
	void FinishDialogue(EventParameters parameters);
	void HideDialogue(EventParameters parameters);
	void HideDialogueStart();

	/// <summary>
	/// Displays all dialogue-related UI elements.
	/// </summary>
	/// <param name="param">Optional parameter (not used).</param>
	void ShowDialogue(EventParameters parameters);

	/// <summary>
	/// Displays the choice box and fills it with options.
	/// </summary>
	/// <param name="param">Array containing dialogues and their labels.</param>
	void ShowChoices(EventParameters parameters);

	/// <summary>
	/// Hides the choice box UI element.
	/// </summary>
	UFUNCTION()
	void HideChoices();
	
	void FillChoiceContainer(EventParameters parameters);
	
	UFUNCTION()
	void OnContinueBtnClicked();

public:
	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnChangeSentence();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnStartDialogue();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnFinishDialogue();
	
};
