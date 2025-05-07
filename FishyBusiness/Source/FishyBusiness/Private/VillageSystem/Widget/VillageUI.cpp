// Fill out your copyright notice in the Description page of Project Settings.


#include "VillageSystem/Widget/VillageUI.h"

void UVillageUI::NativeConstruct()
{
	Super::NativeConstruct();

	HideWidget();
	
	_xFishShopBtn->OnClicked.AddDynamic(this, &UVillageUI::onFishShopBtnClicked);
	_xLighthouseBtn->OnClicked.AddDynamic(this, &UVillageUI::onLighthouseBtnClicked);
	_xWorkshopBtn->OnClicked.AddDynamic(this, &UVillageUI::onWorkshopBtnClicked);
	_xArchiveBtn->OnClicked.AddDynamic(this, &UVillageUI::onArchiveBtnClicked);
	_xCarpentryBtn->OnClicked.AddDynamic(this, &UVillageUI::onCarpentryBtnClicked);
	_xExitVillageBtn->OnClicked.AddDynamic(this, &UVillageUI::ExitWidget);

	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	UEventBus* eventBus = gamemode->xVillageEventBus;
	UEventWrapper::RegisterEvent(eventBus, EventListVillage::SHOW_VILLAGE_BASE, MakeShared<TFunction<void(const EventParameters&)>>([this](const EventParameters& Params) { ShowWidget(Params); }));
}

void UVillageUI::onFishShopBtnClicked()
{
	EventParameters eventParameters;
	eventParameters.Add(nullptr);
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	
	gamemode->xVillageEventBus->TriggerEvent(EventListVillage::SHOW_FISHSHOP, eventParameters);

	HideWidget();
}

void UVillageUI::onLighthouseBtnClicked()
{
	EventParameters eventParameters;
	eventParameters.Add(nullptr);
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	
	gamemode->xVillageEventBus->TriggerEvent(EventListVillage::SHOW_LIGHTHOUSE, eventParameters);

	HideWidget();
}

void UVillageUI::onWorkshopBtnClicked()
{
	EventParameters eventParameters;
	eventParameters.Add(nullptr);
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	
	gamemode->xVillageEventBus->TriggerEvent(EventListVillage::SHOW_WORKSHOP, eventParameters);

	HideWidget();
}

void UVillageUI::onArchiveBtnClicked()
{
	EventParameters eventParameters;
	eventParameters.Add(nullptr);
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	
	gamemode->xVillageEventBus->TriggerEvent(EventListVillage::SHOW_ARCHIVE, eventParameters);

	HideWidget();
}

void UVillageUI::onCarpentryBtnClicked()
{
	EventParameters eventParameters;
	eventParameters.Add(nullptr);
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	
	gamemode->xVillageEventBus->TriggerEvent(EventListVillage::SHOW_CARPENTRY, eventParameters);

	HideWidget();
}

void UVillageUI::ShowWidget(EventParameters parameters)
{
	_xCanvas->SetVisibility(ESlateVisibility::Visible);
	OnVisible();
}

void UVillageUI::ExitWidget()
{
	EventParameters eventParameters;
	eventParameters.Add(nullptr);
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	gamemode->xVillageEventBus->TriggerEvent(EventListVillage::HIDE_VILLAGE_BASE, eventParameters);

	_xCanvas->SetVisibility(ESlateVisibility::Collapsed);
}

void UVillageUI::HideWidget()
{
	_xCanvas->SetVisibility(ESlateVisibility::Collapsed);
}
