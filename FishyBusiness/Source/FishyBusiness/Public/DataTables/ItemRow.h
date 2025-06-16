// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataSystem/ItemData/BaseItem.h"
#include "UObject/NoExportTypes.h"
#include "ItemRow.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FItemRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UBaseItem* xItem;
};
