// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EventList.h"
#include "EventWrapper.generated.h"


class UEventBus;
class UParameterWrapper;
using EventParameters = TArray<UParameterWrapper*>;
using Function = TSharedPtr<TFunction<void(const EventParameters&)>>;

UCLASS()
class FISHYBUSINESS_API UEventWrapper : public UObject
{
	GENERATED_BODY()
public:
	Function function;

	/// <summary>Registers an event callback with the specified observer manager.
	/// <para>
	/// @param EventManager - The observer manager pointer that will handle the event.
	/// </para>
	/// <para>
	/// @param EventType - The name of the event to register the callback for.
	/// </para>
	/// @param Callback - The function to execute when the event is triggered.
	/// </summary>
	static void RegisterEvent(UEventBus* EventManager, FString EventType, TSharedPtr<TFunction<void(const EventParameters&)>> Callback);
};

UCLASS()
class FISHYBUSINESS_API UParameterWrapper : public UObject
{
	GENERATED_BODY()
private:
	FVariant _xData;
	const std::type_info* TypeInfo;
	
public:
	template <typename T>
	void Setter(T data)
	{
		_xData = data;
		TypeInfo = &typeid(T);
	}

	template <typename T>
	T Getter()
	{
		if (*TypeInfo != typeid(T))
		{
			return T();
		}
		return _xData;
	}

	template <typename T>
	static UParameterWrapper* CreateParameter(T &data);
};


/// <summary>Creates and returns a new ParameterWrapper pointer instance and sets its value.
/// <para>
/// @tparam T - The type of the data to be stored in the parameter wrapper.
/// </para>
/// @param data - The data to store in the wrapper.
/// </summary>
template <typename T>
UParameterWrapper* UParameterWrapper::CreateParameter(T &data)
{
	UParameterWrapper* parameter = NewObject<UParameterWrapper>();
	parameter->Setter<T>(data);
	return parameter;
}


