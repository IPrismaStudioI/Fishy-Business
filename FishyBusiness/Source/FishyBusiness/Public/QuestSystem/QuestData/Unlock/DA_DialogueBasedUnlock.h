// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enums/ENpcNames.h"
#include "FishyBusiness/Public/QuestSystem/QuestData/Unlock/DA_QuestUnlockBase.h"
#include "DA_DialogueBasedUnlock.generated.h"

/**
 * 
 */
UCLASS()
class FISHYBUSINESS_API UDA_DialogueBasedUnlock : public UDA_QuestUnlockBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	ENpcNames eNpcName;
};
