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
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Camera Zoom")
	float fOldCameraSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Camera Zoom")
	float fNewCameraSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Camera Zoom")
	float fZoomSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "SpringArm Reposition")
	bool bCanSpringarmRelocate = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (MakeEditWidget = true), category = "SpringArm Reposition")
	FVector vNewSpringarmPosition;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "SpringArm Reposition")
	float fRelocateSpeed;

public:	
	// Sets default values for this actor's properties
	ACameraChanger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
private:

	FVector _vOldSpringarmPos;
	
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
