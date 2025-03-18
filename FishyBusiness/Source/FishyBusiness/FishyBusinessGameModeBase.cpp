// Fill out your copyright notice in the Description page of Project Settings.


#include "FishyBusinessGameModeBase.h"

AFishyBusinessGameModeBase::AFishyBusinessGameModeBase()
{
	DialogueElaborator = CreateDefaultSubobject<UDialogueElaborator>("Dialogue Elaboratore");
	this->AddInstanceComponent(DialogueElaborator);
}
