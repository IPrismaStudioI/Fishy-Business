// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Rarity.h"
#include "RarityColor.h"
#include "DataSystem/ItemData/SellableItem.h"
#include "FishingSystem/FishBehaviour.h"
#include "Fish.generated.h"

/**
 * 
 */
UCLASS()
class FISHYBUSINESS_API UFish : public USellableItem
{
	GENERATED_BODY()

	public:
	UPROPERTY(EditAnywhere)
	FString sFishID;
	UPROPERTY(EditAnywhere)
	float fBaseSize;
	UPROPERTY(EditAnywhere)
	float fSizeCorrector;
	UPROPERTY(EditAnywhere)
	float fBasePrice;
	UPROPERTY(EditAnywhere)
	float fPriceCorrector;
	UPROPERTY(EditAnywhere)
	ERarity eRarity;
	UPROPERTY(EditAnywhere)
	ERarityColor eRarityColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVariables")
	TArray<UFishBehaviour*> xFishBehaviour;
};
