// Fill out your copyright notice in the Description page of Project Settings.


#include "CompendioSystem/CompendioManager.h"

#include "CompendioSystem/CompendioPageBase.h"
#include "EventManager/EventWrapper.h"
#include "FishyBusiness/FishyBusinessGameModeBase.h"

// Sets default values
ACompendioManager::ACompendioManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACompendioManager::BeginPlay()
{
	Super::BeginPlay();
	
	APlayerController* playerController = GetWorld()->GetFirstPlayerController();

	if (playerController)
	{
		EnableInput(playerController);

		if (InputComponent)
		{
			InputComponent->BindAxis("MoveForward", this, &AMyActor::MoveForward);
		}
	}



	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();

	EventParameters eventParameters;
	eventParameters.Add(UParameterWrapper::CreateParameter<TSubclassOf<UCompendioPageBase>>(test));
	gamemode->xDialogueEventBus->TriggerEvent(EventListDialogue::CHANGE_SENTENCE, eventParameters);

}

// Called every frame
void ACompendioManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

