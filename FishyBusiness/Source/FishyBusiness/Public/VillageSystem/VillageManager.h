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

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Buildings")
	TMap<EBuildings, ABuildingBase*> XBuildingsMap;

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
	// Sets default values for this actor's properties

	AVillageManager();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void AdvanceNotify(EventParameters params);
	void AdvanceDenotify(EventParameters params);
	
	UFUNCTION()
	void ExitVillage();
	UFUNCTION()
	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnEnterVillage();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnExitVillage();
};
