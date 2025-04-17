// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerSystem/PlayerCameraController.h"

#include "Camera/CameraComponent.h"

// Sets default values for this component's properties
UPlayerCameraController::UPlayerCameraController(): xCamera(nullptr), _fStartOrthoWidth(0), _fTargetOrthoWidth(0),
                                                    _fLerpDuration(0),
                                                    _fCurrentLerpTime(0)
{
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPlayerCameraController::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void UPlayerCameraController::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (_bIsLerping)
	{
		_fCurrentLerpTime += DeltaTime;
		float alpha = FMath::Clamp(_fCurrentLerpTime / _fLerpDuration, 0.f, 1.f);

		float newOrthoWidth = FMath::Lerp(_fStartOrthoWidth, _fTargetOrthoWidth, alpha);
		xCamera->SetOrthoWidth(newOrthoWidth);

		if (alpha > 1.f)
		{
			_bIsLerping = false;
		}
	}
}

void UPlayerCameraController::ResizeCamera(float nextValue, float speed)
{
	_fStartOrthoWidth = xCamera->OrthoWidth;
	_fTargetOrthoWidth = nextValue;
	_fCurrentLerpTime = 0.0f;
	_fLerpDuration = speed;
	_bIsLerping = true;
	
	//float lastValue = xCamera->OrthoWidth;

	//xCamera->OrthoWidth = FMath::FInterpTo(lastValue, nextValue, GetWorld()->GetDeltaSeconds(), speed);
}

