// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataSystem/ItemData/BaseItem.h"
#include "Enums/ENpcNames.h"
#include "QuestData/Enums/E_QuestZones.h"
#include "E_ModuleType.h"
#include "S_QuestModule.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FISHYBUSINESS_API FQuestModule
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FString sDescription;
	UPROPERTY(EditAnywhere)
	int iCurrentAmount;
	UPROPERTY(EditAnywhere)
	int iAmountOf;
	UPROPERTY(EditAnywhere)
	ENpcNames eNpcName;
	UPROPERTY(EditAnywhere)
	EQuestZones eQuestZone;
	UPROPERTY(EditAnywhere)
	UBaseItem* xItem;
	UPROPERTY(EditAnywhere)
	EPlayerModuleType eModuleType;
};
