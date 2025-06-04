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

	/// <summary>
	/// no params
	/// </summary>
	static const FString ESC_VILLAGE;
	
	/// <summary>
	/// no params
	/// </summary>
	static const FString ENTER_BUILDING;

	/// <summary>
	/// EBuildingStatus new status
	/// </summary>
	static const FString RESTORE_CARPENTRY;
	/// <summary>
	/// EBuildingStatus new status
	/// </summary>
	static const FString RESTORE_LIGHTHOUSE;
	/// <summary>
	/// EBuildingStatus new status
	/// </summary>
	static const FString RESTORE_FISHSHOP;
	/// <summary>
	/// EBuildingStatus new status
	/// </summary>
	static const FString RESTORE_WORKSHOP;
	/// <summary>
	/// EBuildingStatus new status
	/// </summary>
	static const FString RESTORE_ARCHIVE;
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
	/// int zone 
	/// </summary>
	static const FString ADVANCE_EXPLORE;

	/// <summary>
	/// int npc name, FString id, int moduleIndex
	/// </summary>
	static const FString ADVANCE_INTERACT;

	/// <summary>
	/// FString item id, int amount
	/// </summary>
	static const FString ADVANCE_COLLECT;

	///<summary>
	///FString id quest
	///</summary>
	static const FString GET_REWARD;

	///<summary>
	///FString quest id, int task array pos
	///</summary>
	static const FString UPDATE_UI_TASK;
	
	///<summary>
	///Used to hide the quest task in ui
	///</summary>
	static const FString HIDE_UI_TASK;
	
	///<summary>
	///int enum id
	///</summary>
	static const FString CALL_NOTIFY;

	///<summary>
	///int enum id
	///</summary>
	static const FString CALL_DENOTIFY;

	///<summary>
	///no params
	///</summary>
	static const FString FILL_QUEST_BOARD;

	///<summary>
	///string quest id
	///</summary>
	static const FString REMOVE_QUEST_FROM_BOARD;
};

class FISHYBUSINESS_API EventListCompendio
{
public:
	static const FString CREATE_PAGE;
	static const FString OPEN_CLOSE_COMPENDIO;
	static const FString CLOSE_COMPENDIO;
	static const FString CATALOGUE_FISH;
	static const FString NEXT_PAGE;
	static const FString PREV_PAGE;
};

class FISHYBUSINESS_API EventListInput
{
public:
	static const FString START_FISHING_INPUT;
	static const FString OPEN_COMPENDIO_INPUT;
	static const FString CLOSE_COMPENDIO_INPUT;
	static const FString NEXT_COMPENDIO_PAGE_INPUT;
	static const FString PREV_COMPENDIO_PAGE_INPUT;
	static const FString CLOSE_VILLAGE_INPUT;
	static const FString MOVE_FORWARD_INPUT;
	static const FString MOVE_RIGHT_INPUT;
};