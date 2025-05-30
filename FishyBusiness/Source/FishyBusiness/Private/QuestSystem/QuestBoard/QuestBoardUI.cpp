// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestSystem/QuestBoard/QuestBoardUI.h"

#include "FishyBusiness/FishyBusinessGameModeBase.h"

void UQuestBoardUI::NativeConstruct()
{
	Super::NativeConstruct();

	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	UEventBus* EventManager = gamemode->xQuestEventBus;
	UEventWrapper::RegisterEvent(EventManager, EventListQuest::SHOW_QUEST_BOARD, MakeShared<TFunction<void(const EventParameters&)>>( [this] (const EventParameters& Params) { OpenBoard(Params) ;}));
	
	for (int32 i = 0; i < _xCanvasBulletin->GetChildrenCount(); i++)
	{
		if (UQuestBulletinUI* item = Cast<UQuestBulletinUI>(_xCanvasBulletin->GetChildAt(i)))
		{
			xQuestItemUIList.Add(item);
		}
	}

	CloseBoard();

	_xExitBtn->OnClicked.AddDynamic(this, &UQuestBoardUI::CloseBoard);
}

void UQuestBoardUI::OpenBoard(EventParameters parameters)
{
	_xCanvas->SetVisibility(ESlateVisibility::Collapsed);
	_xCanvas->SetVisibility(ESlateVisibility::Visible);
	ShowQuestBoard();
}

void UQuestBoardUI::CloseBoard()
{
	_xCanvas->SetVisibility(ESlateVisibility::Collapsed);
}

void UQuestBoardUI::OnClick()
{
	CloseBoard();
}
