// Fill out your copyright notice in the Description page of Project Settings.


#include "FishyBusinessGameModeBase.h"

AFishyBusinessGameModeBase::AFishyBusinessGameModeBase()
{
	xDialogueElaborator = CreateDefaultSubobject<UDialogueElaborator>("Dialogue Elaborator");
	this->AddInstanceComponent(xDialogueElaborator);
	
	xDialogueEventManager = CreateDefaultSubobject<UObserverManager>("Dialogue event");
	this->AddInstanceComponent(xDialogueEventManager);
}