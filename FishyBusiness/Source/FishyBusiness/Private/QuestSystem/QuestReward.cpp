// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestSystem/QuestReward.h"

#include "FishyBusiness/FishyBusinessGameModeBase.h"

// Sets default values for this component's properties
UQuestReward::UQuestReward()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
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

	// ...
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
}

