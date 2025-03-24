// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerSystem/CameraChanger.h"

#include "Components/SphereComponent.h"
#include "PlayerSystem/PlayerCameraController.h"
#include "PlayerSystem/PlayerCharacter.h"

// Sets default values
ACameraChanger::ACameraChanger()
{
	p_xSphereTrigger = CreateDefaultSubobject<USphereComponent>(TEXT("SphereTrigger"));
	p_xSphereTrigger->SetupAttachment(RootComponent);
	p_xSphereTrigger->OnComponentBeginOverlap.AddDynamic(this, &ACameraChanger::OnBeginOverlap);
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
			PlayerComponent->ResizeCamera(p_fNewCameraSize, p_fSpeed);
		}
	}
}


