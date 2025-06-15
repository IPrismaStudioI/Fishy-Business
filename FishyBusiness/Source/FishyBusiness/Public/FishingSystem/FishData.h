// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FishData.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FISHYBUSINESS_API FFishData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	FString sFishID;
	UPROPERTY(BlueprintReadWrite)
	float fFishPrice;
	UPROPERTY(BlueprintReadWrite)
	float fFishSize;

	FFishData()
		: sFishID(TEXT("")), fFishPrice(0.0f), fFishSize(0.0f)
	{}
	
	FFishData(const FString& SFishID, float FFishPrice, float FFishSize)
		: sFishID(SFishID),
		  fFishPrice(FFishPrice),
		  fFishSize(FFishSize)
	{	}
};

USTRUCT(BlueprintType)
struct FISHYBUSINESS_API FFishDataRecord
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	float fFishPrice;
	UPROPERTY(BlueprintReadWrite)
	float fFishSize;

	FFishDataRecord()
		:fFishPrice(0.0f), fFishSize(0.0f)
	{}
	
	FFishDataRecord(float FFishPrice, float FFishSize)
		: fFishPrice(FFishPrice),
		  fFishSize(FFishSize)
	{	}
};