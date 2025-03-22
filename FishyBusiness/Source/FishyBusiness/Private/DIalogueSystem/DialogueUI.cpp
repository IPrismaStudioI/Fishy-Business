// Fill out your copyright notice in the Description page of Project Settings.


#include "DIalogueSystem/DialogueUI.h"

#include "EventManager/EventList.h"
#include "FishyBusiness/FishyBusinessGameModeBase.h"

void UDialogueUI::NativeConstruct()
{
	Super::NativeConstruct();

	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	
	UObserverManager* EventManager = gamemode->xDialogueEventManager;

	HideDialogueStart();
	
	UEventWrapper::RegisterEvent(EventManager, EventListDialogue::CHANGE_SENTENCE, [this](const EventParameters& Params) { ChangeSentence(Params); });
	UEventWrapper::RegisterEvent(EventManager, EventListDialogue::CHANGE_NAME, [this](const EventParameters& Params) { ChangeName(Params); });
	UEventWrapper::RegisterEvent(EventManager, EventListDialogue::HIDE_DIALOGUE, [this](const EventParameters& Params) { HideDialogue(Params); });
	UEventWrapper::RegisterEvent(EventManager, EventListDialogue::SHOW_DIALOGUE, [this](const EventParameters& Params) { ShowDialogue(Params); });
	UEventWrapper::RegisterEvent(EventManager, EventListDialogue::SHOW_CHOICES, [this](const EventParameters& Params) { ShowChoices(Params); });
	UEventWrapper::RegisterEvent(EventManager, EventListDialogue::HIDE_CHOICES, [this](const EventParameters& Params) { HideChoices(Params); });
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

void UDialogueUI::HideDialogueStart()
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
