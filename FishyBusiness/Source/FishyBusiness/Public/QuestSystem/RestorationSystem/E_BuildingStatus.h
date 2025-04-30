// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "E_BuildingStatus.generated.h"

UENUM(BlueprintType)
enum class EBuildingStatus : uint8
{
	STATUS_1		UMETA(DisplayName = "STATUS_1"),
	STATUS_2		UMETA(DisplayName = "STATUS_2"),
	STATUS_3		UMETA(DisplayName = "STATUS_3")
};