// Fill out your copyright notice in the Description page of Project Settings.


#include "VillageSystem/UpgradeBuilding.h"

void AUpgradeBuilding::BeginPlay()
{
	Super::BeginPlay();
	
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	UEventBus* EventManager = gamemode->xVillageEventBus;
	UEventWrapper::RegisterEvent(EventManager, EventListVillage::RESTORE_WORKSHOP, MakeShared<TFunction<void(const EventParameters&)>>( [this] (const EventParameters& Params) { xRestoreComponent->ChangeStatus(Params) ;}));
}