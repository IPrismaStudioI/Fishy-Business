// Fill out your copyright notice in the Description page of Project Settings.


#include "EventManager/ObserverManager.h"

UEventBus::UEventBus()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UEventBus::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UEventBus::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UEventBus::Register(FString eventName, UEventWrapper* functionEvent)
{
	if (!CheckPrecondition(eventName, functionEvent)) return;
	if (_xEventMap.Contains(eventName))
		_xEventMap[eventName].Add(functionEvent);
	else
	{
		_xEventMap.Add(eventName);
		_xEventMap[eventName].Add(functionEvent);
	}
}

void UEventBus::Unregister(FString eventName, UEventWrapper* functionEvent)
{
	if (!CheckPrecondition(eventName, functionEvent)) return;
	if (_xEventMap.Contains(eventName))
	{
		int i = _xEventMap[eventName].Find(functionEvent);
		_xEventMap[eventName].RemoveAt(i);
	}
}

void UEventBus::TriggerEvent(FString eventName, EventParameters &parameters)
{
	if (_xEventMap.Contains(eventName))
	{
		for (UEventWrapper* Element : _xEventMap[eventName])
		{
			(*Element->function)(parameters);
		}
	}
}


bool UEventBus::CheckPrecondition(FString eventName, UEventWrapper* functionEvent)
{
	if (functionEvent == nullptr) return false;
	if (eventName.IsEmpty()) return false;
	return true;
}
