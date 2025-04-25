// Fill out your copyright notice in the Description page of Project Settings.


#include "CompendioSystem/CompendioPageFIsh.h"
#include "FishyBusiness/FishyBusinessGameModeBase.h"

void UCompendioPageFIsh::NativeConstruct()
{
	Super::NativeConstruct();
}

void UCompendioPageFIsh::NativeDestruct()
{
	Super::NativeConstruct();
}

void UCompendioPageFIsh::FillInformations(bool isCatalogued)
{
	Super::FillInformations(isCatalogued);
	
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	UFish* fish = gamemode->GetFishFromDT(sFishID);
	
	if (isCatalogued)
	{
		_xPageImage->SetBrushFromTexture(fish->xFishCatalogueImage);
		_xFishName->SetText(FText::FromString(fish->sFishName));
		_xLocation->SetText(FText::FromString(UEnum::GetValueAsString(fish->eLocation)));
	}
	else
	{
		_xPageImage->SetBrushFromTexture(fish->xFishNotCatalogueImage);
	}
}
