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

private:
	UFishingMinigame* ActiveWidget;
	int _iCurrentFishes;
	bool _bCanCreateMinigame = false;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USphereComponent* xSphereTrigger;
	
	UPROPERTY(EditAnywhere)
	TArray<FString> xFishes;

	UPROPERTY(EditAnywhere)
	int iTotalFishes;

	bool bIsActive = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UFishingMinigame> xFishingMinigame;

	UPROPERTY()
	AFishingGenerator* xFishingGenerator;

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
	void FinishedMinigame();

	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, 
						UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, 
						bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
					  UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};
