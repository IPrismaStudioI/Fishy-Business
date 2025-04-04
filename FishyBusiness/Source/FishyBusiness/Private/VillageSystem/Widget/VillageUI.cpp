// Fill out your copyright notice in the Description page of Project Settings.


#include "VillageSystem/Widget/VillageUI.h"

void UVillageUI::NativeConstruct()
{
	Super::NativeConstruct();

	_xFishShopBtn->OnClicked.AddDynamic(this, &UVillageUI::onFishShopBtnClicked);
	_xLighthouseBtn->OnClicked.AddDynamic(this, &UVillageUI::onLighthouseBtnClicked);
	_xWorkshopBtn->OnClicked.AddDynamic(this, &UVillageUI::onWorkshopBtnClicked);
	_xArchiveBtn->OnClicked.AddDynamic(this, &UVillageUI::onArchiveBtnClicked);
	_xCarpentryBtn->OnClicked.AddDynamic(this, &UVillageUI::onCarpentryBtnClicked);

}

void UVillageUI::onFishShopBtnClicked()
{
	EventParameters eventParameters;
	eventParameters.Add(nullptr);
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	
	gamemode->xDialogueEventManager->TriggerEvent(EventListVillage::SHOW_FISHSHOP, eventParameters);
}

void UVillageUI::onLighthouseBtnClicked()
{
	EventParameters eventParameters;
	eventParameters.Add(nullptr);
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	
	gamemode->xDialogueEventManager->TriggerEvent(EventListVillage::SHOW_LIGHTHOUSE, eventParameters);
}

void UVillageUI::onWorkshopBtnClicked()
{
	EventParameters eventParameters;
	eventParameters.Add(nullptr);
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	
	gamemode->xDialogueEventManager->TriggerEvent(EventListVillage::SHOW_WORKSHOP, eventParameters);
}

void UVillageUI::onArchiveBtnClicked()
{
	EventParameters eventParameters;
	eventParameters.Add(nullptr);
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	
	gamemode->xDialogueEventManager->TriggerEvent(EventListVillage::SHOW_ARCHIVE, eventParameters);
}

void UVillageUI::onCarpentryBtnClicked()
{
	EventParameters eventParameters;
	eventParameters.Add(nullptr);
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	
	gamemode->xDialogueEventManager->TriggerEvent(EventListVillage::SHOW_CARPENTRY, eventParameters);
}
