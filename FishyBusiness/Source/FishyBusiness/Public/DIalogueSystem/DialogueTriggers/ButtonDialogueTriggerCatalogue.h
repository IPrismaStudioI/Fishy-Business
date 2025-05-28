// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DIalogueSystem/DialogueTriggers/ButtonDialogueTriggerBase.h"
#include "ButtonDialogueTriggerCatalogue.generated.h"

/**
 * 
 */
UCLASS()
class FISHYBUSINESS_API UButtonDialogueTriggerCatalogue : public UButtonDialogueTriggerBase
{
	GENERATED_BODY()
	
private:
	UPROPERTY(EditAnywhere)
	FString _sFishID;

public:
	UButtonDialogueTriggerCatalogue();

	///<summary>
	///Checks if the associated fish is catalogued, if it is, the button will be visible, if not it will be collapsed
	///</summary>
	void CheckIfVisible();
};
