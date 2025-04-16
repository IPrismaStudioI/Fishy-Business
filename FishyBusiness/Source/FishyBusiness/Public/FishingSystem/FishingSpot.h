// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FishingMinigame.h"
#include "DataSystem/FishData/Fish.h"
#include "GameFramework/Actor.h"
#include "FishingSystem/FishingGenerator.h"
#include "FishingSpot.generated.h"

UCLASS()
class FISHYBUSINESS_API AFishingSpot : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFishingSpot();

private:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	bool _bCanCreateMinigame = false;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USphereComponent* xSphereTrigger;
	
	UPROPERTY(EditAnywhere)
	TArray<UFish*> xFishes;

	UPROPERTY(EditAnywhere)
	int iTotalFishes;

	bool bIsActive = false;

	void ToggleActive(bool value);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UFishingMinigame> xFishingMinigame;

	UFUNCTION(BlueprintCallable, Category = "MyFunctions")
	void FinishedMinigame();
	
	AFishingGenerator* xFishingGenerator;

private:
	UFishingMinigame* ActiveWidget;

	int iCurrentFishes;

private:
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, 
						UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, 
						bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
					  UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};
