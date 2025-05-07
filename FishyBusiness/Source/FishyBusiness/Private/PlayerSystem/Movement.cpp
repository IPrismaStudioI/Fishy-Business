// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerSystem/Movement.h"

#include "PlayerSystem/PlayerCharacter.h"

// Sets default values for this component's properties
UMovement::UMovement(): xCockPit(nullptr), Hull(nullptr), xEngine(nullptr), _fxDirection(0), _fyDirection(0)
{
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

void UMovement::SetFlipbook(EDirections direction)
{
	//xCockPit = _xCockPitFlipBook[direction];
	Hull->SetFlipbook(_xHullFlipBook[direction]);
	//xEngine = _xEngineFlipBook[direction];
}


void UMovement::OnMovingVertical(float vector)
{
	_fyDirection = vector;
	CheckDirection();
	OnBoatMovement();
}

void UMovement::OnMovingHorizontal(float vector)
{
	_fxDirection = vector;
	CheckDirection();
	OnBoatMovement();
}

void UMovement::CheckDirection()
{
	float x = _fxDirection;
	float y = _fyDirection;

	int HashX = static_cast<int>(x * 10);
	int HashY = static_cast<int>(y * 10);

	switch (int Code = HashX * 10 + HashY)
	{
	case 10:    // (0, 1) N
		SetFlipbook(EDirections::E_NORTH);
		break;
	case 110:   // (1, 1) NE
		SetFlipbook(EDirections::E_NORTH_EST);
		break;
	case 100:   // (1, 0) E
		SetFlipbook(EDirections::E_EST);
		break;
	case 90:    // (1, -1) SE
		SetFlipbook(EDirections::E_SOUTH_EST);
		break;
	case -10:   // (0, -1) S
		SetFlipbook(EDirections::E_SOUTH);
		break;
	case -110:  // (-1, -1) SW
		SetFlipbook(EDirections::E_SOUTH_WEST);
		break; 
	case -100:  // (-1, 0) W 
		SetFlipbook(EDirections::E_WEST);
		break;
	case -90:   // (-1, 1) NW
		SetFlipbook(EDirections::E_NORTH_WEST);
		break;
	}
}



