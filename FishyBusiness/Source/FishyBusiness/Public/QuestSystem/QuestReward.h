// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EventManager/EventWrapper.h"
#include "QuestData/Rewards/DA_QuestRewardBase.h"
#include "QuestReward.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FISHYBUSINESS_API UQuestReward : public UActorComponent
{
	GENERATED_BODY()


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Sets default values for this component's properties
	UQuestReward();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void GiveReward(EventParameters parameters);

private:
	void GetItemReward(UDA_QuestRewardBase* reward);
	void GetNewQuestReward(UDA_QuestRewardBase* reward);
	void GetRestorationReward(UDA_QuestRewardBase* reward);
};
