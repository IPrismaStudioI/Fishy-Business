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
	//gamemode->GetQuestFromDT(questID);
	//FQuestRow* questRow = gamemode->xQuestDataManager->GetQuestNameFromDT(questID);
	//FPlayerQuest playerQuest; //= FPlayerQuest(questRow->xModuleList, 0, EQuestStatus::E_ACTIVE_QUEST);
	if (xQuests.Find(questID) == nullptr)
	{
		xQuests.Add(questID, FPlayerQuest(gamemode->xQuestDataManager->GetQuestModuleListFromDT(questID)));
	}
}
//----------------------------------------------------------------------------------
#pragma region Advance

void UAC_QuestLog::AdvanceExploreModule(EQuestZones zone)
{
	FPlayerQuest quest = xQuests[FindQuestFromExplore(zone)];
}

void UAC_QuestLog::AdvanceDialogueModule(ENpcNames npcName)
{
	FPlayerQuest quest = xQuests[FindQuestFromDialogue(npcName)];
}

void UAC_QuestLog::AdvanceCollectModule(UBaseItem* item, int quantity)
{
	FPlayerQuest quest = xQuests[FindQuestFromCollect(item)];
}

#pragma endregion

//----------------------------------------------------------------------------------
#pragma region Check Modules 

void UAC_QuestLog::CheckNextModule()
{
}

void UAC_QuestLog::CheckQuestStatus()
{
}

#pragma endregion

//----------------------------------------------------------------------------------
#pragma region Find Quest 

FString UAC_QuestLog::FindQuestFromExplore(EQuestZones zone)
{
	for (auto Quest : xQuests)
	{
		for (auto Module : Quest.Value.xModules)
		{
			if (Module->eModuleType == EPlayerModuleType::E_EXPLORE_MODULE)
			{
				return Quest.Key;
			}
			
		}
	}
}

FString UAC_QuestLog::FindQuestFromDialogue(ENpcNames npcName)
{
	for (auto Quest : xQuests)
	{
		for (auto Module : Quest.Value.xModules)
		{
			if (Module->eModuleType == EPlayerModuleType::E_INTERACT_MODULE)
			{
				return Quest.Key;
			}
			
		}
	}
}

FString UAC_QuestLog::FindQuestFromCollect(UBaseItem* item)
{
	for (auto Quest : xQuests)
	{
		for (auto Module : Quest.Value.xModules)
		{
			if (Module->eModuleType == EPlayerModuleType::E_COLLECT_MODULE)
			{
				return Quest.Key;
			}
			
		}
	}
}

#pragma endregion


