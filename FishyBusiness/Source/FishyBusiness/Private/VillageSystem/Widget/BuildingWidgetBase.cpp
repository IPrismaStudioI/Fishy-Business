// Fill out your copyright notice in the Description page of Project Settings.


#include "VillageSystem/Widget/BuildingWidgetBase.h"

void UBuildingWidgetBase::NativeConstruct()
{
	Super::NativeConstruct();

	HideCanvas();
}

void UBuildingWidgetBase::HideCanvas()
{
	_xCanvas->SetVisibility(ESlateVisibility::Collapsed);
}
