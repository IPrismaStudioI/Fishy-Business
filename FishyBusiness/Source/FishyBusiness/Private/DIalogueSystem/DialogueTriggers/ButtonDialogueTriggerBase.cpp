// Fill out your copyright notice in the Description page of Project Settings.


#include "DIalogueSystem/DialogueTriggers/ButtonDialogueTriggerBase.h"

#include "DataTables/DialogueRow.h"
#include "DIalogueSystem/DA_Dialogue.h"
#include "FishyBusiness/FishyBusinessGameModeBase.h"

struct FDialogueRow;

UDA_Dialogue* UButtonDialogueTriggerBase::GetDialogueFromDT(FString id, AFishyBusinessGameModeBase* gamemode)
{
	FDialogueRow* row = gamemode->xDataTableDialogues->FindRow<FDialogueRow>(FName(id), "");
	if (row != NULL)
		return row->xDialogue;
	else
		return NULL;
}

UButtonDialogueTriggerBase::UButtonDialogueTriggerBase()
{
	this->OnClicked.AddDynamic(this, &UButtonDialogueTriggerBase::StartDialogue);
}

void UButtonDialogueTriggerBase::StartDialogue()
{
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();

	if (GetDialogueFromDT(_sDialogueID, gamemode))
		gamemode->xDialogueElaborator->StartDialogue(GetDialogueFromDT(_sDialogueID, gamemode)->Dialogue);
	else
		UE_LOG(LogTemp, Error, TEXT("Missing dialogue"));
}