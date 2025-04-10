// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VillageSystem/Widget/BuildingWidgetBase.h"
#include "QuestBuildingWidget.generated.h"

/**
 * 
 */
UCLASS()
class FISHYBUSINESS_API UQuestBuildingWidget : public UBuildingWidgetBase
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;
};
