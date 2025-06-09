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
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	FQuestRow* row = gamemode->xDataTableQuest->FindRow<FQuestRow>(FName(id), "");
	if (!row)
	{
		UE_LOG(LogCore, Error, TEXT("Quest row not found"));
		return "";
	}
	return row->sQuestName;
}

FString UQuestDataManager::GetQuestDescriptionFromDT(FString id)
{
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	FQuestRow* row = gamemode->xDataTableQuest->FindRow<FQuestRow>(FName(id), "");
	if (!row)
	{
		UE_LOG(LogCore, Error, TEXT("Quest row not found"));
		return "";
	}
	return row->sQuestDescription;
}

UDA_QuestUnlockBase* UQuestDataManager::GetQuestUnlockFromDT(FString id)
{
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	FQuestRow* row = gamemode->xDataTableQuest->FindRow<FQuestRow>(FName(id), "");
	if (!row)
	{
		UE_LOG(LogCore, Error, TEXT("Quest row not found"));
		return nullptr;
	}
	return row->xUnlock;
}

EQuestUnlockType UQuestDataManager::GetQuestUnlockTypeFromDT(FString id)
{
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	FQuestRow* row = gamemode->xDataTableQuest->FindRow<FQuestRow>(FName(id), "");
	if (!row)
	{
		UE_LOG(LogCore, Error, TEXT("Quest row not found"));
		return EQuestUnlockType::None;
	}
	return row->eUnlockType;
}

TArray<UDA_QuestModuleBase*> UQuestDataManager::GetQuestModuleListFromDT(FString id)
{
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	FQuestRow* row = gamemode->xDataTableQuest->FindRow<FQuestRow>(FName(id), "");
	if (!row)
	{
		UE_LOG(LogCore, Error, TEXT("Quest row not found"));
		return TArray<UDA_QuestModuleBase*>();
	}
	return row->xModuleList;
}

TMap<EQuestRewardType, UDA_QuestRewardBase*> UQuestDataManager::GetQuestRewardFromDT(FString id)
{
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	FQuestRow* row = gamemode->xDataTableQuest->FindRow<FQuestRow>(FName(id), "");
	if (!row)
	{
		UE_LOG(LogCore, Error, TEXT("Quest row not found"));
		return {};
	}
	return row->xReward;
}

EQuestRewardType UQuestDataManager::GetQuestRewardTypeFromDT(FString id)
{
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	FQuestRow* row = gamemode->xDataTableQuest->FindRow<FQuestRow>(FName(id), "");
	if (!row)
	{
		UE_LOG(LogCore, Error, TEXT("Quest row not found"));
		return EQuestRewardType::None;
	}
	return row->eRewardType;
}

UTexture2D* UQuestDataManager::GetQuestIconFromDT(FString id)
{
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	FQuestRow* row = gamemode->xDataTableQuest->FindRow<FQuestRow>(FName(id), "");
	if (!row)
	{
		UE_LOG(LogCore, Error, TEXT("Quest row not found"));
		return nullptr;
	}
	return row->xQuestIcon;
}

FString UQuestDataManager::GetQuestGiverFromDT(FString id)
{
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	FQuestRow* row = gamemode->xDataTableQuest->FindRow<FQuestRow>(FName(id), "");
	if (!row)
	{
		UE_LOG(LogCore, Error, TEXT("Quest row not found"));
		return "";
	}
	return row->sQuestGiver;
}
