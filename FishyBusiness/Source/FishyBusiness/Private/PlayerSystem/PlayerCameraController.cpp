// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerSystem/PlayerCameraController.h"

#include "Camera/CameraComponent.h"

// Sets default values for this component's properties
UPlayerCameraController::UPlayerCameraController(): xCamera(nullptr)
{
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPlayerCameraController::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPlayerCameraController::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UPlayerCameraController::ResizeCamera(float nextValue, float speed)
{
	float lastValue = xCamera->OrthoWidth;

	xCamera->OrthoWidth = FMath::FInterpTo(lastValue, nextValue, GetWorld()->GetDeltaSeconds(), speed);
}

