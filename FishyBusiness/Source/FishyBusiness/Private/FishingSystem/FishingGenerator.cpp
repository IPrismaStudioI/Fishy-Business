// Fill out your copyright notice in the Description page of Project Settings.


#include "FishingSystem/FishingGenerator.h"
#include "Math/RandomStream.h"
#include "Misc/DateTime.h"
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

	//const int32 Seed= FDateTime::GetMillisecond();
	//const FRandomStream RandomStream(Seed);
	//const float Min = -50;
	//const float Max = 50;
	//const float rnd = RandomStream.RandRange(Min,Max);
	
	//Box-Muller transformation for gaussian distribution: calcoliamo il valore del peso da una distribuzione gaussiana
	//utilizzando una box-muller transformation, che genera
	//una distribuzione uniforme e poi la mappa in gaussiana con l'aiuto del seno.
	//Documentazione di riferimento: https://en.wikipedia.org/wiki/Box%E2%80%93Muller_transform e https://stackoverflow.com/questions/218060/random-gaussian-variables

	float u1 = 1.0 - FMath::FRandRange(0.0, 1.0);
	float u2 = 1.0 - FMath::FRandRange(0.0, 1.0);
	float randStdNormal = FMath::Sqrt(-2.0 * FMath::LogX(10, u1)) * FMath::Sin(2.0 * PI * u2);
	float randNormal = fish->fBaseSize + 4 * rarityCorrector * randStdNormal;

	UE_LOG(LogTemp, Error , TEXT("Generated fish: %s"), *fish->sFishName);
	UE_LOG(LogTemp, Error , TEXT("Generated: %f"), randNormal);


	return randNormal;
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
	
	return FFishData(id, price, size);
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


