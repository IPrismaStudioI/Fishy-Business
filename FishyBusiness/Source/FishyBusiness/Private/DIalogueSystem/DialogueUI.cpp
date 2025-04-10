// Fill out your copyright notice in the Description page of Project Settings.


#include "DIalogueSystem/DialogueUI.h"

#include "Blueprint/WidgetTree.h"
#include "DIalogueSystem/DialogueTriggers/ButtonDialogueTriggerBase.h"
#include "EventManager/EventList.h"
#include "FishyBusiness/FishyBusinessGameModeBase.h"

void UDialogueUI::NativeConstruct()
{
	Super::NativeConstruct();
	
	// Initial UI state: hidden
	HideDialogueStart();

	// Registering functions to EventManager
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	
	UEventBus* EventManager = gamemode->xDialogueEventBus;
	
	UEventWrapper::RegisterEvent(EventManager, EventListDialogue::CHANGE_SENTENCE, MakeShared<TFunction<void(const EventParameters&)>>( [this] (const EventParameters& Params) { ChangeSentence(Params) ;}));
	UEventWrapper::RegisterEvent(EventManager, EventListDialogue::CHANGE_NAME, MakeShared<TFunction<void(const EventParameters&)>>([this](const EventParameters& Params) { ChangeName(Params); }));
	UEventWrapper::RegisterEvent(EventManager, EventListDialogue::START_DIALOGUE, MakeShared<TFunction<void(const EventParameters&)>>([this](const EventParameters& Params) { ShowDialogue(Params); }));
	UEventWrapper::RegisterEvent(EventManager, EventListDialogue::END_DIALOGUE, MakeShared<TFunction<void(const EventParameters&)>>([this](const EventParameters& Params) { HideDialogue(Params); }));
	UEventWrapper::RegisterEvent(EventManager, EventListDialogue::START_CHOICES, MakeShared<TFunction<void(const EventParameters&)>>([this](const EventParameters& Params) { ShowChoices(Params); }));
	UEventWrapper::RegisterEvent(EventManager, EventListDialogue::HIDE_CHOICES, MakeShared<TFunction<void(const EventParameters&)>>([this](const EventParameters& Params) { HideChoices(Params); }));

	_xContinueBtn->OnClicked.AddDynamic(this, &UDialogueUI::OnContinueBtnClicked);
}

void UDialogueUI::OnContinueBtnClicked()
{
	EventParameters eventParameters;
	eventParameters.Add(nullptr);
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	
	gamemode->xDialogueEventBus->TriggerEvent(EventListDialogue::CONTINUE_DIALOGUE, eventParameters);
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
	TArray<FString> allIDChoices;
	parameters[0]->Getter<FString>().ParseIntoArray(allIDChoices, TEXT("|"));
	TArray<FString> allAnswers;
	parameters[0]->Getter<FString>().ParseIntoArray(allAnswers, TEXT("|"));
	
	for (int i = 0; i < allIDChoices.Num(); i++) {
		UButtonDialogueTriggerBase *choiceBtn1 = WidgetTree->ConstructWidget<UButtonDialogueTriggerBase>(UButtonDialogueTriggerBase::StaticClass());
		choiceBtn1->Set_SDialogueID(allIDChoices[i]);

		UTextBlock* labelChoice1 = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
		labelChoice1->SetText(FText::FromString(allAnswers[i]));
		
		_xChoiceContainer->AddChild(choiceBtn1);
	}
}
