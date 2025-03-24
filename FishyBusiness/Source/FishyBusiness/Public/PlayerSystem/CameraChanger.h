// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CameraChanger.generated.h"

UCLASS()
class FISHYBUSINESS_API ACameraChanger : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACameraChanger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USphereComponent* p_xSphereTrigger;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Camera")
	float p_fNewCameraSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Camera")
	float p_fSpeed;

private:
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, 
										AActor* OtherActor, 
										UPrimitiveComponent* OtherComp, 
										int32 OtherBodyIndex, 
										bool bFromSweep, 
										const FHitResult& SweepResult);

};
