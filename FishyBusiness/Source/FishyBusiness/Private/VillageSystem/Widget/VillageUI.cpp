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

	UEventBus* eventBusInput = gamemode->xInputEventBus;
	UEventWrapper::RegisterEvent(eventBusInput, EventListInput::CLOSE_VILLAGE_INPUT, MakeShared<TFunction<void(const EventParameters&)>>([this](const EventParameters& Params) { ExitWidgetEvent(Params); }));
}

void UVillageUI::onFishShopBtnClicked()
{
	EventParameters eventParameters;
	eventParameters.Add(nullptr);
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	gamemode->xVillageEventBus->TriggerEvent(EventListVillage::SHOW_FISHSHOP, eventParameters);
	SetIsInBuilding();
	
	HideWidget();
}

void UVillageUI::onLighthouseBtnClicked()
{
	EventParameters eventParameters;
	eventParameters.Add(nullptr);
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	gamemode->xVillageEventBus->TriggerEvent(EventListVillage::SHOW_LIGHTHOUSE, eventParameters);
	SetIsInBuilding();

	HideWidget();
}

void UVillageUI::onWorkshopBtnClicked()
{
	EventParameters eventParameters;
	eventParameters.Add(nullptr);
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	gamemode->xVillageEventBus->TriggerEvent(EventListVillage::SHOW_WORKSHOP, eventParameters);
	SetIsInBuilding();

	HideWidget();
}

void UVillageUI::onArchiveBtnClicked()
{
	EventParameters eventParameters;
	eventParameters.Add(nullptr);
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	gamemode->xVillageEventBus->TriggerEvent(EventListVillage::SHOW_ARCHIVE, eventParameters);
	SetIsInBuilding();

	HideWidget();
}

void UVillageUI::onCarpentryBtnClicked()
{
	EventParameters eventParameters;
	eventParameters.Add(nullptr);
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	gamemode->xVillageEventBus->TriggerEvent(EventListVillage::SHOW_CARPENTRY, eventParameters);
	SetIsInBuilding();
	
	HideWidget();
}

void UVillageUI::ShowWidget(EventParameters parameters)
{
	if (_bIsInBuilding == true)
		_bIsInBuilding = false;
	
	_xCanvas->SetVisibility(ESlateVisibility::Visible);
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	gamemode->_xActiveWidgets.Add(this);
	OnVisible();
}

void UVillageUI::ExitWidget()
{
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	if (_bIsInBuilding) return;
	if (!gamemode->_xActiveWidgets.IsEmpty())
	{
		if (gamemode->_xActiveWidgets.Last() != this) return;
	}
	
	
	EventParameters eventParameters;
	eventParameters.Add(nullptr);
	gamemode->xVillageEventBus->TriggerEvent(EventListVillage::HIDE_VILLAGE_BASE, eventParameters);

	gamemode->_xActiveWidgets.Remove(this);
	_xCanvas->SetVisibility(ESlateVisibility::Collapsed);
}

void UVillageUI::ExitWidgetEvent(EventParameters parameters)
{
	ExitWidget();
}

void UVillageUI::HideWidget()
{
	_xCanvas->SetVisibility(ESlateVisibility::Collapsed);
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	gamemode->_xActiveWidgets.Remove(this);
}

void UVillageUI::SetIsInBuilding()
{
	_bIsInBuilding = !_bIsInBuilding;
}
