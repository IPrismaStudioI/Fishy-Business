// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "E_QuestStatus.h"
#include "S_QuestModule.h"
#include "S_PlayerQuest.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FISHYBUSINESS_API FPlayerQuest
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TArray<FQuestModule> xModules;
	UPROPERTY(EditAnywhere)
	int iCurrentModule;
	UPROPERTY(EditAnywhere)
	EQuestStatus eStatus;
};
