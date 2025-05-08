// Fill out your copyright notice in the Description page of Project Settings.


#include "CompendioSystem/CompendioPageQuest.h"

#include "Blueprint/WidgetTree.h"
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
	FillQuest();
}

void UCompendioPageQuest::FillQuest()
{
	UAC_QuestLog* log = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(),0))->xQuestLog;

	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	
	if (log->xQuests.Find(_sQuestID))
	{
		_xQuestCanvas->SetVisibility(ESlateVisibility::Visible);
		FString status = "<Compendium>" + UEnum::GetDisplayValueAsText(log->xQuests[_sQuestID].eStatus).ToString() + "</>";
		_xQuestStatus->SetText(FText::FromString(status));
		FString name = "<Compendium>" + gamemode->xQuestDataManager->GetQuestNameFromDT(_sQuestID) + "</>";
		_xQuestName->SetText(FText::FromString(name));
		FString description = "<Compendium>" + gamemode->xQuestDataManager->GetQuestDescriptionFromDT(_sQuestID) + "</>";
		_xQuestDescription->SetText(FText::FromString(description));

		for (int i = 0; i < log->xQuests.Find(_sQuestID)->iCurrentModule; i++)
		{
			FString desc = "<Compendium>" + log->xQuests.Find(_sQuestID)->xModules[i]->sDescription + "</>";
			FString currentAmount = "<Compendium>" + FString::FromInt(log->xQuests.Find(_sQuestID)->iCurrentAmountModules[i]) + "</>";
			FString totalAmount = "<Compendium>" + FString::FromInt(log->xQuests.Find(_sQuestID)->iTotalAmountModules[i]) + "</>";

			UQuestModuleUI* taskQuestTmp = WidgetTree->ConstructWidget<UQuestModuleUI>(_xQuestTaskUI);
			taskQuestTmp->_xQuestTaskDescription->SetText(FText::FromString(desc));
			taskQuestTmp->_xQuestTaskCurrentAmount->SetText(FText::FromString(currentAmount));
			taskQuestTmp->_xQuestTaskTotalAmount->SetText(FText::FromString(totalAmount));
			_xBoxTasks->AddChild(taskQuestTmp);
		}
	}
	else
	{
		_xQuestCanvas->SetVisibility(ESlateVisibility::Collapsed);
	}
}
