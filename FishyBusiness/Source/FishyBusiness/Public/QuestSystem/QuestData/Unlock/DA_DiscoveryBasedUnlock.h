// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FishyBusiness/Public/QuestSystem/QuestData/Enums/E_QuestZones.h"
#include "FishyBusiness/Public/QuestSystem/QuestData/Unlock/DA_QuestUnlockBase.h"
#include "DA_DiscoveryBasedUnlock.generated.h"

/**
 * 
 */
UCLASS()
class FISHYBUSINESS_API UDA_DiscoveryBasedUnlock : public UDA_QuestUnlockBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	EQuestZones eZone;
};
