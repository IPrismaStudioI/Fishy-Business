// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Rarity.h"
#include "RarityColor.h"
#include "DataSystem/ItemData/SellableItem.h"
#include "Enums/Biomes.h"
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
	float fBaseSize;
	UPROPERTY(EditAnywhere)
	float fSizeCorrector;
	UPROPERTY(EditAnywhere)
	float fBasePrice;
	UPROPERTY(EditAnywhere)
	float fPriceCorrector;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ERarity eRarity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ERarityColor eRarityColor;	

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString sFishName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString sFishSName;
	
	UPROPERTY(EditAnywhere)
	FString sFishDescription;
	
	UPROPERTY(EditAnywhere)
	EBiomes eLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* xFishingSpotSprite;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* xFishImage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* xFishCatalogueImage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* xFishNotCatalogueImage;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyVariables")
	TArray<UFishBehaviour*> xFishBehaviour;
};
