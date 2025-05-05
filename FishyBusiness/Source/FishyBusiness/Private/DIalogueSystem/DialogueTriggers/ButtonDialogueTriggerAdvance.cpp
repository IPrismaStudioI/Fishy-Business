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
	int intName = static_cast<int>(_eName); //casts the enum npc name into an int
	eventParameters.Add(UParameterWrapper::CreateParameter<int>(intName)); //add param int name

	eventParameters.Add(UParameterWrapper::CreateParameter<FString>(_sQuestID)); //add the quest ID as param

	eventParameters.Add(UParameterWrapper::CreateParameter<int>(_iModuleIndex)); //add the associated module for the quest
	
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	
	gamemode->xQuestEventBus->TriggerEvent(EventListQuest::ADVANCE_INTERACT, eventParameters); //check QuestLog.h/cpp
}

void UButtonDialogueTriggerAdvance::CheckIfVisible()
{
	APlayerCharacter* player = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (player->xQuestLog->xQuests[_sQuestID].iCurrentModule == _iModuleIndex) //checks if the current module is the same as the specified _iModulIndex
	{
		this->SetVisibility(ESlateVisibility::Visible);
	}
	else
	{
		this->SetVisibility(ESlateVisibility::Collapsed);
	}
}
