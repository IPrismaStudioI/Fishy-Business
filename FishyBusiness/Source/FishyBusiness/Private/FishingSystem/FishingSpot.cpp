// Fill out your copyright notice in the Description page of Project Settings.


#include "FishingSystem/FishingSpot.h"

#include "Components/SphereComponent.h"
#include "PlayerSystem/PlayerCharacter.h"

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
	if (_bCanCreateMinigame)
	{
		if (GetWorld()->GetFirstPlayerController()->IsInputKeyDown(EKeys::E))
		{
			ActiveWidget = CreateWidget<UFishingMinigame>(GetWorld(), xFishingMinigame);

			if (ActiveWidget)
			{
				ActiveWidget->AddToViewport();
			}
		}
	}
	iCurrentFishes = iTotalFishes;
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
	if (value == true)
	{
		iCurrentFishes = iTotalFishes;
	}
}

void AFishingSpot::FinishedMinigame()
{
	iCurrentFishes -= 1;
	if (iCurrentFishes <= 0)
	{
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
	if (APlayerCharacter* Player = Cast<APlayerCharacter>(OtherActor))
	{
		ActiveWidget = CreateWidget<UFishingMinigame>(GetWorld(), xFishingMinigame);

		if (ActiveWidget)
		{
			ActiveWidget->AddToViewport();
			//ActiveWidget->SetupParameters();
		}
		_bCanCreateMinigame = true;
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


