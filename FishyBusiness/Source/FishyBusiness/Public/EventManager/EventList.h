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
	/// <summary>
	/// no parameters
	/// </summary>
	static const FString SHOW_LIGHTHOUSE;
	
	/// <summary>
	/// no parameters
	/// </summary>
	static const FString SHOW_FISHSHOP;

	/// <summary>
	/// no parameters
	/// </summary>
	static const FString SHOW_WORKSHOP;

	/// <summary>
	/// no parameters
	/// </summary>
	static const FString SHOW_ARCHIVE;

	/// <summary>
	/// no parameters
	/// </summary>
	static const FString SHOW_CARPENTRY;

	/// <summary>
	/// no parameters
	/// </summary>
	static const FString SHOW_VILLAGE_BASE;

	/// <summary>
	/// no parameters
	/// </summary>
	static const FString HIDE_VILLAGE_BASE;

	/// <summary>
	/// no parameters
	/// </summary>
	static const FString SHOW_MENU;
};

class FISHYBUSINESS_API EventListQuest
{
public:
	/// <summary>
	/// no parameters
	/// </summary>
	static const FString SHOW_QUEST_BOARD;
	
	/// <summary>
	/// no parameters
	/// </summary>
	static const FString FILL_BULLETIN;
	
	/// <summary>
	/// FString id
	/// </summary>
	static const FString UI_ADD_QUEST;
	
	/// <summary>
	/// FString id
	/// </summary>
	static const FString ADD_QUEST;

	/// <summary>
	/// FString id
	/// </summary>
	static const FString GET_REWARD;
};

class FISHYBUSINESS_API EventListCompendio
{
public:
	static const FString CREATE_PAGE;
	static const FString OPEN_CLOSE_COMPENDIO;
	static const FString CATALOGUE_FISH;
};