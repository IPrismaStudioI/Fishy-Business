// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BuildingBase.h"
#include "Components/BoxComponent.h"
#include "Enums/EBuildings.h"
#include "GameFramework/Actor.h"
#include "PlayerSystem/PlayerCharacter.h"
#include "VillageManager.generated.h"

UCLASS()
class FISHYBUSINESS_API AVillageManager : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
	TMap<EBuildings, ABuildingBase*> _xBuldingsMap;
	UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true))
	FVector3d _xPosition;
	UPROPERTY(EditAnywhere, Category="ArriveTrigger")
	UBoxComponent* Trigger;

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

private:
	void ChangePlayerPosition(float lerp, APlayerCharacter* player);
	void ApproachVillage();
};
