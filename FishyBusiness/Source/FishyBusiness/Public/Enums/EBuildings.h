// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EBuildings : uint8
{
	E_LIGHTHOUSE = 0    UMETA(DisplayName = "Lighthouse"),
	E_FISHSHOP = 1		UMETA(DisplayName = "Fish Shop"),
	E_WORKSHOP = 2      UMETA(DisplayName = "Workshop"),
	E_ARCHIVE = 3		UMETA(DisplayName = "Archive"),
	E_CARPENTRY = 4     UMETA(DisplayName = "Carpentry"),
};
