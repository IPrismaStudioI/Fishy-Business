// Fill out your copyright notice in the Description page of Project Settings.


#include "VillageSystem/ShopBuilding.h"

AShopBuilding::AShopBuilding()
{
	_xSellComponent = CreateDefaultSubobject<USellComponent>("Sell Component");
	this->AddInstanceComponent(_xSellComponent); 
}

void AShopBuilding::BeginPlay()
{
	Super::BeginPlay();
	
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	UEventBus* EventManager = gamemode->xVillageEventBus;
	UEventWrapper::RegisterEvent(EventManager, EventListVillage::RESTORE_FISHSHOP, MakeShared<TFunction<void(const EventParameters&)>>( [this] (const EventParameters& Params) { xRestoreComponent->ChangeStatus(Params) ;}));
}
