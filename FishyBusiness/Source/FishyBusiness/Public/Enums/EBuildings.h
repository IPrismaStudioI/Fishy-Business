// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EBuildings : uint8
{
	E_LIGHTHOUSE    UMETA(DisplayName = "Lighthouse"),
	E_FISHSHOP		UMETA(DisplayName = "Fish Shop"),
	E_WORKSHOP      UMETA(DisplayName = "Workshop"),
	E_ARCHIVE		UMETA(DisplayName = "Archive"),
	E_CARPENTRY     UMETA(DisplayName = "Carpentry"),
};
