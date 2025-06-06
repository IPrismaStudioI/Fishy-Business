// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "QuestSystem/QuestData/Rewards/DA_QuestRewardBase.h"
#include "DA_NewQuestReward.generated.h"

/**
 * 
 */
UCLASS()
class FISHYBUSINESS_API UDA_NewQuestReward : public UDA_QuestRewardBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	FString sQuestID;
};
