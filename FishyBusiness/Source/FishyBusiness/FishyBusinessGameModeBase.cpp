// Fill out your copyright notice in the Description page of Project Settings.


#include "FishyBusinessGameModeBase.h"

AFishyBusinessGameModeBase::AFishyBusinessGameModeBase()
{
	xDialogueElaborator = CreateDefaultSubobject<UDialogueElaborator>("Dialogue Elaboratore");
	this->AddInstanceComponent(xDialogueElaborator);
}
