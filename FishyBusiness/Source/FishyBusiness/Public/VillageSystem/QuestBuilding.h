// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "QuestSystem/QuestReward.h"
#include "QuestSystem/QuestBoard/QuestBoard.h"
#include "VillageSystem/BuildingBase.h"
#include "QuestBuilding.generated.h"

/**
 * 
 */
UCLASS()
class FISHYBUSINESS_API AQuestBuilding : public ABuildingBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
	UQuestBoard* _xQuestBoard;
	UPROPERTY(EditAnywhere)
	UQuestReward* _xQuestReward;

public:	
	// Sets default values for this actor's properties
	AQuestBuilding();
};
