// Fill out your copyright notice in the Description page of Project Settings.


#include "DIalogueSystem/DialogueUI.h"

void UDialogueUI::NativeConstruct()
{
	Super::NativeConstruct();
}

void UDialogueUI::ChangeSentence(EventParameters parameters)
{
	FText text = FText::FromString(*std::any_cast<FString>(parameters[0]));
	_xSentence->SetText(text);
}

void UDialogueUI::ChangeName(EventParameters parameters)
{
	FText text = FText::FromString(*std::any_cast<FString>(parameters[0]));
	_xName->SetText(text);
}

void UDialogueUI::HideDialogue(EventParameters parameters)
{
	_xCanvas->SetVisibility(ESlateVisibility::Collapsed);
}

void UDialogueUI::ShowDialogue(EventParameters parameters)
{
	_xCanvas->SetVisibility(ESlateVisibility::Visible);
}

void UDialogueUI::HideChoices(EventParameters parameters)
{
	_xChoiceContainer->SetVisibility(ESlateVisibility::Collapsed);
}

void UDialogueUI::ShowChoices(EventParameters parameters)
{
	FillChoiceContainer(parameters);
	_xChoiceContainer->SetVisibility(ESlateVisibility::Visible);
}

void UDialogueUI::FillChoiceContainer(EventParameters parameters)
{
}
