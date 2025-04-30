// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestSystem/QuestBoard/QuestBulletinUI.h"

#include "EventManager/EventWrapper.h"
#include "FishyBusiness/FishyBusinessGameModeBase.h"

void UQuestBulletinUI::NativeConstruct()
{
	Super::NativeConstruct();

	_xBulletinBtn->OnClicked.AddDynamic(this, &UQuestBulletinUI::ShowBulletinFocused);
}

void UQuestBulletinUI::ShowBulletinFocused()
{
	EventParameters eventParameters;
	eventParameters.Add(UParameterWrapper::CreateParameter<FString>(_sQuestID));
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	
	gamemode->xQuestEventBus->TriggerEvent(EventListQuest::FILL_BULLETIN, eventParameters);
}
