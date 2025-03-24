// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <any>

#include "CoreMinimal.h"
#include "EventWrapper.h"
#include "Components/ActorComponent.h"
#include "ObserverManager.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FISHYBUSINESS_API UObserverManager : public UActorComponent
{
	GENERATED_BODY()
private:
	TMap<FString, TArray<UEventWrapper*>> _xEventMap;
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	UObserverManager();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void Register(FString eventName, UEventWrapper* functionEvent);
	void Unregister(FString eventName, UEventWrapper* functionEvent);
	void TriggerEvent(FString eventName, EventParameters &parameters);

private:
	bool CheckPrecondition(FString eventName, UEventWrapper* functionEvent);
};
