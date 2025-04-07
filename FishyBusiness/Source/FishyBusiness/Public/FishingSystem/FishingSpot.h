// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FishingSpot.generated.h"

UCLASS()
class FISHYBUSINESS_API AFishingSpot : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFishingSpot();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	TArray<UFish*> xFishes;

	UPROPERTY(EditAnywhere)
	int iTotalFishes;

	bool bIsActive = false;
};
