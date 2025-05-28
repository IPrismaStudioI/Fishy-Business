// Fill out your copyright notice in the Description page of Project Settings.


#include "DIalogueSystem/DialogueTriggers/ButtonDialogueTriggerCatalogue.h"

UButtonDialogueTriggerCatalogue::UButtonDialogueTriggerCatalogue()
{
	this->OnClicked.AddDynamic(this, &UButtonDialogueTriggerCatalogue::SetMainOverlay);
}

void UButtonDialogueTriggerCatalogue::CheckIfVisible()
{
	Super::CheckIfVisible();

	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	if (_sFishID.IsEmpty())
	{
		this->SetVisibility(ESlateVisibility::Collapsed);
		return;
	}
	if (!gamemode->xCatalogueFishComponent->_xFishCatalogued.Find(_sFishID)) return;
	if (gamemode->xCatalogueFishComponent->_xFishCatalogued[_sFishID]) //checks if the fish is catalogued
	{
		this->SetVisibility(ESlateVisibility::Visible);
	}
	else
	{
		this->SetVisibility(ESlateVisibility::Collapsed);
	}
}

void UButtonDialogueTriggerCatalogue::SetMainOverlay()
{
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	gamemode->SetBIsMainOverlayVisible(true);
}
