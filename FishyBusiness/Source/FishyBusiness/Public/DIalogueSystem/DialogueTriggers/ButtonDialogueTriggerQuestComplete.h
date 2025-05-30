// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DIalogueSystem/DialogueTriggers/ButtonDialogueTriggerBase.h"
#include "ButtonDialogueTriggerQuestComplete.generated.h"

/**
 * 
 */
UCLASS()
class FISHYBUSINESS_API UButtonDialogueTriggerQuestComplete : public UButtonDialogueTriggerBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
	FString _sQuestID;

	bool _bOneTime = true;

public:
	void CheckIfVisible() override;
};
