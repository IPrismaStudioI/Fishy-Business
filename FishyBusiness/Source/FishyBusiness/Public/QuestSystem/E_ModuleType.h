// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "E_ModuleType.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EPlayerModuleType : uint8
{
	E_INTERACT_MODULE,
	E_COLLECT_MODULE,
	E_EXPLORE_MODULE,
	
};
