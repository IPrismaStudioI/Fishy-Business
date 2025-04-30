// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "E_QuestZones.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EQuestZones : uint8
{
	ZONE_1		UMETA(DisplayName = "ZONE_1"),
	ZONE_2		UMETA(DisplayName = "ZONE_2"),
	ZONE_3		UMETA(DisplayName = "ZONE_3"),
	ZONE_4		UMETA(DisplayName = "ZONE_4"),
	ZONE_5		UMETA(DisplayName = "ZONE_5")
};