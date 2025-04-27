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
	static const FString CONTINUE_DIALOGUE;
	static const FString CLOSE_DIALOGUE;
	static const FString END_DIALOGUE;
	static const FString START_CHOICES;
	static const FString HIDE_CHOICES;
};

class FISHYBUSINESS_API EventListVillage
{
public:
	static const FString SHOW_LIGHTHOUSE;
	static const FString SHOW_FISHSHOP;
	static const FString SHOW_WORKSHOP;
	static const FString SHOW_ARCHIVE;
	static const FString SHOW_CARPENTRY;
	static const FString SHOW_VILLAGE_BASE;
	static const FString HIDE_VILLAGE_BASE;
	static const FString SHOW_MENU;
};

class FISHYBUSINESS_API EventListCompendio
{
public:
	static const FString CREATE_PAGE;
	static const FString OPEN_CLOSE_COMPENDIO;
	static const FString CATALOGUE_FISH;
};