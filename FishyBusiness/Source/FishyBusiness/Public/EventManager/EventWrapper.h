// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EventList.h"
#include "EventWrapper.generated.h"


class UObserverManager;
class UParameterWrapper;
using EventParameters = TArray<UParameterWrapper*>;
using Function = TFunction<void(EventParameters)>;

UCLASS()
class FISHYBUSINESS_API UEventWrapper : public UObject
{
	GENERATED_BODY()
public:
	Function function;

	static void RegisterEvent(UObserverManager* EventManager, FString EventType, TFunction<void(EventParameters)> Callback);
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

template <typename T>
UParameterWrapper* UParameterWrapper::CreateParameter(T &data)
{
	UParameterWrapper* parameter = nullptr;
	parameter->Setter<T>(data);
	return parameter;
}


