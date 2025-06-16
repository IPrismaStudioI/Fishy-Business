// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerSystem/MaterialInventory.h"

#include "FishyBusiness/FishyBusinessGameModeBase.h"

// Sets default values for this component's properties
UMaterialInventory::UMaterialInventory()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMaterialInventory::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMaterialInventory::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UMaterialInventory::AddItem(FString itemID, int amount)
{
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();

	UBaseItem* item = gamemode->GetItemFromDT(itemID);

	if (item == nullptr) return;

	if (xItemMap.Contains(itemID))
	{
		xItemMap[itemID] += amount;

		EventParameters eventParameters;

		eventParameters.Add(UParameterWrapper::CreateParameter<FString>(itemID));

		int totalAmount = xItemMap[itemID];
		eventParameters.Add(UParameterWrapper::CreateParameter<int>(totalAmount));

		//gamemode->xQuestEventBus->TriggerEvent(EventlistQuest::ADVANCE_ITEM_COLLECT, eventParameters);

		return;
	}

	xItemMap.Add(itemID);
	xItemMap[itemID] += amount;

	EventParameters eventParameters;

	eventParameters.Add(UParameterWrapper::CreateParameter<FString>(itemID));

	int totalAmount = xItemMap[itemID];
	eventParameters.Add(UParameterWrapper::CreateParameter<int>(totalAmount));

	//gamemode->xQuestEventBus->TriggerEvent(EventlistQuest::ADVANCE_ITEM_COLLECT, eventParameters);
}

