// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataSystem/FishData/Fish.h"
#include "QuestSystem/QuestData/Rewards/DA_QuestRewardBase.h"
#include "DA_CompendioReward.generated.h"

/**
 * 
 */
UCLASS()
class FISHYBUSINESS_API UDA_CompendioReward : public UDA_QuestRewardBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	UFish* xFish;
};
