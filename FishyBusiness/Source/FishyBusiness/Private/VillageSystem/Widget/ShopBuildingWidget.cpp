// Fill out your copyright notice in the Description page of Project Settings.


#include "VillageSystem/Widget/ShopBuildingWidget.h"
#include "FishyBusiness/FishyBusinessGameModeBase.h"

void UShopBuildingWidget::NativeConstruct()
{
	Super::NativeConstruct();

	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	UEventBus* eventBus = gamemode->xVillageEventBus;
	UEventWrapper::RegisterEvent(eventBus, EventListVillage::SHOW_FISHSHOP, MakeShared<TFunction<void(const EventParameters&)>>([this](const EventParameters& Params) { ShowCanvas(Params); }));

	_xShopMenu->SetVisibility(ESlateVisibility::Collapsed);
	
	_xShopBtn->OnClicked.AddDynamic(this, &UShopBuildingWidget::ShowShopMenu);
	_xExitShopBtn->OnClicked.AddDynamic(this, &UShopBuildingWidget::HideShopMenu);
}

void UShopBuildingWidget::ShowShopMenu()
{
	_xShopMenu->SetVisibility(ESlateVisibility::Visible);
	_xMainMenu->SetVisibility(ESlateVisibility::Collapsed);

	OnShowShopMenuUI();
}

void UShopBuildingWidget::HideShopMenu()
{
	_xShopMenu->SetVisibility(ESlateVisibility::Collapsed);
	OnHideShopMenuUI();
}
