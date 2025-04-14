// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "E_QuestRewardType.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EQuestRewardType : uint8
{
	ITEM_REWARD				UMETA(DisplayName = "ITEM_REWARD"),
	NEW_QUEST_REWARD		UMETA(DisplayName = "NEW_QUEST_REWARD"),
	UPGRADE_REWARD			UMETA(DisplayName = "UPGRADE_REWARD"),
	COMPENDIO_REWARD		UMETA(DisplayName = "COMPENDIO_REWARD"),
	DIALOGUE_REWARD			UMETA(DisplayName = "DIALOGUE_REWARD"),
	RESTORATION_REWARD		UMETA(DisplayName = "RESTORATION_REWARD")
};

