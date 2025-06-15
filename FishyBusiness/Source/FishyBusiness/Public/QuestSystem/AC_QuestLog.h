// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "S_PlayerQuest.h"
#include "Components/ActorComponent.h"
#include "DataSystem/ItemData/BaseItem.h"
#include "EventManager/EventWrapper.h"
#include "QuestData/Enums/E_QuestZones.h"
#include "Enums/ENpcNames.h"
#include "FishingSystem/FFishBunch.h"
#include "AC_QuestLog.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FISHYBUSINESS_API UAC_QuestLog : public UActorComponent
{
	GENERATED_BODY()

private:
	FString _sActiveQuest;
	int _iQuestCount = -1;
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
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

	/// <summary>
	/// Adds a quest from the quest Data table to xQuests
	/// </summary>
	UFUNCTION(BlueprintCallable)
	void AddQuest(FString questID);

	/// <summary>
	///	gets the quest zone and checks if there is a quest module that requires that zone, if so it advances that quest by 1 position
	/// </summary>
	void AdvanceExploreModule(EQuestZones zone);

	/// <summary>
	///gets the quest id, npc name and module index, checks if they are correct then advance the specified quest by 1 position
	/// </summary>
	void AdvanceDialogueModule(ENpcNames npcName, FString questID, int moduleIndex);

	/// <summary>
	///	gets the item and checks if there is a quest module that requires that item, if there is and the amount passed is >= of the required amount it advances that quest by 1 position
	/// </summary>
	void AdvanceFishCollectModule(TMap<FString, FFishBunch> map);

	void AdvanceItemCollectModule(UBaseItem* item, int quantity);

	void AddQuestEvent(EventParameters params);
	
	void AdvanceExploreEvent(EventParameters params);
	void AdvanceInteractEvent(EventParameters params);
	void AdvanceCollectEvent(EventParameters params);

private:
	void CreateAdvanceNotify(int moduleIndex, FString questID);
	
	/// <summary>
	/// augment the quest current module by 1 and calls CheckQuestStatus()
	/// </summary>
	void CheckAdvanceModule(FString questID);
	
	/// <summary>
	/// checks if the quest is completed
	/// </summary>
	void CheckQuestStatus(FString questID);

	void SetActiveQuest(FString questID);

	void UpdateUIQuest();

	bool CheckSameTMap(const TMap<FString, FFishBunch>& MapA, const TMap<FString, int>& MapB);

#pragma region Events blueprint

public:
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void QuestCompleted();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void TaskCompleted();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void QuestAdded();
	
#pragma endregion
	
};
