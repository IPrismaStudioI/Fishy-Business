// Fill out your copyright notice in the Description page of Project Settings.


#include "EventManager/ObserverManager.h"

UObserverManager::UObserverManager()
{
}

void UObserverManager::Register(FString eventName, UFunctionWrapper* functionEvent)
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

void UObserverManager::Unregister(FString eventName, UFunctionWrapper* functionEvent)
{
	if (!CheckPrecondition(eventName, functionEvent)) return;
	if (_xEventMap.Contains(eventName))
	{
		int i = _xEventMap[eventName].Find(functionEvent);
		_xEventMap[eventName].RemoveAt(i);
	}
}

void UObserverManager::TriggerEvent(FString eventName, EventParameters &parameters)
{
	if (_xEventMap.Contains(eventName))
	{
		for (auto Element : _xEventMap[eventName])
		{
			Element->function(parameters);
		}
	}
}


bool UObserverManager::CheckPrecondition(FString eventName, UFunctionWrapper* functionEvent)
{
	if (functionEvent == nullptr) return false;
	if (eventName.IsEmpty()) return false;
	return true;
}
