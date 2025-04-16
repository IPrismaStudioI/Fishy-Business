// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataSystem/FishData/Fish.h"
#include "UObject/NoExportTypes.h"
#include "FishRow.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FFishRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UFish* xFish; 
};
