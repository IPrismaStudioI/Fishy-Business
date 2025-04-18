// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestSystem/AC_QuestLog.h"

#include "QuestSystem/QuestData/QuestRow.h"

// Sets default values for this component's properties
UAC_QuestLog::UAC_QuestLog()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAC_QuestLog::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAC_QuestLog::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UAC_QuestLog::AddQuest(FString questID)
{
	FQuestRow* questRow = xQuestDT->FindRow<FQuestRow>(FName(questID), "");
	//FPlayerQuest playerQuest; //= FPlayerQuest(questRow->xModuleList, 0, EQuestStatus::E_ACTIVE_QUEST);
	if (xQuests.Find(questID) == nullptr)
	{
		xQuests.Add(questID, FPlayerQuest(questRow->xModuleList));
	}
}

