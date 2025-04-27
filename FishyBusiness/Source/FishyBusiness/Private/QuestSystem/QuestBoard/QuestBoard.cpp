// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestSystem/QuestBoard/QuestBoard.h"

#include "QuestSystem/QuestBoard/QuestBoardUI.h"
#include "VillageSystem/Widget/CarpenterBuildingWidget.h"

UQuestBoard::UQuestBoard()
{

	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UQuestBoard::BeginPlay()
{
	Super::BeginPlay();
	
	UUserWidget* questBoardUI = CreateWidget(GetWorld(), _xQuestBoardUI);
	questBoardUI->AddToViewport(1);

	for (auto Element : Cast<UQuestBoardUI>(questBoardUI)->xQuestItemUIList)
	{
		_mQuestUIElements.Add(Element, FQuestUIElement());
		_mQuestUIElements[Element].bIsActive = false;
	}
}


// Called every frame
void UQuestBoard::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

