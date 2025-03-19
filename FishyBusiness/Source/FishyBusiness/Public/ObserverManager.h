// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <any>
#include <functional>

#include "CoreMinimal.h"

/**
 * 
 */
class FISHYBUSINESS_API ObserverManager
{
private:
	TMap<FString, TArray<std::function<void(TArray<std::any>)>>> _EventMap;
public:
	ObserverManager();
	~ObserverManager();
};
