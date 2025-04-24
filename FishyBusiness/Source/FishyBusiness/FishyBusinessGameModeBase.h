// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Public/DIalogueSystem/DialogueElaborator.h"
#include "DataSystem/FishData/Fish.h"
#include "DIalogueSystem/DA_Dialogue.h"
#include "EventManager/ObserverManager.h"
#include "GameFramework/GameModeBase.h"
#include "FishyBusinessGameModeBase.generated.h"


UCLASS()
class FISHYBUSINESS_API AFishyBusinessGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere)
	UDialogueElaborator* xDialogueElaborator;
	
	UPROPERTY(VisibleAnywhere)
	UEventBus* xDialogueEventBus;
	UPROPERTY(VisibleAnywhere)
	UEventBus* xVillageEventBus;
	UPROPERTY(VisibleAnywhere)
	UEventBus* xCompendioEventBus;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DataTables")
	UDataTable* xDataTableDialogues;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DataTables")
	UDataTable* xDataTableFishes;
	
public:
	AFishyBusinessGameModeBase();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

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
};
