// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FFishInfo.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FISHYBUSINESS_API FFishInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	float fPrice;
	UPROPERTY(EditAnywhere)
	float fSize;
};
