// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class ENpcNames : uint8
{
	E_QUEST_KEEPER	UMETA(DisplayName = "Quest Keeper"),
	E_SHOPKEEPER    UMETA(DisplayName = "Shopkeeper"),
	E_ENGINEER      UMETA(DisplayName = "Engineer"),
	E_ARCHIVIST     UMETA(DisplayName = "Archivist"),
	E_CARPENTER     UMETA(DisplayName = "Carpenter"),
};
