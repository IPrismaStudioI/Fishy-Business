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

private:
	UDA_Dialogue* GetDialogueFromDT(FString id, AFishyBusinessGameModeBase* gamemode);
	
public:
	UButtonDialogueTriggerBase();
	UFUNCTION()
	void StartDialogue();
};
