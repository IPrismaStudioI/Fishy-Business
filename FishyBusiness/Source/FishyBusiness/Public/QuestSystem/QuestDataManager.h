// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "QuestData/Enums/E_QuestRewardType.h"
#include "QuestData/Enums/E_QuestUnlockType.h"
#include "QuestData/Modules/DA_QuestModuleBase.h"
#include "QuestData/Rewards/DA_QuestRewardBase.h"
#include "QuestData/Unlock/DA_QuestUnlockBase.h"
#include "QuestDataManager.generated.h"

class AFishyBusinessGameModeBase;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FISHYBUSINESS_API UQuestDataManager : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY()
	AFishyBusinessGameModeBase* xFishyBusinessGameMode;

public:
	void SetXFishyBusinessGameMode(AFishyBusinessGameModeBase* XFishyBusinessGameMode)
	{
		xFishyBusinessGameMode = XFishyBusinessGameMode;
	}

	// Sets default values for this component's properties
	UQuestDataManager();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	FString GetQuestNameFromDT(FString id);
	FString GetQuestDescriptionFromDT(FString id);
	UDA_QuestUnlockBase* GetQuestUnlockFromDT(FString id);
	EQuestUnlockType GetQuestUnlockTypeFromDT(FString id);
	TArray<UDA_QuestModuleBase*> GetQuestModuleListFromDT(FString id);
	TMap<EQuestRewardType, UDA_QuestRewardBase*> GetQuestRewardFromDT(FString id);
	UTexture2D* GetQuestIconFromDT(FString id);
	FString GetQuestGiverFromDT(FString id);
};
