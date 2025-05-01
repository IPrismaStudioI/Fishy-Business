// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "S_PlayerQuest.h"
#include "Components/ActorComponent.h"
#include "DataSystem/ItemData/BaseItem.h"
#include "EventManager/EventWrapper.h"
#include "AC_QuestLog.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FISHYBUSINESS_API UAC_QuestLog : public UActorComponent
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	TMap<FString, FPlayerQuest> xQuests;
	// UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DataTables")
	// UDataTable* xQuestDT;
	
public:	
	// Sets default values for this component's properties
	UAC_QuestLog();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void AddQuest(FString questID);

	void AdvanceExploreModule(EQuestZones zone);
	void AdvanceDialogueModule(ENpcNames npcName, FString questID);
	void AdvanceCollectModule(UBaseItem* item, int quantity);

	void AddQuestEvent(EventParameters params);
	
	void AdvanceExploreEvent(EventParameters params);
	void AdvanceInteractEvent(EventParameters params);
	void AdvanceCollectEvent(EventParameters params);

private:
	void CheckAdvanceModule(FString questID);
	void CheckQuestStatus(FString questID);
	
};
