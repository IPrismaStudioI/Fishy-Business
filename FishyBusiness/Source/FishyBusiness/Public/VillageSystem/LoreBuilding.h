// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VillageSystem/BuildingBase.h"
#include "LoreBuilding.generated.h"

/**
 * 
 */
UCLASS()
class FISHYBUSINESS_API ALoreBuilding : public ABuildingBase
{
	GENERATED_BODY()
		
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
