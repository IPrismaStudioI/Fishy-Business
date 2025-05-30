// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestSystem/QuestBoard/QuestBulletinUI.h"

#include "EventManager/EventWrapper.h"
#include "FishyBusiness/FishyBusinessGameModeBase.h"

void UQuestBulletinUI::NativeConstruct()
{
	Super::NativeConstruct();

	_xBulletinBtn->OnClicked.AddDynamic(this, &UQuestBulletinUI::CheckCompleted);
}

void UQuestBulletinUI::CheckCompleted()
{
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	int i = gamemode->xQuestUnlockStorageManager->_sCompletedQuestList.Find(_sQuestID);
	if (i == -1)
		ShowBulletinFocused();
	else
		ApplyReward();
}

void UQuestBulletinUI::EnableBulletin(bool value)
{
	_xBulletinBtn->SetIsEnabled(value);
}

void UQuestBulletinUI::OnClick()
{
	CheckCompleted();
}

void UQuestBulletinUI::ShowBulletinFocused()
{
	EventParameters eventParameters;
	eventParameters.Add(UParameterWrapper::CreateParameter<FString>(_sQuestID));
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	
	gamemode->xQuestEventBus->TriggerEvent(EventListQuest::FILL_BULLETIN, eventParameters);
}

void UQuestBulletinUI::ApplyReward()
{
	EventParameters eventParameters;
	eventParameters.Add(UParameterWrapper::CreateParameter<FString>(_sQuestID));
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	
	if (gamemode->xQuestDataManager->GetQuestRewardTypeFromDT(_sQuestID) != EQuestRewardType::NEW_QUEST_REWARD)
	{
		EnableBulletin(false);
	}
	
	gamemode->xQuestEventBus->TriggerEvent(EventListQuest::GET_REWARD, eventParameters);

}
