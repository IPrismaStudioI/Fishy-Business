// Fill out your copyright notice in the Description page of Project Settings.


#include "DIalogueSystem/DialogueTriggers/ButtonDialogueTriggerBase.h"

#include "DataTables/DialogueRow.h"
#include "DIalogueSystem/DA_Dialogue.h"
#include "FishyBusiness/FishyBusinessGameModeBase.h"

struct FDialogueRow;

UDA_Dialogue* UButtonDialogueTriggerBase::GetDialogueFromDT(FString id, AFishyBusinessGameModeBase* gamemode)
{
	UDA_Dialogue* test = (UDA_Dialogue*)malloc(sizeof(UDA_Dialogue));
	FDialogueRow* row = gamemode->xDataTableDialogues->FindRow<FDialogueRow>(FName(id), "");
	return row->xDialogue;
}

UButtonDialogueTriggerBase::UButtonDialogueTriggerBase()
{
	this->OnClicked.AddDynamic(this, &UButtonDialogueTriggerBase::StartDialogue);
}

void UButtonDialogueTriggerBase::StartDialogue()
{
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	
	gamemode->xDialogueElaborator->StartDialogue(GetDialogueFromDT(_sDialogueID, gamemode)->Dialogue);
}