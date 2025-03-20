// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerSystem/Movement.h"

#include "PlayerSystem/PlayerCharacter.h"

// Sets default values for this component's properties
UMovement::UMovement(): _xCockPit(nullptr), _xHull(nullptr), _xEngine(nullptr)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMovement::BeginPlay()
{
	Super::BeginPlay();

	SetupInputBindings();
	
}

void UMovement::SetupInputBindings()
{
	AActor* Owner = GetOwner();
	if (!Owner) return;

	APlayerController* PC = Cast<APlayerController>(Owner->GetInstigatorController());
	if (!PC) return;

	if (!Owner->InputComponent)
	{
		UE_LOG(LogTemp, Error, TEXT("L'Actor %s non ha un InputComponent!"), *Owner->GetName());
		return;
	}

	Owner->InputComponent->BindAxis("MoveForward", this, &UMovement::OnMovingVertical);
	Owner->InputComponent->BindAxis("MoveRight", this, &UMovement::OnMovingHorizontal);

}

void UMovement::SetFlipbook(FString direction)
{
	_xCockPit = _xCockPitFlipBook[direction];
	_xHull = _xHullFlipBook[direction];
	_xEngine = _xEngineFlipBook[direction];
}


void UMovement::OnMovingVertical(float vector)
{
	_fyDirection = vector;
	CheckDirection();
}

void UMovement::OnMovingHorizontal(float vector)
{
	_fxDirection = vector;
	CheckDirection();
}

void UMovement::CheckDirection()
{
	float x = _fxDirection;
	float y = _fyDirection;

	int HashX = static_cast<int>(x * 10);
	int HashY = static_cast<int>(y * 10);

	switch (int Code = HashX * 10 + HashY)
	{
	case 1:    // (0, 1) N
		SetFlipbook("N");
		break;
	case 11:   // (1, 1) NE
		SetFlipbook("NE");
		break;
	case 10:   // (1, 0) E
		SetFlipbook("E");
		break;
	case 9:    // (1, -1) SE
		SetFlipbook("SE");
		break;
	case -1:   // (0, -1) S
		SetFlipbook("S");
		break;
	case -11:  // (-1, -1) SW
		SetFlipbook("SW");
		break; 
	case -10:  // (-1, 0) W 
		SetFlipbook("W");
		break;
	case -9:   // (-1, 1) NW
		SetFlipbook("NW");
		break;
	}
}



