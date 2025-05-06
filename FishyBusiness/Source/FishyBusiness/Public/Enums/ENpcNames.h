// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class ENpcNames : uint8
{
	E_QUEST_KEEPER = 0	UMETA(DisplayName = "Quest Keeper"),
	E_SHOPKEEPER = 1    UMETA(DisplayName = "Shopkeeper"),
	E_ENGINEER = 2      UMETA(DisplayName = "Engineer"),
	E_ARCHIVIST = 3     UMETA(DisplayName = "Archivist"),
	E_CARPENTER = 4     UMETA(DisplayName = "Carpenter"),
};
