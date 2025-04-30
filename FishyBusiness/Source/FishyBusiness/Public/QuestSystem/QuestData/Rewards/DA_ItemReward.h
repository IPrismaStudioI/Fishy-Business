// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataSystem/ItemData/BaseItem.h"
#include "QuestSystem/QuestData/Rewards/DA_QuestRewardBase.h"
#include "DA_ItemReward.generated.h"

/**
 * 
 */
UCLASS()
class FISHYBUSINESS_API UDA_ItemReward : public UDA_QuestRewardBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	UBaseItem* xItem;
};
