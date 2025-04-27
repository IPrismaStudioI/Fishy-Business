// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "QuestUnlockStorageManager.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FISHYBUSINESS_API UQuestUnlockStorageManager : public UActorComponent
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere)
	TArray<FString> _sUnlockedQuestList;
	
public:	
	// Sets default values for this component's properties
	UQuestUnlockStorageManager();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
