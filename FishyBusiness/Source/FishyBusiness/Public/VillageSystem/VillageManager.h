// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BuildingBase.h"
#include "Components/BoxComponent.h"
#include "Components/TimelineComponent.h"
#include "Enums/EBuildings.h"
#include "GameFramework/Actor.h"
#include "PlayerSystem/PlayerCharacter.h"
#include "Widget/VillageUI.h"
#include "VillageManager.generated.h"

UCLASS()
class FISHYBUSINESS_API AVillageManager : public AActor
{
	GENERATED_BODY()

private:
	APlayerCharacter* player;
	
	UPROPERTY(EditAnywhere, Category = "Buildings")
	TMap<EBuildings, ABuildingBase*> _xBuldingsMap;
	
#pragma region move player
	UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true))
	FVector _xPosition;
	FVector _xTargetPosition;
	FVector _xInitialPosition;

	UPROPERTY(EditAnywhere)
	USceneComponent* xRoot;
	UPROPERTY(EditAnywhere, Category="ArriveTrigger")
	UBoxComponent* Trigger;
#pragma endregion move player

#pragma region LerpApproach

private:
	UPROPERTY(EditAnywhere, Category = "LerpApproach")
	float _fLerpDuration = 0.f;
	
	float _fCurrentLerpTime = 0.f;
	bool _bIsLerping = false;
	
#pragma endregion lerpApproach
	
// #pragma region timeline
// 	UPROPERTY(EditAnywhere, Category = "Timeline")
// 	UTimelineComponent* ArriveTimeline;
// 	UPROPERTY(EditAnywhere, Category = "Timeline")
// 	float ArriveTimeLineLenght;
//
// 	UPROPERTY()
// 	UCurveFloat* fCurve;
//
// 	FOnTimelineFloat tickCallback{};
// 	FOnTimelineEventStatic finishedCallback;
// #pragma endregion timeline
	
	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UVillageUI> VillageUI;

private:
	UFUNCTION()
	void ChangePlayerPosition(float val);
	UFUNCTION()
	void ApproachVillage();
	
	void FreePlayer(EventParameters parameters);
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:
	TMap<EBuildings, ABuildingBase*>& xBuldingsMap()
	{
		return _xBuldingsMap;
	}

	// Sets default values for this actor's properties

	AVillageManager();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnEnterVillage();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnExitVillage();
};
