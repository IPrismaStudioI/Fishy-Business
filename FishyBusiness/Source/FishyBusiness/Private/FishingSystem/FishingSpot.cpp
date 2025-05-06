// Fill out your copyright notice in the Description page of Project Settings.


#include "FishingSystem/FishingSpot.h"

#include "Components/SphereComponent.h"
#include "EventManager/EventWrapper.h"
#include "FishingSystem/FishingReward.h"
#include "FishyBusiness/FishyBusinessGameModeBase.h"
#include "PlayerSystem/PlayerCharacter.h"

class AFishyBusinessGameModeBase;
// Sets default values
AFishingSpot::AFishingSpot()
{
	xSphereTrigger = CreateDefaultSubobject<USphereComponent>(TEXT("SphereTrigger"));
	xSphereTrigger->SetupAttachment(RootComponent);
	xSphereTrigger->OnComponentBeginOverlap.AddDynamic(this, &AFishingSpot::OnBeginOverlap);
	xSphereTrigger->OnComponentEndOverlap.AddDynamic(this, &AFishingSpot::OnOverlapEnd);

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AFishingSpot::BeginPlay()
{
	Super::BeginPlay();
	
	_iCurrentFishes = iTotalFishes;
}

// Called every frame
void AFishingSpot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFishingSpot::ToggleActive(bool value)
{
	AActor* actor = this;
	actor->SetActorEnableCollision(value);
	actor->SetActorHiddenInGame(!value);
	bIsActive = value;
	if (value == true)
	{
		_iCurrentFishes = iTotalFishes;
	}
}

void AFishingSpot::FinishedMinigame(bool hasWon)
{
	if (hasWon)
	{
		xRewardWidget = CreateWidget<UFishingReward>(GetWorld(), xFishingReward);
		xRewardWidget->sFishID = xFishes[_iCurrentFishes -1];
		xRewardWidget->xFishingSpot = this;
		xRewardWidget->AddToViewport();

		xPlayerCharacter->xFishInventory->AddFish(xFishes[_iCurrentFishes -1]);

		EventParameters eventParameters;
		eventParameters.Add(UParameterWrapper::CreateParameter<FString>(xFishes[_iCurrentFishes -1]));
		AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
		gamemode->xCompendioEventBus->TriggerEvent(EventListCompendio::CATALOGUE_FISH, eventParameters);
	}

	xPlayerCharacter->xCameraController->ResizeCamera(_fOldCameraSize, _fLerpSpeed);
	
	ActiveWidget[0]->RemoveFromParent();
	ActiveWidget.Empty();
	
	xPlayerCharacter->SetMovable(true);
	_bCanCreateMinigame = true;
	_iCurrentFishes -= 1;

	if (_iCurrentFishes <= 0)
	{
		_bCanCreateMinigame = false;
		xFishingGenerator->ShuffleSpots(this);
	}
}

void AFishingSpot::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, 
                                  AActor* OtherActor, 
                                  UPrimitiveComponent* OtherComp, 
                                  int32 OtherBodyIndex, 
                                  bool bFromSweep, 
                                  const FHitResult& SweepResult)
{
	OnOverlapFishingSpot();
	
	if (APlayerCharacter* Player = Cast<APlayerCharacter>(OtherActor))
	{
		xPlayerCharacter = Player;
		_bCanCreateMinigame = true;

		EnableInput(Cast<APlayerController>(xPlayerCharacter->GetController()));
		if (InputComponent)
		{
			InputComponent->BindAction("StartFishing", IE_Pressed, this, &AFishingSpot::OnInteractFishing);
		}
	}

}

void AFishingSpot::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (APlayerCharacter* Player = Cast<APlayerCharacter>(OtherActor))
	{
		_bCanCreateMinigame = false;
	}
}

void AFishingSpot::OnInteractFishing()
{
	if (_bCanCreateMinigame)
	{
		_bCanCreateMinigame = false;
		// if (GetWorld()->GetFirstPlayerController()->IsInputKeyDown(EKeys::E) || GetWorld())
		// {
			xPlayerCharacter->SetMovable(false);
			
			OnInteractFishingSpot();

			_fOldCameraSize = xPlayerCharacter->xCamera->OrthoWidth;
			xPlayerCharacter->xCameraController->ResizeCamera(_fNewCameraSize, _fLerpSpeed);
		
		
			ActiveWidget.Add(CreateWidget<UFishingMinigame>(GetWorld(), xFishingMinigame));
			
			ActiveWidget[0]->sFishID = xFishes[_iCurrentFishes -1];
			ActiveWidget[0]->xFishSpot = this;
	
			if (ActiveWidget[0])
			{
				ActiveWidget[0]->AddToViewport();
				_bCanCreateMinigame = false;
			}
		//}
	}
}


