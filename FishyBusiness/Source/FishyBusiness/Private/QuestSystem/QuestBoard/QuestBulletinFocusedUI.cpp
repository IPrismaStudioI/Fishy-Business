// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestSystem/QuestBoard/QuestBulletinFocusedUI.h"

#include "FishyBusiness/FishyBusinessGameModeBase.h"

void UQuestBulletinFocusedUI::NativeConstruct()
{
	Super::NativeConstruct();

	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	
	UEventBus* EventManager = gamemode->xQuestEventBus;
	
	UEventWrapper::RegisterEvent(EventManager, EventListQuest::FILL_BULLETIN, MakeShared<TFunction<void(const EventParameters&)>>( [this] (const EventParameters& Params) { FillBulletin(Params) ;}));

}

void UQuestBulletinFocusedUI::QuestAccept()
{
	//TODO da vedere con jack e il quest logo
}

void UQuestBulletinFocusedUI::CloseBulletin()
{
	_xCanvas->SetVisibility(ESlateVisibility::Collapsed);
}

void UQuestBulletinFocusedUI::FillBulletin(EventParameters parameters)
{
	
}
