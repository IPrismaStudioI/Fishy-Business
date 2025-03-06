// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Fish.h"
#include "FFishStorage.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FISHYBUSINESS_API FFishStorage : public FTableRowBase
{
	GENERATED_BODY()
	public:
	UPROPERTY(EditAnywhere)
	FString sFishID;
	UPROPERTY(EditAnywhere)
	UFish* xFish;
};
