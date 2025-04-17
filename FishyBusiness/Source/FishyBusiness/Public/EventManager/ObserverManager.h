// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <any>

#include "CoreMinimal.h"
#include "EventWrapper.h"
#include "Components/ActorComponent.h"
#include "ObserverManager.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FISHYBUSINESS_API UEventBus : public UActorComponent
{
	GENERATED_BODY()
private:
	TMap<FString, TArray<TStrongObjectPtr<UEventWrapper>>> _xEventMap;
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	UEventBus();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/// <summary>
	/// Registers a function event to the event map for a given event name.
	/// </summary>
	/// <param name="eventName">The name of the event to register the function for.</param>
	/// <param name="functionEvent">The function event wrapper pointer to register.</param>
	void Register(FString eventName, TStrongObjectPtr<UEventWrapper> functionEvent);

	/// <summary>
	/// Unregisters a function event from the event map for a given event name.
	/// </summary>
	/// <param name="eventName">The name of the event to unregister the function from.</param>
	/// <param name="functionEvent">The function event wrapper pointer to unregister.</param>
	void Unregister(FString eventName, TStrongObjectPtr<UEventWrapper> functionEvent);
	
	/// <summary>
	/// Calls all registered function events for a given event name, passing event parameters.
	/// </summary>
	/// <param name="eventName">The name of the event to trigger.</param>
	/// <param name="parameters">The reference to parameters to pass to the function events.</param>
	void TriggerEvent(FString eventName, EventParameters &parameters);

private:
	bool CheckPrecondition(FString eventName, TStrongObjectPtr<UEventWrapper> functionEvent);
};
