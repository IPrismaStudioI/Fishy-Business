// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestSystem/AC_QuestLog.h"

#include "FishyBusiness/FishyBusinessGameModeBase.h"
#include "QuestSystem/QuestData/QuestRow.h"

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

	// ...
	
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

//----------------------------------------------------------------------------------
#pragma region Advance

// void UAC_QuestLog::AdvanceExploreModule(EQuestZones zone)
// {
// 	FString questID = "null";
// 	for (auto Quest : xQuests)
// 	{
// 		for (auto Module : Quest.Value.xModules)
// 		{
// 			if (Module->eModuleType == EPlayerModuleType::E_EXPLORE_MODULE)
// 			{
// 				if (Module->eQuestZone == zone)
// 				{
// 					questID = Quest.Key;
// 				}
// 			}
// 		}
// 	}
// 	
// 	//FPlayerQuest quest = xQuests[FindQuestFromExplore(zone)];
// 	//quest.iCurrentModule++;
//
// 	if (questID != "null")
// 	{
// 		xQuests[questID].iCurrentModule++;
// 		CheckQuestStatus(xQuests[questID]);
// 		if (xQuests[questID].eStatus == EQuestStatus::E_ACTIVE_QUEST)
// 		{
// 			CheckNextModule();
// 		}
// 	}
// }
//
// void UAC_QuestLog::AdvanceDialogueModule(ENpcNames npcName)
// {
// 	FString questID = "null";
// 	for (auto Quest : xQuests)
// 	{
// 		for (auto Module : Quest.Value.xModules)
// 		{
// 			if (Module->eModuleType == EPlayerModuleType::E_INTERACT_MODULE)
// 			{
// 				if (Module->eNpcName == npcName)
// 				{
// 					questID = Quest.Key;
// 				}
// 			}
// 		}
// 	}
// 	
// 	//FPlayerQuest quest = xQuests[FindQuestFromDialogue(npcName)];
// 	//quest.iCurrentModule++;
// 	
// 	if (questID != "null")
// 	{
// 		xQuests[questID].iCurrentModule++;
// 		CheckQuestStatus(xQuests[questID]);
// 		if (xQuests[questID].eStatus == EQuestStatus::E_ACTIVE_QUEST)
// 		{
// 			CheckNextModule();
// 		}
// 	}
// }
//
// void UAC_QuestLog::AdvanceCollectModule(UBaseItem* item, int quantity)
// {
// 	FString questID = "null";
// 	for (auto Quest : xQuests)
// 	{
// 		for (auto Module : Quest.Value.xModules)
// 		{
// 			if (Module->eModuleType == EPlayerModuleType::E_COLLECT_MODULE)
// 			{
// 				if (Module->xItem == item && Module->iAmountOf == quantity)
// 				{
// 					questID = Quest.Key;
// 				}
// 			}
// 		}
// 	}
// 	
// 	//FPlayerQuest quest = xQuests[FindQuestFromCollect(item)];
// 	//quest.iCurrentModule++;
// 	
// 	if (questID != "null")
// 	{
// 		xQuests[questID].iCurrentModule++;
// 		CheckQuestStatus(xQuests[questID]);
// 		if (xQuests[questID].eStatus == EQuestStatus::E_ACTIVE_QUEST)
// 		{
// 			CheckNextModule();
// 		}
// 	}
// }

#pragma endregion

//----------------------------------------------------------------------------------
#pragma region Check Modules 

void UAC_QuestLog::CheckNextModule()
{
}

void UAC_QuestLog::CheckQuestStatus(FPlayerQuest quest)
{
	if (quest.iCurrentModule == quest.xModules.Num() -1)
	{
		quest.eStatus = EQuestStatus::E_COMPLETED_QUEST;
	}
}

#pragma endregion

//----------------------------------------------------------------------------------
#pragma region Find Quest 

// FString UAC_QuestLog::FindQuestFromExplore(EQuestZones zone)
// {
// 	for (auto Quest : xQuests)
// 	{
// 		for (auto Module : Quest.Value.xModules)
// 		{
// 			if (Module->eModuleType == EPlayerModuleType::E_EXPLORE_MODULE)
// 			{
// 				//if zone ==
// 				return Quest.Key;
// 			}
// 			
// 		}
// 	}
// }

// FString UAC_QuestLog::FindQuestFromDialogue(ENpcNames npcName)
// {
// 	for (auto Quest : xQuests)
// 	{
// 		for (auto Module : Quest.Value.xModules)
// 		{
// 			if (Module->eModuleType == EPlayerModuleType::E_INTERACT_MODULE)
// 			{
// 				//if zone ==
// 				return Quest.Key;
// 			}
// 			
// 		}
// 	}
// }

// FString UAC_QuestLog::FindQuestFromCollect(UBaseItem* item)
// {
// 	for (auto Quest : xQuests)
// 	{
// 		for (auto Module : Quest.Value.xModules)
// 		{
// 			if (Module->eModuleType == EPlayerModuleType::E_COLLECT_MODULE)
// 			{
// 				//if zone ==
// 				return Quest.Key;
// 			}
// 			
// 		}
// 	}
// }

#pragma endregion


