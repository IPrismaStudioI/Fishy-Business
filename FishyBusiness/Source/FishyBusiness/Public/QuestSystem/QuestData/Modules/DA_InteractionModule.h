// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enums/ENpcNames.h"
#include "QuestSystem/QuestData/Modules/DA_QuestModuleBase.h"
#include "DA_InteractionModule.generated.h"

/**
 * 
 */
UCLASS()
class FISHYBUSINESS_API UDA_InteractionModule : public UDA_QuestModuleBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	ENpcNames eNpcName;
};
