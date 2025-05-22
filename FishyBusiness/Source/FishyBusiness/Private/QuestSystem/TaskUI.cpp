// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestSystem/TaskUI.h"

#include "FishyBusiness/FishyBusinessGameModeBase.h"


void UTaskUI::NativeConstruct()
{
	Super::NativeConstruct();

	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	
	UEventBus* EventManager = gamemode->xQuestEventBus;

	UEventWrapper::RegisterEvent(EventManager, EventListQuest::UPDATE_UI_TASK, MakeShared<TFunction<void(const EventParameters&)>>( [this] (const EventParameters& Params) {ChangeTaskDescription(Params);}));
	
}

void UTaskUI::ChangeTaskDescription(EventParameters parameters)
{
	FString id = parameters[0]->Getter<FString>();
	int taskPos = parameters[1]->Getter<int>();

	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	UDA_QuestModuleBase* task = gamemode->xQuestDataManager->GetQuestModuleListFromDT(id)[taskPos];

	FText text = FText::FromString(task->sDescription);
	xTaskDescription->SetText(text);
}
