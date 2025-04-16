// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DataSystem/FishData/Fish.h"
#include "FishingReward.generated.h"

/**
 * 
 */
UCLASS()
class FISHYBUSINESS_API UFishingReward : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
	FString sFishID;
	UPROPERTY(BlueprintReadWrite)
	UFish* xFish;
	UPROPERTY(BlueprintReadWrite)
	AFishingSpot* xFishingSpot;
};
