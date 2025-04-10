// Fill out your copyright notice in the Description page of Project Settings.


#include "EventManager/EventWrapper.h"
#include "EventManager/ObserverManager.h"

void UEventWrapper::RegisterEvent(UEventBus* EventManager, FString EventType, TSharedPtr<TFunction<void(const EventParameters&)>> Callback)
{
	UEventWrapper* Wrapper = NewObject<UEventWrapper>();
	Wrapper->function = Callback;
	EventManager->Register(EventType, Wrapper);
}