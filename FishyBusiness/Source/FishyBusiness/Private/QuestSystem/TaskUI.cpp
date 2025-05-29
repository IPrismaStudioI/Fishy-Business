// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestSystem/TaskUI.h"

#include "FishyBusiness/FishyBusinessGameModeBase.h"


void UTaskUI::NativeConstruct()
{
	Super::NativeConstruct();

	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	
	UEventBus* EventManager = gamemode->xQuestEventBus;

	UEventWrapper::RegisterEvent(EventManager, EventListQuest::UPDATE_UI_TASK, MakeShared<TFunction<void(const EventParameters&)>>( [this] (const EventParameters& Params) {ChangeTaskDescription(Params);}));
	UEventWrapper::RegisterEvent(EventManager, EventListQuest::HIDE_UI_TASK, MakeShared<TFunction<void(const EventParameters&)>>( [this] (const EventParameters& Params) {ClearUI(Params);}));
	
}

void UTaskUI::ClearUI(EventParameters parameters)
{
	xCanvas->SetVisibility(ESlateVisibility::Collapsed);
}

void UTaskUI::ChangeTaskDescription(EventParameters parameters)
{
	xCanvas->SetVisibility(ESlateVisibility::Visible);
	
	FString id = parameters[0]->Getter<FString>();
	int taskPos = parameters[1]->Getter<int>();

	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	UDA_QuestModuleBase* task = gamemode->xQuestDataManager->GetQuestModuleListFromDT(id)[taskPos];

	FText text = FText::FromString(task->sDescription);
	xTaskDescription->SetText(text);
}
