// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "Components/ActorComponent.h"
#include "PlayerCameraController.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FISHYBUSINESS_API UPlayerCameraController : public UActorComponent
{
	GENERATED_BODY()

public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCameraComponent* xCamera;

private:
	float _fStartOrthoWidth;
	float _fTargetOrthoWidth;
	float _fLerpDuration;
	float _fCurrentLerpTime;
	bool _bIsLerping = false;
	
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
};
