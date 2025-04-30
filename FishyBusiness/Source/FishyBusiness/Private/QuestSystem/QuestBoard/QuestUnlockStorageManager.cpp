// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestSystem/QuestBoard/QuestUnlockStorageManager.h"

// Sets default values for this component's properties
UQuestUnlockStorageManager::UQuestUnlockStorageManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UQuestUnlockStorageManager::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UQuestUnlockStorageManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

