// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "CameraChanger.generated.h"

UCLASS()
class FISHYBUSINESS_API ACameraChanger : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USphereComponent* xSphereTrigger;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Camera")
	float fNewCameraSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Camera")
	float fSpeed;

public:	
	// Sets default values for this actor's properties
	ACameraChanger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
private:

	float _fOldCameraSize;
	
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, 
										AActor* OtherActor, 
										UPrimitiveComponent* OtherComp, 
										int32 OtherBodyIndex, 
										bool bFromSweep, 
										const FHitResult& SweepResult);

	UFUNCTION()
	void OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
					  UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};
