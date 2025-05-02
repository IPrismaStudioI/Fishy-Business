// Fill out your copyright notice in the Description page of Project Settings.


#include "VillageSystem/Widget/BuildingWidgetBase.h"

#include "FishyBusiness/FishyBusinessGameModeBase.h"

void UBuildingWidgetBase::NativeConstruct()
{
	Super::NativeConstruct();

	HideCanvas();

	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	UEventBus* eventBus = gamemode->xVillageEventBus;
	UEventWrapper::RegisterEvent(eventBus, EventListVillage::SHOW_MENU, MakeShared<TFunction<void(const EventParameters&)>>([this](const EventParameters& Params) { ShowMenu(Params); }));

	
	_xExitBuildingBtn->OnClicked.AddDynamic(this, &UBuildingWidgetBase::ExitBuilding);
}

void UBuildingWidgetBase::HideCanvas()
{
	_xCanvas->SetVisibility(ESlateVisibility::Collapsed);
}

void UBuildingWidgetBase::ShowCanvas(EventParameters parameters)
{
	OnOpenBuilding();
	_xCanvas->SetVisibility(ESlateVisibility::Visible);
	_xMainMenu->SetVisibility(ESlateVisibility::Collapsed);
}

void UBuildingWidgetBase::ShowMenu(EventParameters parameters)
{
	_xMainMenu->SetVisibility(ESlateVisibility::Visible);
}

void UBuildingWidgetBase::ExitBuilding()
{
	OnCloseBuilding();
	HideCanvas();

	EventParameters eventParameters;
	eventParameters.Add(nullptr);
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	
	gamemode->xVillageEventBus->TriggerEvent(EventListVillage::SHOW_VILLAGE_BASE, eventParameters);
	gamemode->xDialogueEventBus->TriggerEvent(EventListDialogue::CLOSE_DIALOGUE, eventParameters);

}
