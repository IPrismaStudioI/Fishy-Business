// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <any>

#include "CoreMinimal.h"
#include "FunctionWrapper.h"
#include "ObserverManager.generated.h"

UCLASS()
class FISHYBUSINESS_API UObserverManager : public UObject
{
	GENERATED_BODY()
private:
	TMap<FString, TArray<UFunctionWrapper*>> _xEventMap;
public:	
	UObserverManager();

	void Register(FString eventName, UFunctionWrapper* functionEvent);
	void Unregister(FString eventName, UFunctionWrapper* functionEvent);
	void TriggerEvent(FString eventName, EventParameters &parameters);

private:
	bool CheckPrecondition(FString eventName, UFunctionWrapper* functionEvent);
};
