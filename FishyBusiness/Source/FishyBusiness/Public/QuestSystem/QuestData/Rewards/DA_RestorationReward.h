// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enums/EBuildings.h"
#include "QuestSystem/QuestData/Rewards/DA_QuestRewardBase.h"
#include "QuestSystem/RestorationSystem/E_BuildingStatus.h"
#include "DA_RestorationReward.generated.h"

/**
 * 
 */
UCLASS()
class FISHYBUSINESS_API UDA_RestorationReward : public UDA_QuestRewardBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	EBuildings eBuilding;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EBuildingStatus eStatus;
};
