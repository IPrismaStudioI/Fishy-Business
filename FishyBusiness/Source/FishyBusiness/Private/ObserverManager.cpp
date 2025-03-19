// Fill out your copyright notice in the Description page of Project Settings.


#include "ObserverManager.h"

ObserverManager::ObserverManager()
{
}

ObserverManager::~ObserverManager()
{
}

void ObserverManager::Register(FString eventName, Function functionEvent)
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

void ObserverManager::Unregister(FString eventName, Function functionEvent)
{
	if (!CheckPrecondition(eventName, functionEvent)) return;
	if (_xEventMap.Contains(eventName))
	{
		_xEventMap[eventName].Remove(functionEvent);
	}
}

void ObserverManager::TriggerEvent(FString eventName, EventParameters parameters)
{
	if (_xEventMap.Contains(eventName))
	{
		for (auto Element : _xEventMap[eventName])
		{
			Element(parameters);
		}
	}
}


bool ObserverManager::CheckPrecondition(FString eventName, Function functionEvent)
{
	if (functionEvent == nullptr) return false;
	if (eventName.IsEmpty()) return false;
	return true;
}
