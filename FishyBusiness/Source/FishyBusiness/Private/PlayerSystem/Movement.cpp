// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerSystem/Movement.h"

#include "PlayerSystem/PlayerCharacter.h"

// Sets default values for this component's properties
UMovement::UMovement(): p_xCockPit(nullptr), p_xHull(nullptr), p_xEngine(nullptr)
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

	// ...
	
}

void UMovement::SetFlipbook(FString direction)
{
	p_xCockPit = p_xCockPitFlipBook[direction];
	p_xHull = p_xHullFlipBook[direction];
	p_xEngine = p_xEngineFlipBook[direction];
}

void UMovement::ChangeSprite(FVector vector)
{
	// switch (vector)
	// {
	// 	case 1
	// }
}


// Called every frame
void UMovement::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (GetOwner()->GetVelocity() != FVector::ZeroVector)
	{
		ChangeSprite(GetOwner()->GetVelocity());
	}
}



