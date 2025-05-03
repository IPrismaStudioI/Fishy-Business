// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DIalogueSystem/DialogueTriggers/ButtonDialogueTriggerBase.h"
#include "ButtonDialogueTriggerAdvance.generated.h"

/**
 * 
 */
UCLASS()
class FISHYBUSINESS_API UButtonDialogueTriggerAdvance : public UButtonDialogueTriggerBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
	FString _sQuestID;
	UPROPERTY(EditAnywhere)
	ENpcNames _eName;
	UPROPERTY(EditAnywhere)
	int _iModuleIndex;

public:
	UButtonDialogueTriggerAdvance();

	UFUNCTION()
	void AdvanceQuest();

	UFUNCTION(BlueprintCallable)
	void CheckIfVisible();
};
