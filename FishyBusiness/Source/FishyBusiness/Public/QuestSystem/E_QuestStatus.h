// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "E_QuestStatus.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EQuestStatus : uint8
{
	E_ACTIVE_QUEST,
	E_COMPLETED_QUEST,
};
