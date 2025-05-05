// Fill out your copyright notice in the Description page of Project Settings.


#include "VillageSystem/RestoreComponent.h"

#include "Enums/EBuildings.h"
#include "VillageSystem/BuildingBase.h"

// Sets default values for this component's properties
URestoreComponent::URestoreComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void URestoreComponent::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void URestoreComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void URestoreComponent::ChangeStatus(EventParameters params)
{
	int i = params[0]->Getter<int>();
	Cast<ALightChangableBase>(GetOwner())->GetXSprite()->SetSprite(xSpriteList[i]);
}

