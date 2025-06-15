// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataSystem/ItemData/BaseItem.h"
#include "QuestSystem/QuestData/Modules/DA_QuestModuleBase.h"
#include "DA_FishCollectionModule.generated.h"

/**
 * 
 */
UCLASS()
class FISHYBUSINESS_API UDA_FishCollectionModule : public UDA_QuestModuleBase
{
	GENERATED_BODY()

public:	
	UPROPERTY(EditAnywhere)
	TMap<FString, int> xFishMap;
};
