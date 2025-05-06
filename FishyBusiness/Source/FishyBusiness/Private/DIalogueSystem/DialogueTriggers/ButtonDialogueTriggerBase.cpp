// Fill out your copyright notice in the Description page of Project Settings.


#include "DIalogueSystem/DialogueTriggers/ButtonDialogueTriggerBase.h"

#include "DataTables/DialogueRow.h"
#include "DIalogueSystem/DA_Dialogue.h"
#include "FishyBusiness/FishyBusinessGameModeBase.h"

UButtonDialogueTriggerBase::UButtonDialogueTriggerBase()
{
	this->OnClicked.AddDynamic(this, &UButtonDialogueTriggerBase::StartDialogue);
}

void UButtonDialogueTriggerBase::StartDialogue()
{
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();

	if (gamemode->GetDialogueFromDT(_sDialogueID) == nullptr) return;
	
	gamemode->xDialogueElaborator->StartDialogue(gamemode->GetDialogueFromDT(_sDialogueID)->Dialogue);
}

void UButtonDialogueTriggerBase::CheckIfVisible()
{
}
