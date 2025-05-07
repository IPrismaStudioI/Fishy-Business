// Fill out your copyright notice in the Description page of Project Settings.


#include "CompendioSystem/CatalogueFishComponent.h"

// Sets default values for this component's properties
UCatalogueFishComponent::UCatalogueFishComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UCatalogueFishComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UCatalogueFishComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

