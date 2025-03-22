// Fill out your copyright notice in the Description page of Project Settings.


#include "EventManager/FunctionWrapper.h"
#include "EventManager/ObserverManager.h"

void UFunctionWrapper::RegisterEvent(UObserverManager* EventManager, FString EventType, const TFunction<void(EventParameters)>& Callback)
{
	UFunctionWrapper* Wrapper = nullptr;
	Wrapper->function = Callback;
	EventManager->Register(EventType, Wrapper);
}