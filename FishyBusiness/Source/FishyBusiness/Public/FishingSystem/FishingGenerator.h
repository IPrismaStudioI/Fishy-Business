// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataSystem/FishData/Fish.h"
#include "GameFramework/Actor.h"
#include "FishingGenerator.generated.h"

class AFishingSpot;

UCLASS()
class FISHYBUSINESS_API AFishingGenerator : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	TArray<FString> xAvailableFishIDs;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<AFishingSpot*> xFishingSpots;

	UPROPERTY(EditAnywhere)
	int iSpotsAvailableAtSpawn = 0;

private:
	void InitialGeneration();
	FString AllocateFish();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Sets default values for this actor's properties
	AFishingGenerator();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	void ShuffleSpots(AFishingSpot* depletedSpot);

};
