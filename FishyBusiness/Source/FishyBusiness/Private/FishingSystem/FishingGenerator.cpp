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

UFish* AFishingGenerator::AllocateFish()
{
	int randomInt = FMath::RandRange(0, xAvailableFishes.Num() -1);
	//randomInt = 2;
	return xAvailableFishes[randomInt];
}

void AFishingGenerator::InitialGeneration()
{
	int randInt = 6;
	for (int i = 0; i < xFishingSpots.Num(); i++)
	{
		//randInt = FMath::RandRange(1, xFishingSpots[i]->iTotalFishes);
		
		for (int j = 0; j < randInt; j++)
		{
			xFishingSpots[i]->xFishes[j] = AllocateFish();
		}
		xFishingSpots[i]->xFishingGenerator = this;
		xFishingSpots[i]->ToggleActive(false);
	}

	for (int i = 0; i < iSpotsAvailableAtSpawn; i++)
	{
		int RandomInt = FMath::RandRange(0, iSpotsAvailableAtSpawn);
		if (!xFishingSpots[RandomInt]->bIsActive)
		{
			xFishingSpots[RandomInt]->ToggleActive(true);
		}
		else i--;
	}
}

void AFishingGenerator::ShuffleSpots(AFishingSpot* depletedSpot)
{
	depletedSpot->ToggleActive(false);

	int randomInt;
	
	do
	{
		randomInt = FMath::RandRange(0, xFishingSpots.Num());
	}
	while (!xFishingSpots[randomInt]->bIsActive);

	xFishingSpots[randomInt]->bIsActive = true;
	int randInt = FMath::RandRange(1, xFishingSpots[randomInt]->iTotalFishes);
	for (int j = 0; j < randInt; j++)
	{
		xFishingSpots[randomInt]->xFishes[j] = AllocateFish();
	}
}


