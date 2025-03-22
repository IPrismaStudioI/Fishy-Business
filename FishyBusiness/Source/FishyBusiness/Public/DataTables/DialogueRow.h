// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DIalogueSystem/DA_Dialogue.h"
#include "UObject/NoExportTypes.h"
#include "DialogueRow.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FDialogueRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UDA_Dialogue* xDialogue; 
};
