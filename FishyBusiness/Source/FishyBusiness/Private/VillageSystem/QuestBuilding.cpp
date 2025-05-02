// Fill out your copyright notice in the Description page of Project Settings.


#include "VillageSystem/QuestBuilding.h"

AQuestBuilding::AQuestBuilding()
{
	_xQuestBoard = CreateDefaultSubobject<UQuestBoard>("Quest Board");
	this->AddInstanceComponent(_xQuestBoard);
	_xQuestReward = CreateDefaultSubobject<UQuestReward>("Quest Reward");
	this->AddInstanceComponent(_xQuestReward);
}

void AQuestBuilding::BeginPlay()
{
	Super::BeginPlay();

	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	UEventBus* EventManager = gamemode->xVillageEventBus;
	UEventWrapper::RegisterEvent(EventManager, EventListVillage::RESTORE_LIGHTHOUSE, MakeShared<TFunction<void(const EventParameters&)>>( [this] (const EventParameters& Params) { xRestoreComponent->ChangeStatus(Params) ;}));
}
