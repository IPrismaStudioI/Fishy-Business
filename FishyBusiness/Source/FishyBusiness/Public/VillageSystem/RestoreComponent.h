// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperSprite.h"
#include "Components/ActorComponent.h"
#include "EventManager/EventWrapper.h"
#include "QuestSystem/RestorationSystem/E_BuildingStatus.h"
#include "RestoreComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FISHYBUSINESS_API URestoreComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
	TArray<UPaperSprite*> xSpriteList;
	EBuildingStatus* buildingStatus;
	
public:	
	// Sets default values for this component's properties
	URestoreComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void ChangeStatus(EventParameters params);
};
