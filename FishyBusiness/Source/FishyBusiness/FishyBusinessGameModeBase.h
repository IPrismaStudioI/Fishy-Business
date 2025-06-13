// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Public/DIalogueSystem/DialogueElaborator.h"
#include "CompendioSystem/CatalogueFishComponent.h"
#include "DataSystem/FishData/Fish.h"
#include "DIalogueSystem/DA_Dialogue.h"
#include "EventManager/ObserverManager.h"
#include "GameFramework/GameModeBase.h"
#include "InputManager/InputManagerComponent.h"
#include "QuestSystem/E_QuestStatus.h"
#include "QuestSystem/QuestData/QuestRow.h"
#include "QuestSystem/QuestDataManager.h"
#include "QuestSystem/QuestBoard/QuestUnlockStorageManager.h"
#include "FishyBusinessGameModeBase.generated.h"

UCLASS()
class FISHYBUSINESS_API AFishyBusinessGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
private:
	bool _bIsMainOverlayVisible;

public:
	UPROPERTY(VisibleAnywhere)
	UQuestDataManager* xQuestDataManager;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UDialogueElaborator* xDialogueElaborator;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UQuestUnlockStorageManager* xQuestUnlockStorageManager;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UCatalogueFishComponent* xCatalogueFishComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UInputManagerComponent* xInputManagerComponent;
	
	UPROPERTY(VisibleAnywhere)
	UEventBus* xDialogueEventBus;
	UPROPERTY(VisibleAnywhere)
	UEventBus* xVillageEventBus;
	UPROPERTY(VisibleAnywhere)
	UEventBus* xQuestEventBus;
	UPROPERTY(VisibleAnywhere)
	UEventBus* xCompendioEventBus;
	UPROPERTY(VisibleAnywhere)
	UEventBus* xInputEventBus;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DataTables")
	UDataTable* xDataTableDialogues;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DataTables")
	UDataTable* xDataTableFishes;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DataTables")
	UDataTable* xDataTableQuest;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enumerators")
	TMap<EBiomes, FString> eBiomesNames;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enumerators")
	TMap<EQuestStatus, FString> eQuestStatusString;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UUserWidget*> _xActiveWidgets;
	
public:
	AFishyBusinessGameModeBase();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION(BlueprintCallable)
	bool GetIsMainOverlayVisible() const
	{
		return _bIsMainOverlayVisible;
	}

	void SetBIsMainOverlayVisible(bool bBIsMainOverlayVisible)
	{
		_bIsMainOverlayVisible = bBIsMainOverlayVisible;
	}
	
	static AFishyBusinessGameModeBase* GetInstance();

	/// <summary>Return a UDA_Dialogue* from the dialogue DataTable using an ID.
	/// <para>
	/// @param id - The ID of the dialogue to look up.
	/// </para>
	/// @return A pointer to UDA_Dialogue if the dialogue is found, otherwise nullptr.
	/// </summary>
	UDA_Dialogue* GetDialogueFromDT(FString id);

	/// <summary>Return a UFish* from the fish DataTable using an ID.
	/// <para>
	/// @param id - The ID of the fish to look up.
	/// </para>
	/// @return A pointer to UFish if the dialogue is found, otherwise nullptr.
	/// </summary>
	UFUNCTION(BlueprintCallable)
	UFish* GetFishFromDT(FString id);

	UFUNCTION(BlueprintCallable)
	TArray<UDA_QuestModuleBase*> GetQuestFromDT(FString id);
};
