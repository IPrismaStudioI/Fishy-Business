// Fill out your copyright notice in the Description page of Project Settings.


#include "CompendioSystem/CompendioPageFIsh.h"
#include "FishyBusiness/FishyBusinessGameModeBase.h"

void UCompendioPageFIsh::NativeConstruct()
{
	Super::NativeConstruct();

	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	UEventBus* eventBus = gamemode->xCompendioEventBus;
}

void UCompendioPageFIsh::NativeDestruct()
{
	Super::NativeConstruct();
}

void UCompendioPageFIsh::FillInformations(bool isCatalogued)
{

}
