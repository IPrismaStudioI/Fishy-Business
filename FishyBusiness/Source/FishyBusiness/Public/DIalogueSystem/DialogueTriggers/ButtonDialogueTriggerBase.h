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
	/// <summary>Return a UDA_Dialogue* from the dialogue DataTable using an ID.
	/// <para>
	/// @param id - The ID of the dialogue to look up.
	/// @param gamemode - A reference to the GameMode to access the DataTable.
	/// </para>
	/// @return A pointer to UDA_Dialogue if the dialogue is found, otherwise nullptr.
	/// </summary>
	UDA_Dialogue* GetDialogueFromDT(FString id, AFishyBusinessGameModeBase* gamemode);
	
public:
	UButtonDialogueTriggerBase();

	///<summary>Initiates a dialogue using the dialogue ID stored in _sDialogueID.</summary>
	UFUNCTION()
	void StartDialogue();
};
