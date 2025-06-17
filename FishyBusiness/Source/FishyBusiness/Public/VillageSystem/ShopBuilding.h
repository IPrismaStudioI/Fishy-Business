// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SellingSystem/SellComponent.h"
#include "VillageSystem/BuildingBase.h"
#include "ShopBuilding.generated.h"

/**
 * 
 */
UCLASS()
class FISHYBUSINESS_API AShopBuilding : public ABuildingBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
	USellComponent* _xSellComponent;
	
public:	
	// Sets default values for this actor's properties
	AShopBuilding();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
