// Fill out your copyright notice in the Description page of Project Settings.


#include "FishyBusinessGameModeBase.h"

#include "Kismet/GameplayStatics.h"

AFishyBusinessGameModeBase::AFishyBusinessGameModeBase()
{
	xDialogueElaborator = CreateDefaultSubobject<UDialogueElaborator>("Dialogue Elaborator");
	this->AddInstanceComponent(xDialogueElaborator);
	
	xDialogueEventManager = CreateDefaultSubobject<UObserverManager>("Dialogue event");
	this->AddInstanceComponent(xDialogueEventManager);
}

AFishyBusinessGameModeBase* AFishyBusinessGameModeBase::GetInstance()
{
	AFishyBusinessGameModeBase* gamemode = GEngine->GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	return gamemode;
}
