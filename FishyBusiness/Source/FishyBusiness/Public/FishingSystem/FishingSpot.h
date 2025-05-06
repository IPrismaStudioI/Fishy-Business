// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FishingMinigame.h"
#include "FishingReward.h"
#include "DataSystem/FishData/Fish.h"
#include "GameFramework/Actor.h"
#include "FishingSystem/FishingGenerator.h"
#include "PlayerSystem/PlayerCharacter.h"
#include "FishingSpot.generated.h"

UCLASS()
class FISHYBUSINESS_API AFishingSpot : public AActor
{
	GENERATED_BODY()

private:
	int _iCurrentFishes;
	UPROPERTY()
	bool _bCanCreateMinigame = false;
	bool _bHasPlayerInteracted = false;
	APlayerCharacter* xPlayerCharacter;

public:
	UPROPERTY(BlueprintReadWrite)
	TArray<UFishingMinigame*> ActiveWidget;

	UPROPERTY(BlueprintReadWrite)
	UFishingReward* xRewardWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USphereComponent* xSphereTrigger;
	
	UPROPERTY(EditAnywhere)
	TArray<FString> xFishes;

	UPROPERTY(EditAnywhere)
	int iTotalFishes;

	bool bIsActive = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UFishingMinigame> xFishingMinigame;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UFishingReward> xFishingReward;

	UPROPERTY()
	AFishingGenerator* xFishingGenerator;

private:
	UPROPERTY(EditAnywhere, Category = "Camera Zoom")
	float _fNewCameraSize;
	UPROPERTY(EditAnywhere, Category = "Camera Zoom")
	float _fLerpSpeed;
	float _fOldCameraSize;
	
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Sets default values for this actor's properties
	AFishingSpot();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	void ToggleActive(bool value);

	UFUNCTION(BlueprintCallable, Category = "MyFunctions")
	void FinishedMinigame(bool hasWon);

	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, 
						UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, 
						bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
					  UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnOverlapFishingSpot();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnInteractFishingSpot();

private:
	void OnInteractFishing();
};
