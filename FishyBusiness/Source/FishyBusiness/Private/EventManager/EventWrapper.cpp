// Fill out your copyright notice in the Description page of Project Settings.


#include "EventManager/EventWrapper.h"
#include "EventManager/ObserverManager.h"

void UEventWrapper::RegisterEvent(UObserverManager* EventManager, FString EventType, const TFunction<void(EventParameters)> Callback)
{
	UEventWrapper* Wrapper = NewObject<UEventWrapper>();
	Wrapper->function = MakeShared<TFunction<void(EventParameters)>>(Callback);
	EventManager->Register(EventType, Wrapper);
}