// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "Components/ActorComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "PlayerCameraController.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FISHYBUSINESS_API UPlayerCameraController : public UActorComponent
{
	GENERATED_BODY()

public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCameraComponent* xCamera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USpringArmComponent* xSpringArm;

private:
	float _fZoomStartOrthoWidth;
	float _fZoomTargetOrthoWidth;
	float _fZoomLerpDuration;
	float _fZoomCurrentLerpTime;
	bool _bZoomIsLerping = false;

	FVector _vRelocateStartPosition;
	FVector _vRelocateTargetPosition;
	float _fRelocateLerpDuration;
	float _fRelocateCurrentLerpTime;
	bool _bRelocateIsLerping = false;
	
private:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Sets default values for this component's properties
	UPlayerCameraController();
	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/// <summary>Changes player camera orthographic size within specified seconds</summary>
	void ResizeCamera(float nextValue, float speed);
	
	/// <summary> Changes player camera position within specified seconds </summary>
	void RelocateCamera(FVector nextValue, float speed);
};
