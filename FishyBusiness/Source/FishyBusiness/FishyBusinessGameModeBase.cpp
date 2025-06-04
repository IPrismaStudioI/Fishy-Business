// Fill out your copyright notice in the Description page of Project Settings.


#include "FishyBusinessGameModeBase.h"

#include "DataTables/DialogueRow.h"
#include "DataTables/FishRow.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerSystem/PlayerCharacter.h"
#include "QuestSystem/QuestDataManager.h"

AFishyBusinessGameModeBase::AFishyBusinessGameModeBase()
{
	xQuestDataManager = CreateDefaultSubobject<UQuestDataManager>("Quest Data Manager");
	this->AddInstanceComponent(xQuestDataManager);

	xQuestDataManager->SetXFishyBusinessGameMode(this);
	
	xDialogueElaborator = CreateDefaultSubobject<UDialogueElaborator>("Dialogue Elaborator");
	this->AddInstanceComponent(xDialogueElaborator);
	xQuestUnlockStorageManager = CreateDefaultSubobject<UQuestUnlockStorageManager>("Quest Unlock Storage Manager");
	this->AddInstanceComponent(xQuestUnlockStorageManager);
	xCatalogueFishComponent = CreateDefaultSubobject<UCatalogueFishComponent>("Catalogue Fish Component");
	this->AddInstanceComponent(xCatalogueFishComponent);
	xInputManagerComponent = CreateDefaultSubobject<UInputManagerComponent>("Input Manager Component");
	this->AddInstanceComponent(xInputManagerComponent);
	
	xDialogueEventBus = CreateDefaultSubobject<UEventBus>("Dialogue Bus");
	this->AddInstanceComponent(xDialogueEventBus);
	xVillageEventBus = CreateDefaultSubobject<UEventBus>("Village Bus");
	this->AddInstanceComponent(xVillageEventBus);
	xCompendioEventBus = CreateDefaultSubobject<UEventBus>("Compendio Bus");
	this->AddInstanceComponent(xCompendioEventBus);
	xQuestEventBus = CreateDefaultSubobject<UEventBus>("Quest Bus");
	this->AddInstanceComponent(xQuestEventBus);
	xInputEventBus = CreateDefaultSubobject<UEventBus>("Input Bus");
	this->AddInstanceComponent(xInputEventBus);

	DefaultPawnClass = APlayerCharacter::StaticClass();
}

void AFishyBusinessGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	
	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	if (PC)
	{
		PC->bShowMouseCursor = true; 
		PC->bEnableClickEvents = true; 
		PC->bEnableMouseOverEvents = true;
	}
}

void AFishyBusinessGameModeBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

AFishyBusinessGameModeBase* AFishyBusinessGameModeBase::GetInstance()
{
	UEngine* g = GEngine;
	AFishyBusinessGameModeBase* gamemode = GEngine->GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	return gamemode;
}

UDA_Dialogue* AFishyBusinessGameModeBase::GetDialogueFromDT(FString id)
{
	FDialogueRow* row = xDataTableDialogues->FindRow<FDialogueRow>(FName(id), "");
	if (!row)
	{
		UE_LOG(LogTemp, Error, TEXT("Dialogue Row not fund"));
		return nullptr;
	}
	return row->xDialogue;
}

UFish* AFishyBusinessGameModeBase::GetFishFromDT(FString id)
{
	FFishRow* row = xDataTableFishes->FindRow<FFishRow>(FName(id), "");
	if (!row)
	{
		UE_LOG(LogTemp, Error, TEXT("Fish Row not fund"));
		return nullptr;
	}
	return row->xFish;
}

TArray<UDA_QuestModuleBase*> AFishyBusinessGameModeBase::GetQuestFromDT(FString id)
{
	FQuestRow* row = xDataTableQuest->FindRow<FQuestRow>(FName(id), "");
	return row->xModuleList;
}
