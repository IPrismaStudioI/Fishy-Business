// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestSystem/QuestBoard/QuestBoard.h"

#include "FishyBusiness/FishyBusinessGameModeBase.h"
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
	UEventWrapper::RegisterEvent(eventBus, EventListVillage::SHOW_LIGHTHOUSE, MakeShared<TFunction<void(const EventParameters&)>>([this](const EventParameters& Params) { FillQuestBulletins(Params); }));

	
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
	
	for (int i = 0; i < x.Num(); i++)
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
	
	for (int i = 0; i < x.Num(); i++)
	{
		FString id = gamemode->xQuestUnlockStorageManager->_sUnlockedQuestList[i];
		x[i]->_sQuestID = id;
		UTexture2D* icon = gamemode->xQuestDataManager->GetQuestIconFromDT(id);
		x[i]->_xIcon->SetBrushFromTexture(icon);
	}
}

