// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VillageSystem/BuildingBase.h"
#include "UpgradeBuilding.generated.h"

/**
 * 
 */
UCLASS()
class FISHYBUSINESS_API AUpgradeBuilding : public ABuildingBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
	TArray<FString> xUpgradeIDList;
};
