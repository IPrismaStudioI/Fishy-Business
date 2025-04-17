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

void UEventBus::Register(FString eventName, TStrongObjectPtr<UEventWrapper> functionEvent)
{
	if (!CheckPrecondition(eventName, functionEvent)) return;
	if (_xEventMap.Contains(eventName))
		_xEventMap[eventName].Add(MoveTemp(functionEvent));
	else
	{
		_xEventMap.Add(eventName);
		_xEventMap[eventName].Add(MoveTemp(functionEvent));
	}
}

void UEventBus::Unregister(FString eventName, TStrongObjectPtr<UEventWrapper> functionEvent)
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
		for (TStrongObjectPtr<UEventWrapper> Element : _xEventMap[eventName])
		{
			if (Element && Element->function.IsValid() && *Element->function)
			{
				UE_LOG(LogTemp, Warning, TEXT("This: '%p'"), this);
				(*Element->function)(parameters);
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("EventBus: Invalid function or element for event '%s'"), *eventName);
			}
		}
	}
}




bool UEventBus::CheckPrecondition(FString eventName, TStrongObjectPtr<UEventWrapper> functionEvent)
{
	if (functionEvent == nullptr) return false;
	if (eventName.IsEmpty()) return false;
	return true;
}
