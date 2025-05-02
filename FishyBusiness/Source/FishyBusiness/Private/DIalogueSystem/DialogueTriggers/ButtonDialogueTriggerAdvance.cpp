// Fill out your copyright notice in the Description page of Project Settings.


#include "DIalogueSystem/DialogueTriggers/ButtonDialogueTriggerAdvance.h"

#include "Kismet/GameplayStatics.h"
#include "PlayerSystem/PlayerCharacter.h"

UButtonDialogueTriggerAdvance::UButtonDialogueTriggerAdvance()
{
	this->OnClicked.AddDynamic(this, &UButtonDialogueTriggerAdvance::AdvanceQuest);

}

void UButtonDialogueTriggerAdvance::AdvanceQuest()
{
	EventParameters eventParameters;
	int intName = static_cast<int>(_eName);
	eventParameters.Add(UParameterWrapper::CreateParameter<int>(intName));

	eventParameters.Add(UParameterWrapper::CreateParameter<FString>(_sQuestID));
	
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	
	gamemode->xQuestEventBus->TriggerEvent(EventListQuest::ADVANCE_INTERACT, eventParameters);
}

void UButtonDialogueTriggerAdvance::CheckIfVisible()
{
	APlayerCharacter* player = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (player->xQuestLog->xQuests[_sQuestID].iCurrentModule == _iModuleIndex)
	{
		this->SetVisibility(ESlateVisibility::Visible);
	}
	else
	{
		this->SetVisibility(ESlateVisibility::Collapsed);
	}
}
