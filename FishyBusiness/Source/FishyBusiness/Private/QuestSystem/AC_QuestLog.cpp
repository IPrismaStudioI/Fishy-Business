// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestSystem/AC_QuestLog.h"

#include "FishingSystem/FishingGenerator.h"
#include "FishyBusiness/FishyBusinessGameModeBase.h"
#include "QuestSystem/QuestData/QuestRow.h"
#include "QuestSystem/QuestData/Modules/DA_CollectionModule.h"
#include "QuestSystem/QuestData/Modules/DA_ExplorationModule.h"
#include "QuestSystem/QuestData/Modules/DA_InteractionModule.h"

// Sets default values for this component's properties
UAC_QuestLog::UAC_QuestLog()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAC_QuestLog::BeginPlay()
{
	Super::BeginPlay();


	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	UEventBus* eventManager = gamemode->xQuestEventBus;
	
	UEventWrapper::RegisterEvent(eventManager, EventListQuest::ADD_QUEST, MakeShared<TFunction<void(const EventParameters&)>>([this](const EventParameters& Params) { AddQuestEvent(Params); }));
	UEventWrapper::RegisterEvent(eventManager, EventListQuest::ADVANCE_EXPLORE, MakeShared<TFunction<void(const EventParameters&)>>([this](const EventParameters& Params) { AdvanceExploreEvent(Params); }));
	UEventWrapper::RegisterEvent(eventManager, EventListQuest::ADVANCE_INTERACT, MakeShared<TFunction<void(const EventParameters&)>>([this](const EventParameters& Params) { AdvanceInteractEvent(Params); }));
	UEventWrapper::RegisterEvent(eventManager, EventListQuest::ADVANCE_COLLECT, MakeShared<TFunction<void(const EventParameters&)>>([this](const EventParameters& Params) { AdvanceCollectEvent(Params); }));
	
}


// Called every frame
void UAC_QuestLog::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UAC_QuestLog::AddQuest(FString questID)
{
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();

	if (xQuests.Find(questID) == nullptr)
	{
		xQuests.Add(questID, FPlayerQuest(gamemode->xQuestDataManager->GetQuestModuleListFromDT(questID)));
	}
}

void UAC_QuestLog::AddQuestEvent(EventParameters params)
{
	FString questID = params[0]->Getter<FString>();
	AddQuest(questID);
}


//----------------------------------------------------------------------------------
#pragma region Advance

void UAC_QuestLog::AdvanceExploreModule(EQuestZones zone)
{
	for (const TPair<FString, FPlayerQuest>& QuestPair : xQuests)
	{
		for (int i = 0; i < QuestPair.Value.xModules.Num(); i++)
		{
			if (QuestPair.Value.xModules[i]->eModuleType == EPlayerModuleType::E_EXPLORE_MODULE)
			{
				UDA_ExplorationModule* ExploreModule = Cast<UDA_ExplorationModule>(QuestPair.Value.xModules[i]);
				if (ExploreModule->QuestZones == zone)
				{
					xQuests[QuestPair.Key].xModules[i]->bIsCompleted = true;
					CheckAdvanceModule(QuestPair.Key);
				}
			}
		}
	}
}

void UAC_QuestLog::AdvanceDialogueModule(ENpcNames npcName, FString questID)
{
	for (int i = 0; i < xQuests[questID].xModules.Num(); i++)
	{
		UDA_InteractionModule* InteractModule = Cast<UDA_InteractionModule>(xQuests[questID].xModules[i]);
		if (InteractModule)
		{
			if (InteractModule->eNpcName == npcName)
			{
				xQuests[questID].xModules[i]->bIsCompleted = true;
				CheckAdvanceModule(questID);
			}
		}
	}
}

void UAC_QuestLog::AdvanceCollectModule(UBaseItem* item, int quantity)
{
	for (const TPair<FString, FPlayerQuest>& QuestPair : xQuests)
	{
		for (int i = 0; i < QuestPair.Value.xModules.Num(); i++)
		{
			if (QuestPair.Value.xModules[i]->eModuleType == EPlayerModuleType::E_COLLECT_MODULE)
			{
				UDA_CollectionModule* CollectModule = Cast<UDA_CollectionModule>(QuestPair.Value.xModules[i]);
				if (CollectModule->xTypeOfItem == item && CollectModule->iAmount == quantity)
				{
					xQuests[QuestPair.Key].xModules[i]->bIsCompleted = true;
					CheckAdvanceModule(QuestPair.Key);
				}
			}
		}
	}
}

#pragma endregion

//----------------------------------------------------------------------------------
#pragma region Check Modules 

void UAC_QuestLog::CheckAdvanceModule(FString questID)
{
	if (xQuests[questID].xModules[xQuests[questID].iCurrentModule]->bIsCompleted == true)
	{
		xQuests[questID].iCurrentModule++;
		CheckQuestStatus(questID);
		CheckAdvanceModule(questID);
	}
}

void UAC_QuestLog::CheckQuestStatus(FString questID)
{
	if (xQuests[questID].iCurrentModule == xQuests[questID].xModules.Num() -1)
	{
		xQuests[questID].eStatus = EQuestStatus::E_COMPLETED_QUEST;
	}
}

#pragma endregion

//----------------------------------------------------------------------------------
#pragma region Event Bus Advance 

void UAC_QuestLog::AdvanceExploreEvent(EventParameters params)
{
	EQuestZones zone = params[0]->Getter<EQuestZones>();
	AdvanceExploreModule(zone);
}

void UAC_QuestLog::AdvanceInteractEvent(EventParameters params)
{
	ENpcNames npcName = params[0]->Getter<ENpcNames>();
	FString questID = params[1]->Getter<FString>();
	AdvanceDialogueModule(npcName, questID);
}

void UAC_QuestLog::AdvanceCollectEvent(EventParameters params)
{
	UBaseItem* item = params[0]->Getter<UBaseItem*>();
	int quantity = params[1]->Getter<int>();
	AdvanceCollectModule(item, quantity);
}


#pragma endregion


