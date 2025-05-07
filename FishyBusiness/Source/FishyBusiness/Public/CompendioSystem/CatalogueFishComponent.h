// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CatalogueFishComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FISHYBUSINESS_API UCatalogueFishComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TMap<FString, bool> _xFishCatalogued;
	
public:	
	// Sets default values for this component's properties
	UCatalogueFishComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
