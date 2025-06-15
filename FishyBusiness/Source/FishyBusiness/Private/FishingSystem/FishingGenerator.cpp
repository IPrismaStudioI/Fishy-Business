// Fill out your copyright notice in the Description page of Project Settings.


#include "FishingSystem/FishingGenerator.h"

#include "FishingSystem/FishingSpot.h"
#include "FishyBusiness/FishyBusinessGameModeBase.h"

class AFishyBusinessGameModeBase;
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

float AFishingGenerator::AllocateSize(FString fishID)
{
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	UFish* fish = gamemode->GetFishFromDT(fishID);

	float corrector = fish->fSizeCorrector * 0.1;
	float rarityCorrector = corrector * static_cast<int>(fish->eRarity);
	float rnd = FMath::RandRange(-50.0, 50.0);
	float x = rarityCorrector * FMath::Pow( rnd, 1/3) + 1;
	
	return x * fish->fBaseSize;
}

float AFishingGenerator::AllocatePrice(FString fishID, float fishSize)
{
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	UFish* fish = gamemode->GetFishFromDT(fishID);
	
	float base = (fishSize - fish->fBaseSize) / fish->fBaseSize;
	float pow = FMath::Pow(base, 3.0);

	float correctorBase = pow * 4.0 * fish->fPriceCorrector * 0.4;
	float correctorexp = 1/3;
	float correctorPow = FMath::Pow(correctorBase, correctorexp);
	
	return (correctorPow + 1.0) * fish->fBasePrice;
}

FFishData AFishingGenerator::CreateNewFish()
{
	FString id = AllocateFish();
	float size = AllocateSize(id);
	float price = AllocatePrice(id, size);
	
	return FFishData(id, size, price);
}

void AFishingGenerator::InitialGeneration()
{
	for (int i = 0; i < xFishingSpots.Num(); i++)
	{

		int total = xFishingSpots[i]->iTotalFishes;
		for (int j = 0; j < total; j++)
		{
			xFishingSpots[i]->xFishes.Add(CreateNewFish());
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
		xFishingSpots[randomInt]->xFishes[j] = CreateNewFish();
	}
}


