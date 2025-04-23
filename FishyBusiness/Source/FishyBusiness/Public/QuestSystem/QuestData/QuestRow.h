// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enums/E_QuestRewardType.h"
#include "Enums/E_QuestUnlockType.h"
#include "Modules/DA_QuestModuleBase.h"
#include "QuestSystem/S_QuestModule.h"
#include "Rewards/DA_QuestRewardBase.h"
#include "Unlock/DA_QuestUnlockBase.h"
#include "UObject/NoExportTypes.h"
#include "QuestRow.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FISHYBUSINESS_API FQuestRow : public FTableRowBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString sQuestName;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString sQuestDescription;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UDA_QuestUnlockBase* xUnlock;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EQuestUnlockType eUnlockType;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UDA_QuestModuleBase*> xModuleList;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UDA_QuestRewardBase* xReward;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EQuestRewardType eRewardType;
};