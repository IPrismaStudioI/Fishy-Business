// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataSystem/ItemData/BaseItem.h"
#include "EventManager/EventWrapper.h"
#include "GameFramework/Actor.h"
#include "ItemObject.generated.h"

UCLASS()
class FISHYBUSINESS_API AItemObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	APlayerCharacter* xPlayerCharacter;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USphereComponent* xSphereTrigger;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// UPROPERTY(EditAnywhere)
	// FString sItemID;
	//
	// UPROPERTY(EditAnywhere)
	// int iItemAmount;

	UPROPERTY(EditAnywhere)
	TMap<FString, int> xItems;
	
	void OnInteractEvent(EventParameters params);

	void OnInteract();

	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, 
						UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, 
						bool bFromSweep, const FHitResult& SweepResult);
	
	
};
