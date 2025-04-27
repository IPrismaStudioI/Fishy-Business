// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestSystem/QuestDataManager.h"

#include "FishyBusiness/FishyBusinessGameModeBase.h"
#include "QuestSystem/QuestData/QuestRow.h"

UQuestDataManager::UQuestDataManager()
{
}

void UQuestDataManager::BeginPlay()
{
	Super::BeginPlay();
}

FString UQuestDataManager::GetQuestNameFromDT(FString id)
{
	FQuestRow* row = xFishyBusinessGameMode->xDataTableQuest->FindRow<FQuestRow>(FName(id), "");
	return row->sQuestName;
}

FString UQuestDataManager::GetQuestDescriptionFromDT(FString id)
{
	FQuestRow* row = xFishyBusinessGameMode->xDataTableQuest->FindRow<FQuestRow>(FName(id), "");
	return row->sQuestDescription;
}

UDA_QuestUnlockBase* UQuestDataManager::GetQuestUnlockFromDT(FString id)
{
	FQuestRow* row = xFishyBusinessGameMode->xDataTableQuest->FindRow<FQuestRow>(FName(id), "");
	return row->xUnlock;
}

EQuestUnlockType UQuestDataManager::GetQuestUnlockTypeFromDT(FString id)
{
	FQuestRow* row = xFishyBusinessGameMode->xDataTableQuest->FindRow<FQuestRow>(FName(id), "");
	return row->eUnlockType;
}

TArray<UDA_QuestModuleBase*> UQuestDataManager::GetQuestModuleListFromDT(FString id)
{
	FQuestRow* row = xFishyBusinessGameMode->xDataTableQuest->FindRow<FQuestRow>(FName(id), "");
	return row->xModuleList;
}

UDA_QuestRewardBase* UQuestDataManager::GetQuestRewardFromDT(FString id)
{
	FQuestRow* row = xFishyBusinessGameMode->xDataTableQuest->FindRow<FQuestRow>(FName(id), "");
	return row->xReward;
}

EQuestRewardType UQuestDataManager::GetQuestRewardTypeFromDT(FString id)
{
	FQuestRow* row = xFishyBusinessGameMode->xDataTableQuest->FindRow<FQuestRow>(FName(id), "");
	return row->eRewardType;
}

UTexture2D* UQuestDataManager::GetQuestIconFromDT(FString id)
{
	FQuestRow* row = xFishyBusinessGameMode->xDataTableQuest->FindRow<FQuestRow>(FName(id), "");
	return row->xQuestIcon;
}
