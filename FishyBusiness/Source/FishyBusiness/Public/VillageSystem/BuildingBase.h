// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnviromentSystem/LightChangableBase.h"
#include "Enums/ENpcNames.h"
#include "Widget/BuildingWidgetBase.h"
#include "Widget/VillageUI.h"
#include "BuildingBase.generated.h"

/**
 * 
 */
UCLASS()
class FISHYBUSINESS_API ABuildingBase : public ALightChangableBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere)
	UPaperSpriteComponent* xOnHover; 
	UPROPERTY(EditAnywhere) 
	ENpcNames _eNpcName;
	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UBuildingWidgetBase> _xBuildingUI;
	
public:	
	// Sets default values for this actor's properties
	ABuildingBase();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
