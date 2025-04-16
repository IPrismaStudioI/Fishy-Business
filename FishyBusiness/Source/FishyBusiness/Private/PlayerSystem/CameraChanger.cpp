// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerSystem/CameraChanger.h"

#include "Components/SphereComponent.h"
#include "PlayerSystem/PlayerCameraController.h"
#include "PlayerSystem/PlayerCharacter.h"

// Sets default values
ACameraChanger::ACameraChanger()
{
	xSphereTrigger = CreateDefaultSubobject<USphereComponent>(TEXT("SphereTrigger"));
	xSphereTrigger->SetupAttachment(RootComponent);
	
	xSphereTrigger->OnComponentBeginOverlap.AddDynamic(this, &ACameraChanger::OnBeginOverlap);
	xSphereTrigger->OnComponentEndOverlap.AddDynamic(this, &ACameraChanger::OnEndOverlap);
	
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

// Called when the game starts or when spawned
void ACameraChanger::BeginPlay()
{
	Super::BeginPlay();
}

void ACameraChanger::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, 
										AActor* OtherActor, 
										UPrimitiveComponent* OtherComp, 
										int32 OtherBodyIndex, 
										bool bFromSweep, 
										const FHitResult& SweepResult)
{
	//checks if the colliding actor is the player
	if (APlayerCharacter* Player = Cast<APlayerCharacter>(OtherActor))
	{
		//checks if the player has the camera controller
		if (UPlayerCameraController* PlayerComponent = Player->FindComponentByClass<UPlayerCameraController>())
		{
			PlayerComponent->ResizeCamera(fNewCameraSize, fSpeed);
			_fOldCameraSize = PlayerComponent->xCamera->OrthoWidth;
		}
	}
}

void ACameraChanger::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (APlayerCharacter* Player = Cast<APlayerCharacter>(OtherActor))
	{
		//checks if the player has the camera controller
		if (UPlayerCameraController* PlayerComponent = Player->FindComponentByClass<UPlayerCameraController>())
		{
			PlayerComponent->ResizeCamera(_fOldCameraSize, fSpeed);
		}
	}
}


