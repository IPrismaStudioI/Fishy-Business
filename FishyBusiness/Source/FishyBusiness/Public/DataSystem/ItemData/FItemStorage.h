// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseItem.h"
#include "FItemStorage.generated.h"

/**
 * 
 */
USTRUCT()
struct FISHYBUSINESS_API FItemStorage : public FTableRowBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	FString sItemID;
	
	UPROPERTY(EditAnywhere)
	UBaseItem* xItem;
};
