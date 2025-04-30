// Fill out your copyright notice in the Description page of Project Settings.


#include "VillageSystem/QuestBuilding.h"

AQuestBuilding::AQuestBuilding()
{
	_xQuestBoard = CreateDefaultSubobject<UQuestBoard>("Quest Board");
	this->AddInstanceComponent(_xQuestBoard);
}
