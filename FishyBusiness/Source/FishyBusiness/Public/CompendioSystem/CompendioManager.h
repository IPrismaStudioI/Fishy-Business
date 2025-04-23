// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CompendioManager.generated.h"

UCLASS()
class FISHYBUSINESS_API ACompendioManager : public AActor
{
	GENERATED_BODY()
	
private:
	bool _bIsOpen = false;
	UPROPERTY()
	UMainCompendio* _xMainCompendio;
	int _iActualPageIndex;
	TArrayTSubclassOf<UCompendioPageBase> test
	
public:	
	// Sets default values for this actor's properties
	ACompendioManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
