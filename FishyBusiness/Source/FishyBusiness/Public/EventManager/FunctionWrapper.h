// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FunctionWrapper.generated.h"


class UParameterWrapper;
using EventParameters = TArray<UParameterWrapper*>;
using Function = TFunction<void(EventParameters)>;

UCLASS()
class FISHYBUSINESS_API UFunctionWrapper : public UObject
{
	GENERATED_BODY()
public:
	Function function;
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
};


