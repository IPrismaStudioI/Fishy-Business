// Fill out your copyright notice in the Description page of Project Settings.


#include "DIalogueSystem/DialogueUI.h"

#include "EventManager/EventList.h"
#include "FishyBusiness/FishyBusinessGameModeBase.h"

void UDialogueUI::NativeConstruct()
{
	Super::NativeConstruct();

	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	UFunctionWrapper* wrapper = nullptr;
	wrapper->function = [this](const EventParameters& parameters){return ChangeSentence(parameters);};
	gamemode->xDialogueEventManager->Register(EventListDialogue::CHANGE_SENTENCE, wrapper);
}

void UDialogueUI::ChangeSentence(EventParameters parameters)
{
	FText text = FText::FromString(parameters[0]->Getter<FString>());
	_xSentence->SetText(text);
}

void UDialogueUI::ChangeName(EventParameters parameters)
{
	FText text = FText::FromString(parameters[0]->Getter<FString>());
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
