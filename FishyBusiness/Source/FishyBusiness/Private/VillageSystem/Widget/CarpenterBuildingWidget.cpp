// Fill out your copyright notice in the Description page of Project Settings.


#include "VillageSystem/Widget/CarpenterBuildingWidget.h"

#include "FishyBusiness/FishyBusinessGameModeBase.h"

void UCarpenterBuildingWidget::NativeConstruct()
{
	Super::NativeConstruct();

	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	UEventBus* eventBus = gamemode->xVillageEventBus;
	UEventWrapper::RegisterEvent(eventBus, EventListVillage::SHOW_CARPENTRY, MakeShared<TFunction<void(const EventParameters&)>>([this](const EventParameters& Params) { ShowCanvas(Params); }));
}
