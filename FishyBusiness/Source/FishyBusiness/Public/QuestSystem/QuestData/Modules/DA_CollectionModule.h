// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataSystem/ItemData/BaseItem.h"
#include "QuestSystem/SCollectModuleValues.h"
#include "QuestSystem/QuestData/Modules/DA_QuestModuleBase.h"
#include "DA_CollectionModule.generated.h"

/**
 * 
 */
UCLASS()
class FISHYBUSINESS_API UDA_CollectionModule : public UDA_QuestModuleBase
{
	GENERATED_BODY()

public:	
	UPROPERTY(EditAnywhere)
	TMap<FString, FCollectModuleValues> xItems;
};
