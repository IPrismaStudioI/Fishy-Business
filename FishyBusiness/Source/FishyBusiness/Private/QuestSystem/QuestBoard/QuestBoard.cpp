// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestSystem/QuestBoard/QuestBoard.h"

#include "FishyBusiness/FishyBusinessGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerSystem/PlayerCharacter.h"
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

	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	UEventBus* eventBus = gamemode->xVillageEventBus;
	UEventBus* eventBusQuest = gamemode->xQuestEventBus;
	UEventWrapper::RegisterEvent(eventBusQuest, EventListQuest::SHOW_QUEST_BOARD, MakeShared<TFunction<void(const EventParameters&)>>([this](const EventParameters& Params) { ActiveFillQuestBulletins(Params); }));
	UEventWrapper::RegisterEvent(eventBusQuest, EventListQuest::FILL_QUEST_BOARD, MakeShared<TFunction<void(const EventParameters&)>>([this](const EventParameters& Params) { FillQuestBulletins(Params); }));
	UEventWrapper::RegisterEvent(eventBusQuest, EventListQuest::UI_ADD_QUEST, MakeShared<TFunction<void(const EventParameters&)>>([this](const EventParameters& Params) { AddQuest(Params); }));
	
	UUserWidget* questBoardUI = CreateWidget(GetWorld(), _xQuestBoardUI);
	questBoardUI->AddToViewport(1);
	UUserWidget* questBulletinFocusedUI = CreateWidget(GetWorld(), _xQuestBulletinFocusedUI);
	questBulletinFocusedUI->AddToViewport(1);

	for (auto Element : Cast<UQuestBoardUI>(questBoardUI)->xQuestItemUIList)
	{
		_mQuestUIElements.Add(Element, FQuestUIElement());
	}
	
	SetupQuestUIElements();
}

void UQuestBoard::SetupQuestUIElements()
{
	TArray<UQuestBulletinUI*> x;
	_mQuestUIElements.GenerateKeyArray(x);
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	
	for (int i = 0; i < x.Num() && i < gamemode->xQuestUnlockStorageManager->_sUnlockedQuestList.Num(); i++)
	{
		FString id = gamemode->xQuestUnlockStorageManager->_sUnlockedQuestList[i];
		_mQuestUIElements[x[i]].sQuestID = id;
		_mQuestUIElements[x[i]].bIsActive = false;
	}
}

// Called every frame
void UQuestBoard::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UQuestBoard::FillQuestBulletins(EventParameters parameters)
{
	TArray<UQuestBulletinUI*> x;
	_mQuestUIElements.GenerateKeyArray(x);

	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	
	for (int i = 0; i < x.Num() && i < gamemode->xQuestUnlockStorageManager->_sUnlockedQuestList.Num(); i++)
	{
		FString id = gamemode->xQuestUnlockStorageManager->_sUnlockedQuestList[i];
		x[i]->_sQuestID = id;
		UTexture2D* icon = gamemode->xQuestDataManager->GetQuestIconFromDT(id);
		x[i]->_xIcon->SetBrushFromTexture(icon);

		if (FindQuestActive(id) == false)
		{
			_mQuestUIElements[x[i]].sQuestID = id;
			_mQuestUIElements[x[i]].bIsActive = false;
		}
	}

	BulletinCheck();
}

void UQuestBoard::ActiveFillQuestBulletins(EventParameters parameters)
{
	EventParameters eventParameters;
	eventParameters.Add(nullptr);
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	
	gamemode->xQuestEventBus->TriggerEvent(EventListQuest::FILL_QUEST_BOARD, eventParameters);
}

void UQuestBoard::BulletinCheck()
{
	TArray<UQuestBulletinUI*> x;
	_mQuestUIElements.GenerateKeyArray(x);
	
	for (int i = 0; i < x.Num(); i++)
	{
		FString id = x[i]->_sQuestID;
		if (id == "")
		{
			x[i]->_xBulletinBtn->SetIsEnabled(false);
		}
		else
		{
			if (_mQuestUIElements[x[FindQuestID(id)]].bIsActive)
			{
				AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
				int funded = gamemode->xQuestUnlockStorageManager->_sCompletedQuestList.Find(id);
				if (funded != -1)
					x[i]->_xBulletinBtn->SetIsEnabled(true);
				else
					x[i]->_xBulletinBtn->SetIsEnabled(false);
			}
			else
			{
				x[i]->_xBulletinBtn->SetIsEnabled(true);
				x[i]->_xBulletinBtn->InvalidateLayoutAndVolatility();
				UE_LOG(LogTemp, Warning, TEXT("%hs\n"), x[i]->_xBulletinBtn->GetIsEnabled() ? "true" : "false");
			}
		}
	}
}

void UQuestBoard::AddQuest(EventParameters parameters)
{
	FString id = parameters[0]->Getter<FString>();
	
	TArray<UQuestBulletinUI*> x;
	_mQuestUIElements.GenerateKeyArray(x);

	_mQuestUIElements[x[FindQuestID(id)]].bIsActive = true;

	EventParameters eventParameters;
	eventParameters.Add(UParameterWrapper::CreateParameter<FString>(id));
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	
	gamemode->xQuestEventBus->TriggerEvent(EventListQuest::ADD_QUEST, eventParameters);

	BulletinCheck();
}

int UQuestBoard::FindQuestID(FString questID)
{
	TArray<FQuestUIElement> v;
	FQuestUIElement tmp;
	tmp.sQuestID = questID;
	tmp.bIsActive = false;
	_mQuestUIElements.GenerateValueArray(v);
	
	return v.Find(tmp);
}


bool UQuestBoard::FindQuestActive(FString questID)
{
	UAC_QuestLog* log = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(),0))->xQuestLog;

	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	
	if (log->xQuests.Find(questID))
	{
		return true;
	}
	return false;
}