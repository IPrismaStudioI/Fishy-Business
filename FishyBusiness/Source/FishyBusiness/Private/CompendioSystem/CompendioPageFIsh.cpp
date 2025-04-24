// Fill out your copyright notice in the Description page of Project Settings.


#include "CompendioSystem/CompendioPageFIsh.h"
#include "FishyBusiness/FishyBusinessGameModeBase.h"

void UCompendioPageFIsh::NativeConstruct()
{
	Super::NativeConstruct();

	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	UEventBus* eventBus = gamemode->xCompendioEventBus;
	UEventWrapper::RegisterEvent(eventBus, EventListCompendio::FILL_INFORMATION, MakeShared<TFunction<void(const EventParameters&)>>([this](const EventParameters& Params) { FillInformations(Params); }));
	
}

void UCompendioPageFIsh::FillInformations(EventParameters parameters)
{
	
}
