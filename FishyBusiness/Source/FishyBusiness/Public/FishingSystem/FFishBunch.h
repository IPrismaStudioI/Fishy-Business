// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FFishInfo.h"
#include "UObject/NoExportTypes.h"
#include "FFishBunch.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FISHYBUSINESS_API FFishBunch
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TArray<FFishInfo> aFishInfos;
	
};
