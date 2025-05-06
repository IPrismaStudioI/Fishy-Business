// Fill out your copyright notice in the Description page of Project Settings.


#include "DIalogueSystem/DialogueTriggers/ButtonDialogueTriggerQuestComplete.h"

void UButtonDialogueTriggerQuestComplete::CheckIfVisible()
{
	Super::CheckIfVisible();

	if (_bOneTime)
	{
		AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();

		if (gamemode->xQuestUnlockStorageManager->_sCompletedQuestList.Contains(_sQuestID))
		{
			_bOneTime = false;
			this->SetVisibility(ESlateVisibility::Visible);
		}
		else
		{
			this->SetVisibility(ESlateVisibility::Collapsed);
		}
	}
}
