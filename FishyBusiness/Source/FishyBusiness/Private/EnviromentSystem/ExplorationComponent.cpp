// Fill out your copyright notice in the Description page of Project Settings.


#include "EnviromentSystem/ExplorationComponent.h"

#include "FishyBusiness/FishyBusinessGameModeBase.h"

// Sets default values for this component's properties
UExplorationComponent::UExplorationComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UExplorationComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UExplorationComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UExplorationComponent::CallExploration()
{
	EventParameters eventParameters;
	int intZone = static_cast<int>(eZone);
	eventParameters.Add(UParameterWrapper::CreateParameter<int>(intZone));
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	
	gamemode->xQuestEventBus->TriggerEvent(EventListQuest::ADVANCE_EXPLORE, eventParameters);
}

