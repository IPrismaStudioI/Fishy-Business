// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Public/DIalogueSystem/DialogueElaborator.h"
#include "GameFramework/GameModeBase.h"
#include "FishyBusinessGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class FISHYBUSINESS_API AFishyBusinessGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere)
	UDialogueElaborator* DialogueElaborator;
	
public:
	AFishyBusinessGameModeBase();
};
