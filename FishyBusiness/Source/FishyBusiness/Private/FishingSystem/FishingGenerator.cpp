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
	InitialGeneration();
}

// Called every frame
void AFishingGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FString AFishingGenerator::AllocateFish()
{
	int randomInt = FMath::RandRange(0, xAvailableFishIDs.Num() -1);
	//randomInt = 2;
	return xAvailableFishIDs[randomInt];
}

void AFishingGenerator::InitialGeneration()
{
	for (int i = 0; i < xFishingSpots.Num(); i++)
	{

		int total = xFishingSpots[i]->iTotalFishes;
		for (int j = 0; j < total; j++)
		{
			xFishingSpots[i]->xFishes.Add(AllocateFish());
		}
		xFishingSpots[i]->xFishingGenerator = this;
		xFishingSpots[i]->ToggleActive(false);
	}

	for (int k = 0; k < iSpotsAvailableAtSpawn; k++)
	{
		int RandInt = FMath::RandRange(0, xFishingSpots.Num() -1);
		if (!xFishingSpots[RandInt]->bIsActive)
		{
			xFishingSpots[RandInt]->ToggleActive(true);
		}
		else k--;
	}
}

void AFishingGenerator::ShuffleSpots(AFishingSpot* depletedSpot)
{
	int randomInt;
	
	do
	{
		randomInt = FMath::RandRange(0, xFishingSpots.Num() - 1);
	}
	while (xFishingSpots[randomInt]->bIsActive);

	if (xFishingSpots[randomInt] != depletedSpot)
	{
		depletedSpot->ToggleActive(false);
		OnShuffleSpots();
	}

	xFishingSpots[randomInt]->ToggleActive(true);

	int randInt = FMath::RandRange(1, xFishingSpots[randomInt]->iTotalFishes);
	for (int j = 0; j < randInt; j++)
	{
		xFishingSpots[randomInt]->xFishes[j] = AllocateFish();
	}
}


