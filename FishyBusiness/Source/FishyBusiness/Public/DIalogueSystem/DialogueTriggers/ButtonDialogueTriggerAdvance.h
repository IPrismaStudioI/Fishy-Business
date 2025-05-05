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

	///<summary>
	///triggers the event to advance the specified quest (quest ID, npc name)
	///</summary>
	UFUNCTION()
	void AdvanceQuest();

	///<summary>
	///Checks if the associated quest current module is the same as _iModuleIndex, if it is, the button will be visible, if not it will be collapsed
	///</summary>
	UFUNCTION(BlueprintCallable)
	void CheckIfVisible();
};
