// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestSystem/QuestBoard/QuestBulletinFocusedUI.h"

#include "FishyBusiness/FishyBusinessGameModeBase.h"

void UQuestBulletinFocusedUI::NativeConstruct()
{
	Super::NativeConstruct();

	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	UEventBus* EventManager = gamemode->xQuestEventBus;
	UEventWrapper::RegisterEvent(EventManager, EventListQuest::FILL_BULLETIN, MakeShared<TFunction<void(const EventParameters&)>>( [this] (const EventParameters& Params) { FillBulletin(Params) ;}));

	ShowBulletin(false);
	
	_xQuestExitBtn->OnClicked.AddDynamic(this, &UQuestBulletinFocusedUI::QuitBulletin);
	_xQuestAcceptBtn->OnClicked.AddDynamic(this, &UQuestBulletinFocusedUI::QuestAccept);
}

void UQuestBulletinFocusedUI::QuestAccept()
{
	EventParameters eventParameters;
	eventParameters.Add(UParameterWrapper::CreateParameter<FString>(_sQuestID));
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	
	gamemode->xQuestEventBus->TriggerEvent(EventListQuest::UI_ADD_QUEST, eventParameters);

	ShowBulletin(false);
}

void UQuestBulletinFocusedUI::CloseBulletin()
{
	_xCanvas->SetVisibility(ESlateVisibility::Collapsed);
}

void UQuestBulletinFocusedUI::FillBulletin(EventParameters parameters)
{
	_sQuestID = parameters[0]->Getter<FString>();

	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	FString name = "<QuestName>" + gamemode->xQuestDataManager->GetQuestNameFromDT(_sQuestID) + "</>";
	_xQuestName->SetText(FText::FromString(name));
	_xQuestDescription->SetText(FText::FromString(gamemode->xQuestDataManager->GetQuestDescriptionFromDT(_sQuestID)));
	FString npc = "<QuestNPC>" + gamemode->xQuestDataManager->GetQuestGiverFromDT(_sQuestID) + "</>";
	_xQuestGiver->SetText(FText::FromString(npc));

	ShowBulletin(true);
}

void UQuestBulletinFocusedUI::ShowBulletin(bool isShowed)
{
	if (isShowed)
		_xCanvas->SetVisibility(ESlateVisibility::Visible);
		OnVisible();
	else
		_xCanvas->SetVisibility(ESlateVisibility::Collapsed);
}

void UQuestBulletinFocusedUI::QuitBulletin()
{
	ShowBulletin(false);
}

void UQuestBulletinFocusedUI::OnClickAccept()
{
	QuestAccept();
}

void UQuestBulletinFocusedUI::OnClickDecline()
{
	CloseBulletin();
}

