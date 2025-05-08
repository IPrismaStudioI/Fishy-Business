// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "QuestSystem/E_ModuleType.h"
#include "DA_QuestModuleBase.generated.h"

/**
 * 
 */
UCLASS()
class FISHYBUSINESS_API UDA_QuestModuleBase : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY()
	EPlayerModuleType eModuleType;
	UPROPERTY(EditAnywhere)
	FString sDescription;
};
