// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "Engine/DataAsset.h"
#include "InputDataConfig.generated.h"

/**
 * 
 */
UCLASS()
class FISHYBUSINESS_API UInputDataConfig : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* START_FISHING_INPUT;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* OPEN_COMPENDIO_INPUT;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* CLOSE_COMPENDIO_INPUT;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* NEXT_COMPENDIO_PAGE_INPUT;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* PREV_COMPENDIO_PAGE_INPUT;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* CLOSE_VILLAGE_INPUT;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* MOVE_FORWARD_INPUT;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* MOVE_RIGHT_INPUT;
};
