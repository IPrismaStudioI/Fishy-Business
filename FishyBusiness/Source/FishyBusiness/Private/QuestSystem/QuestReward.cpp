// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestSystem/QuestReward.h"

#include "FishyBusiness/FishyBusinessGameModeBase.h"
#include "QuestSystem/QuestData/Rewards/DA_RestorationReward.h"

// Sets default values for this component's properties
UQuestReward::UQuestReward()
{
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UQuestReward::BeginPlay()
{
	Super::BeginPlay();

	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	UEventBus* eventBusQuest = gamemode->xQuestEventBus;
	UEventWrapper::RegisterEvent(eventBusQuest, EventListQuest::GET_REWARD, MakeShared<TFunction<void(const EventParameters&)>>([this](const EventParameters& Params) { GiveReward(Params); }));	
}

// Called every frame
void UQuestReward::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UQuestReward::GiveReward(EventParameters parameters)
{
	FString id = parameters[0]->Getter<FString>();
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	UDA_QuestRewardBase* reward = gamemode->xQuestDataManager->GetQuestRewardFromDT(id);
	EQuestRewardType type = gamemode->xQuestDataManager->GetQuestRewardTypeFromDT(id);
	
	switch (type)
	{
		case EQuestRewardType::ITEM_REWARD:
			GetItemReward(reward);
			break;
		case EQuestRewardType::None:
			break;
		case EQuestRewardType::NEW_QUEST_REWARD:
			break;
		case EQuestRewardType::UPGRADE_REWARD:
			break;
		case EQuestRewardType::COMPENDIO_REWARD:
			break;
		case EQuestRewardType::DIALOGUE_REWARD:
			break;
		case EQuestRewardType::RESTORATION_REWARD:
			GetRestorationReward(reward);
			break;
	}
}

void UQuestReward::GetItemReward(UDA_QuestRewardBase* reward)
{
	
}

void UQuestReward::GetRestorationReward(UDA_QuestRewardBase* reward)
{
	UDA_RestorationReward* tmp = Cast<UDA_RestorationReward>(reward);

	EventParameters eventParameters;
	int i = static_cast<int>(tmp->eStatus);
	eventParameters.Add(UParameterWrapper::CreateParameter<int>(i));

	FString event;
	switch (tmp->eBuilding)
	{
	case EBuildings::E_LIGHTHOUSE:
		event = EventListVillage::RESTORE_LIGHTHOUSE;
		break;
	case EBuildings::E_FISHSHOP:
		event = EventListVillage::RESTORE_FISHSHOP;
		break;
	case EBuildings::E_WORKSHOP:
		event = EventListVillage::RESTORE_WORKSHOP;
		break;
	case EBuildings::E_ARCHIVE:
		event = EventListVillage::RESTORE_ARCHIVE;
		break;
	case EBuildings::E_CARPENTRY:
		event = EventListVillage::RESTORE_CARPENTRY;
		break;
	}
	
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	gamemode->xVillageEventBus->TriggerEvent(event, eventParameters);
}

