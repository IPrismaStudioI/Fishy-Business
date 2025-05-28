// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerSystem/PlayerCameraController.h"

#include "Camera/CameraComponent.h"

// Sets default values for this component's properties
UPlayerCameraController::UPlayerCameraController(): xCamera(nullptr), _fZoomStartOrthoWidth(0), _fZoomTargetOrthoWidth(0),
                                                    _fZoomLerpDuration(0),
                                                    _fZoomCurrentLerpTime(0)
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

	if (_bZoomIsLerping)
	{
		_fZoomCurrentLerpTime += DeltaTime;
		float alpha = FMath::Clamp(_fZoomCurrentLerpTime / _fZoomLerpDuration, 0.f, 1.f);

		float newOrthoWidth = FMath::Lerp(_fZoomStartOrthoWidth, _fZoomTargetOrthoWidth, alpha);
		xCamera->SetOrthoWidth(newOrthoWidth);

		if (alpha >= 1.f)
		{
			_bZoomIsLerping = false;
			_bIsMoving = false;
		}
	}

	if (_bRelocateIsLerping)
	{
		_fRelocateCurrentLerpTime += DeltaTime;
		float beta = FMath::Clamp(_fRelocateCurrentLerpTime / _fRelocateLerpDuration, 0.f, 1.f);

		FVector newPos = FMath::Lerp(_vRelocateStartPosition, _vRelocateTargetPosition, beta);
		xSpringArm->SocketOffset = newPos;

		if (beta >= 1.f)
		{
			_bZoomIsLerping = false;
		}
	}
}

void UPlayerCameraController::ResizeCamera(float nextValue, float speed)
{
	if (!_bIsMoving)
	{
		_bIsMoving = true;
		_fZoomStartOrthoWidth = xCamera->OrthoWidth;
		_fZoomTargetOrthoWidth = nextValue;
		_fZoomCurrentLerpTime = 0.0f;
		_fZoomLerpDuration = speed;
		_bZoomIsLerping = true;
	}
	
	//float lastValue = xCamera->OrthoWidth;

	//xCamera->OrthoWidth = FMath::FInterpTo(lastValue, nextValue, GetWorld()->GetDeltaSeconds(), speed);
}

void UPlayerCameraController::RelocateCamera(FVector nextValue, float speed)
{
	if (!_bIsMoving)
	{
		_vRelocateStartPosition = xSpringArm->SocketOffset;
		_vRelocateTargetPosition = nextValue;
		_fRelocateCurrentLerpTime = 0.0f;
		_fRelocateLerpDuration = speed;
		_bRelocateIsLerping = true;
	}
}

