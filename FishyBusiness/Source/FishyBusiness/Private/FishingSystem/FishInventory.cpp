// Fill out your copyright notice in the Description page of Project Settings.


#include "FishingSystem/FishInventory.h"

#include "FishyBusiness/FishyBusinessGameModeBase.h"

// Sets default values for this component's properties
UFishInventory::UFishInventory()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UFishInventory::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UFishInventory::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UFishInventory::AddFish(FString fishID)
{
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	
	UFish* fish = gamemode->GetFishFromDT(fishID);

	if (fish == nullptr) return;
	
	FFishInfo newFishInfo(fish->fBasePrice, fish->fBaseSize);

	if (_mFishes.Contains(fishID))
	{
		_mFishes[fishID].aFishInfos.Add(newFishInfo);

		EventParameters eventParameters;

		eventParameters.Add(UParameterWrapper::CreateParameter<FString>(fishID));
	
		int amount = _mFishes[fishID].aFishInfos.Num();
		eventParameters.Add(UParameterWrapper::CreateParameter<int>(amount));
	
		gamemode->xQuestEventBus->TriggerEvent(EventListQuest::ADVANCE_COLLECT, eventParameters);
		return;
	}
	_mFishes.Add(fishID);
	_mFishes[fishID].aFishInfos.Add(newFishInfo);

	EventParameters eventParameters;

	eventParameters.Add(UParameterWrapper::CreateParameter<FString>(fishID));
	
	int amount = _mFishes[fishID].aFishInfos.Num();
	eventParameters.Add(UParameterWrapper::CreateParameter<int>(amount));
	
	gamemode->xQuestEventBus->TriggerEvent(EventListQuest::ADVANCE_COLLECT, eventParameters);
	
}

void UFishInventory::RemoveFish(FString fishID)
{
	if (_mFishes.Contains(fishID))
	{
		_mFishes[fishID].aFishInfos.Pop();
		return;
	}
	_mFishes.Add(fishID);
	_mFishes[fishID].aFishInfos.Pop();
}

