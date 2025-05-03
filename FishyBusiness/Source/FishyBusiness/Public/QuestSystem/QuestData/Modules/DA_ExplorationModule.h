// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "QuestSystem/QuestData/Modules/DA_QuestModuleBase.h"
#include "FishyBusiness/Public/QuestSystem/QuestData/Enums/E_QuestZones.h"
#include "DA_ExplorationModule.generated.h"

/**
 * 
 */

UCLASS()
class FISHYBUSINESS_API UDA_ExplorationModule : public UDA_QuestModuleBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EQuestZones QuestZones;
};

