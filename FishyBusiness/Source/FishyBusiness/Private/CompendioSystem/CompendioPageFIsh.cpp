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
		FString name = "<Compendium>" + fish->sFishName + "</>";
		_xFishName->SetText(FText::FromString(name));
		FString sname = "<Compendium>" + fish->sFishSName + "</>";
		_xFishSName->SetText(FText::FromString(sname));
		FString desc = "<Compendium>" + fish->sFishDescription + "</>";
		_xFishDescription->SetText(FText::FromString(desc));
		FString loc = "<Compendium>" + UEnum::GetDisplayValueAsText(fish->eLocation).ToString() + "</>";
		_xLocation->SetText(FText::FromString(loc));
	}
	else
	{
		_xPageImage->SetBrushFromTexture(fish->xFishNotCatalogueImage);
	}
}
