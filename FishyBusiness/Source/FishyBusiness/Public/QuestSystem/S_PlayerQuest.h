// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "E_QuestStatus.h"
#include "QuestData/Modules/DA_QuestModuleBase.h"
#include "S_PlayerQuest.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FISHYBUSINESS_API FPlayerQuest
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TArray<UDA_QuestModuleBase*> xModules;
	TArray<int> iCurrentAmountModules;
	TArray<int> iTotalAmountModules;
	UPROPERTY(EditAnywhere)
	int iCurrentModule;
	UPROPERTY(EditAnywhere)
	EQuestStatus eStatus;

	FPlayerQuest()
		: xModules(), iCurrentModule(0), eStatus(EQuestStatus::E_ACTIVE_QUEST) {}

	explicit FPlayerQuest(const TArray<UDA_QuestModuleBase*>& modules)
		: xModules(modules), iCurrentModule(0), eStatus(EQuestStatus::E_ACTIVE_QUEST) {}
};
