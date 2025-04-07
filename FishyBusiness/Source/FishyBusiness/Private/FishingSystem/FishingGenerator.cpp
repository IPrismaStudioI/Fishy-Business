// Fill out your copyright notice in the Description page of Project Settings.


#include "FishingSystem/FishingGenerator.h"

#include "FishingSystem/FishingSpot.h"

// Sets default values
AFishingGenerator::AFishingGenerator()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AFishingGenerator::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFishingGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFishingGenerator::InitialGeneration()
{
	for (int i = 0; i < xFishingSpots.Num(); i++)
	{
		for (int j = 0; j < xFishingSpots[i]->iTotalFishes; j++)
		xFishingSpots[i]->xFishes[j] = AllocateFish();
	}

	for (int i = 0; i < iSpotsAvailableAtSpawn; i++)
	{
		int RandomInt = FMath::RandRange(0, xFishingSpots.Num());
		if (!xFishingSpots[i]->bIsActive)
		{
			xFishingSpots[i]->bIsActive = true;
		}
		else i--;
	}
}

void AFishingGenerator::ShuffleSpots(AFishingSpot depletedSpot)
{
	depletedSpot.bIsActive = false;

	int randomInt;
	
	do
	{
		randomInt = FMath::RandRange(0, xFishingSpots.Num());
	}
	while (!xFishingSpots[randomInt]->bIsActive);

	xFishingSpots[randomInt]->bIsActive = true;
}

UFish* AFishingGenerator::AllocateFish()
{
	UFish* fish;
	return fish;
}

void AFishingGenerator::ChooseFish()
{
}

