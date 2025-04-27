// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestSystem/QuestBoard/QuestBoardUI.h"

void UQuestBoardUI::NativeConstruct()
{
	Super::NativeConstruct();

	for (int32 i = 0; i < _xCanvasBulletin->GetChildrenCount(); i++)
	{
		if (UQuestItemUI* item = Cast<UQuestItemUI>(_xCanvasBulletin->GetChildAt(i)))
		{
			xQuestItemUIList.Add(item);
		}
	}
}
