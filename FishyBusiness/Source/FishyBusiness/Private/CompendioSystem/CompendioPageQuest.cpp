// Fill out your copyright notice in the Description page of Project Settings.


#include "CompendioSystem/CompendioPageQuest.h"

#include "FishyBusiness/FishyBusinessGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerSystem/PlayerCharacter.h"

void UCompendioPageQuest::NativeConstruct()
{
	Super::NativeConstruct();
}

void UCompendioPageQuest::NativeDestruct()
{
	Super::NativeDestruct();
}

void UCompendioPageQuest::FillInformations(bool isCatalogued)
{
	Super::FillInformations(isCatalogued);

	_xPageImage->SetBrushFromTexture(_xPageTexture);
}

void UCompendioPageQuest::FillQuest()
{
	UAC_QuestLog* log = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(),0))->xQuestLog;

	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	
	if (log->xQuests.Find(_sQuestID))
	{
		_xQuestCanvas->SetVisibility(ESlateVisibility::Visible);
		FString status = UEnum::GetDisplayValueAsText(log->xQuests[_sQuestID].eStatus).ToString();
		_xQuestStatus->SetText(FText::FromString(status));
		FString name = gamemode->xQuestDataManager->GetQuestNameFromDT(_sQuestID);
		_xQuestName->SetText(FText::FromString(name));
		FString description = gamemode->xQuestDataManager->GetQuestDescriptionFromDT(_sQuestID);
		_xQuestDescription->SetText(FText::FromString(description));

		for (int i = 0; i < log->xQuests.Find(_sQuestID)->iCurrentModule; i++)
		{
			//FString desc = log->xQuests.Find(_sQuestID)->xModules[i]
		}
	}
	else
	{
		_xQuestCanvas->SetVisibility(ESlateVisibility::Collapsed);
	}
}
