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
		QuestAdded();
		
		for (int i = 0; i < xQuests[questID].xModules.Num(); i++)
		{
			UDA_QuestModuleBase* x = xQuests[questID].xModules[i];
			
		    if (UDA_CollectionModule* tmp = Cast<UDA_CollectionModule>(x))
		    {
		   		xQuests[questID].iTotalAmountModules.Add(Cast<UDA_CollectionModule>(tmp)->iAmount);
		   		xQuests[questID].iCurrentAmountModules.Add(0);
		    }
			
		 	if (UDA_ExplorationModule* tpm = Cast<UDA_ExplorationModule>(x))
		 	{
		 		xQuests[questID].iTotalAmountModules.Add(1);
		 		xQuests[questID].iCurrentAmountModules.Add(0);
		 	}
			
		 	if (UDA_InteractionModule* mpt = Cast<UDA_InteractionModule>(x))
		 	{
		 		xQuests[questID].iTotalAmountModules.Add(1);
		 		xQuests[questID].iCurrentAmountModules.Add(0);
		 	}
		}
	}
}

void UAC_QuestLog::AddQuestEvent(EventParameters params)
{
	FString questID = params[0]->Getter<FString>();
	AddQuest(questID);
	CreateAdvanceNotify(0, questID);
}

//----------------------------------------------------------------------------------
#pragma region Advance

void UAC_QuestLog::AdvanceExploreModule(EQuestZones zone)
{
	TArray<FString> questIDs;
	xQuests.GenerateKeyArray(questIDs); //generate array of quest ids from xQuests

	for (int i = 0; i < questIDs.Num(); i++) //checks if there is a quest with a module that requires the specified zone
	{
		if (xQuests[questIDs[i]].eStatus != EQuestStatus::E_ACTIVE_QUEST) break;
		if (UDA_ExplorationModule* ExploreModule = Cast<UDA_ExplorationModule>(xQuests[questIDs[i]].xModules[xQuests[questIDs[i]].iCurrentModule])/*xQuests[questIDs[i]].xModules[xQuests[questIDs[i]].iCurrentModule]->eModuleType == EPlayerModuleType::E_EXPLORE_MODULE*/)
		{
			if (ExploreModule->QuestZones == zone)
			{
				CheckAdvanceModule(questIDs[i]);
				xQuests[questIDs[i]].iCurrentAmountModules[xQuests[questIDs[i]].iCurrentModule - 1] = 1;
			}
		}
	}
}

void UAC_QuestLog::AdvanceDialogueModule(ENpcNames npcName, FString questID, int moduleIndex)
{
	if (xQuests[questID].eStatus != EQuestStatus::E_ACTIVE_QUEST) return;
	if (UDA_InteractionModule* InteractModule = Cast<UDA_InteractionModule>(xQuests[questID].xModules[moduleIndex])) //gets the quest and the specified module (it also checks if it's actually an interaction)
	{
		if (InteractModule->eNpcName == npcName)//checks if the npc is correct
		{
			CheckAdvanceModule(questID);
			xQuests[questID].iCurrentAmountModules[xQuests[questID].iCurrentModule - 1] = 1;
		}
	}
}

void UAC_QuestLog::AdvanceCollectModule(UBaseItem* item, int quantity)
{
	TArray<FString> questIDs;
	xQuests.GenerateKeyArray(questIDs);//generate array of quest ids from xQuests

	for (int i = 0; i < questIDs.Num(); i++) //checks if there is a quest with a module that requires the specified item and amount
	{
		if (xQuests[questIDs[i]].eStatus != EQuestStatus::E_ACTIVE_QUEST) break;
		if (UDA_CollectionModule* CollectModule = Cast<UDA_CollectionModule>(xQuests[questIDs[i]].xModules[xQuests[questIDs[i]].iCurrentModule])/*xQuests[questIDs[i]].xModules[xQuests[questIDs[i]].iCurrentModule]->eModuleType == EPlayerModuleType::E_EXPLORE_MODULE*/)
		{
			if (CollectModule->xTypeOfItem == item && quantity >= CollectModule->iAmount)
			{
				CheckAdvanceModule(questIDs[i]);
				xQuests[questIDs[i]].iCurrentAmountModules[xQuests[questIDs[i]].iCurrentModule - 1] = quantity;
			}
			if (CollectModule->xTypeOfItem == item)
			{
				xQuests[questIDs[i]].iCurrentAmountModules[xQuests[questIDs[i]].iCurrentModule - 1] = quantity;
			}
		}
	}
}

#pragma endregion

//----------------------------------------------------------------------------------
#pragma region Check Modules 

void UAC_QuestLog::CreateAdvanceNotify(int moduleIndex, FString questID)
{
	if (UDA_InteractionModule* module = Cast<UDA_InteractionModule>(xQuests[questID].xModules[moduleIndex]))
	{
		int index = static_cast<int>(module->eNpcName);

		EventParameters eventParameters;
		eventParameters.Add(UParameterWrapper::CreateParameter<int>(index));
		AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
		gamemode->xQuestEventBus->TriggerEvent(EventListQuest::CALL_NOTIFY, eventParameters);
	}
}

void UAC_QuestLog::CheckAdvanceModule(FString questID)
{
	xQuests[questID].iCurrentModule++;
	TaskCompleted();
	CheckQuestStatus(questID);
	if (xQuests[questID].iCurrentModule != xQuests[questID].xModules.Num())
		CreateAdvanceNotify(xQuests[questID].iCurrentModule, questID);
	else
		CreateAdvanceNotify(xQuests[questID].iCurrentModule - 1, questID);
}


void UAC_QuestLog::CheckQuestStatus(FString questID)
{
	if (xQuests[questID].iCurrentModule == xQuests[questID].xModules.Num())
	{
		QuestCompleted();
		xQuests[questID].eStatus = EQuestStatus::E_COMPLETED_QUEST;
		AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
		gamemode->xQuestUnlockStorageManager->_sCompletedQuestList.Add(questID);
	}
}

#pragma endregion

//----------------------------------------------------------------------------------
#pragma region Event Bus Advance 

void UAC_QuestLog::AdvanceExploreEvent(EventParameters params)
{
	int intZone = params[0]->Getter<int>();
	EQuestZones zone = static_cast<EQuestZones>(intZone);
	AdvanceExploreModule(zone);
}

void UAC_QuestLog::AdvanceInteractEvent(EventParameters params)
{
	int npcNameInt = params[0]->Getter<int>();
	FString questID = params[1]->Getter<FString>();
	ENpcNames npcName = static_cast<ENpcNames>(npcNameInt);
	int moduleIndex = params[2]->Getter<int>();
	AdvanceDialogueModule(npcName, questID, moduleIndex);
}

void UAC_QuestLog::AdvanceCollectEvent(EventParameters params)
{
	FString itemID = params[0]->Getter<FString>();
	int quantity = params[1]->Getter<int>();
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	UBaseItem* item = gamemode->GetFishFromDT(itemID);
	AdvanceCollectModule(item, quantity);
}


#pragma endregion


