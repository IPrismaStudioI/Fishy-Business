// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "DIalogueSystem/DA_Dialogue.h"
#include "FishyBusiness/FishyBusinessGameModeBase.h"
#include "ButtonDialogueTriggerBase.generated.h"

UCLASS()
class FISHYBUSINESS_API UButtonDialogueTriggerBase : public UButton
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
	FString _sDialogueID;

public:
	void Set_SDialogueID(const FString& SDialogueID)
	{
		_sDialogueID = SDialogueID;
	}
	
public:
	UButtonDialogueTriggerBase();

	///<summary>Initiates a dialogue using the dialogue ID stored in _sDialogueID.</summary>
	UFUNCTION()
	void StartDialogue();

	///<summary>
	///Checks if the associated quest current module is the same as _iModuleIndex, if it is, the button will be visible, if not it will be collapsed
	///</summary>
	virtual void CheckIfVisible();
};
