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

	if (GetWorld())
	{
		AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
		UFish* fish = gamemode->GetFishFromDT(sFishID);
		_xLilaInfoBtn->Set_SDialogueID(sLilaInfoID);
		if (isCatalogued)
		{
			_xPageImage->SetBrushFromTexture(fish->xFishCatalogueImage);
			FString name = "<Compendium>" + fish->sFishName + "</>";
			_xFishName->SetText(FText::FromString(name));
			FString sname = "<Compendium>" + fish->sFishSName + "</>";
			_xFishSName->SetText(FText::FromString(sname));
			FString desc = "<Compendium>" + fish->sFishDescription + "</>";
			_xFishDescription->SetText(FText::FromString(desc));
			FString loc = "<Compendium>" + gamemode->eBiomesNames[fish->eLocation] + "</>";
			_xLocation->SetText(FText::FromString(loc));
			_xLilaInfoBtn->SetVisibility(ESlateVisibility::Visible);
		}
		else
		{
			_xPageImage->SetBrushFromTexture(fish->xFishNotCatalogueImage);
			_xLilaInfoBtn->SetVisibility(ESlateVisibility::Collapsed);
		}
	}
}
