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
	// Sets default values for this actor's properties
	AFishingGenerator();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	TArray<UFish*> xAvailableFishes;

	UPROPERTY(EditAnywhere)
	TArray<AFishingSpot*> xFishingSpots;

	UPROPERTY(EditAnywhere)
	int iSpotsAvailableAtSpawn = 0;

private:
	void InitialGeneration();
	void ShuffleSpots(AFishingSpot depletedSpot);
	UFish* AllocateFish();
	void ChooseFish();
};
