// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Public/DIalogueSystem/DialogueElaborator.h"
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DataTables")
	UDataTable* xDataTableDialogues;
	
public:
	AFishyBusinessGameModeBase();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	static AFishyBusinessGameModeBase* GetInstance();
};
