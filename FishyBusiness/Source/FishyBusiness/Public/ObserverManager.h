// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <any>

#include "CoreMinimal.h"

using EventParameters = TArray<std::any>;
using Function = TFunction<void(EventParameters)>;

class FISHYBUSINESS_API ObserverManager
{
private:
	TMap<FString, TArray<Function>> _xEventMap;
public:	
	ObserverManager();
	~ObserverManager();

	void Register(FString eventName, Function functionEvent);
	void Unregister(FString eventName, Function functionEvent);
	void TriggerEvent(FString eventName, EventParameters parameters);

private:
	bool CheckPrecondition(FString eventName, Function functionEvent);
};
