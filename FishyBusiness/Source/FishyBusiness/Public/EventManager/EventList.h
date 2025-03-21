// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FunctionWrapper.h"

/**
 * 
 */

class FISHYBUSINESS_API EventListDialogue
{
public:
	static const FString CHANGE_SENTENCE;
	template <typename T>
	static EventParameters trigger(T parameter);
};

template <typename T>
EventParameters EventListDialogue::trigger(T parameter)
{
	UParameterWrapper* parameter = nullptr;
	EventParameters eventParameters;
	parameter->Setter<T>(parameter);
	eventParameters.Add(parameter);

	return eventParameters;
}
