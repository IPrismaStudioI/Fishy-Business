// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EventWrapper.h"

/**
 * 
 */

class FISHYBUSINESS_API EventListDialogue
{
public:
	static const FString CHANGE_SENTENCE;
	static const FString CHANGE_NAME;
	static const FString START_DIALOGUE;
	static const FString END_DIALOGUE;
	static const FString START_CHOICES;
	static const FString HIDE_CHOICES;
	static const FString CONTINUE_DIALOGUE;
};

class FISHYBUSINESS_API EventListVillage
{
public:
	static const FString SHOW_LIGHTHOUSE;
	static const FString SHOW_FISHSHOP;
	static const FString SHOW_WORKSHOP;
	static const FString SHOW_ARCHIVE;
	static const FString SHOW_CARPENTRY;
};