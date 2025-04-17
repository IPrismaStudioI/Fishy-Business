// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FishBehaviour.generated.h"

/**
 * 
 */
UCLASS()
class FISHYBUSINESS_API UFishBehaviour : public UPrimaryDataAsset
{
	GENERATED_BODY()

	public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float fMinDuration;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float fMaxDuration;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float fMaxSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float fAcceleration;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float fDirection;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float fDirectionMultiplier;
};
