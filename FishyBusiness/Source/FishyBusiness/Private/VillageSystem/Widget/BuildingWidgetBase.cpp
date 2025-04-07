// Fill out your copyright notice in the Description page of Project Settings.


#include "VillageSystem/Widget/BuildingWidgetBase.h"

#include "FishyBusiness/FishyBusinessGameModeBase.h"

void UBuildingWidgetBase::NativeConstruct()
{
	Super::NativeConstruct();

	HideCanvas();
	
	_xExitBuildingBtn->OnClicked.AddDynamic(this, &UBuildingWidgetBase::ExitBuilding);
}

void UBuildingWidgetBase::HideCanvas()
{
	_xCanvas->SetVisibility(ESlateVisibility::Collapsed);
}

void UBuildingWidgetBase::ShowCanvas(EventParameters parameters)
{
	_xCanvas->SetVisibility(ESlateVisibility::Visible);
}

void UBuildingWidgetBase::ExitBuilding()
{
	HideCanvas();

	EventParameters eventParameters;
	eventParameters.Add(nullptr);
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	
	gamemode->xVillageEventBus->TriggerEvent(EventListVillage::SHOW_VILLAGE_BASE, eventParameters);

}
