// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enums/EItemType.h"
#include "UObject/NoExportTypes.h"
#include "SCollectModuleValues.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FISHYBUSINESS_API FCollectModuleValues
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	int iAmount;

	UPROPERTY(EditAnywhere)
	EItemType eItemType;
};
