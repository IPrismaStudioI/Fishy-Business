// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Dialogue.h"
#include "Engine/DataAsset.h"
#include "DA_Dialogue.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class FISHYBUSINESS_API UDA_Dialogue : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FDialogue Dialogue;
	// UPROPERTY(EditAnywhere, BlueprintReadWrite)
	// int Value;
	// UPROPERTY(EditAnywhere, BlueprintReadWrite)
	// FString Name;

public:
	UDA_Dialogue();
};

