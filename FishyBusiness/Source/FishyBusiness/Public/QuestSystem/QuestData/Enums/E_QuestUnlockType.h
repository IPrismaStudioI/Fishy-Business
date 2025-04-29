// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "E_QuestUnlockType.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EQuestUnlockType : uint8
{
	None = 0,
	QUEST_BASED		UMETA(DisplayName = "QUEST_BASED"),
	DISCOVERY_BASED		UMETA(DisplayName = "DISCOVERY_BASED"),
	DIALOGUE_BASED		UMETA(DisplayName = "DIALOGUE_BASED")
};