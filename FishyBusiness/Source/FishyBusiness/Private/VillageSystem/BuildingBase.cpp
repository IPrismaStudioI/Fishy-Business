// Fill out your copyright notice in the Description page of Project Settings.


#include "VillageSystem/BuildingBase.h"

#include "VillageSystem/Widget/BuildingWidgetBase.h"

ABuildingBase::ABuildingBase()
{
	xOnHover = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("OnHover"));
	xOnHover->SetupAttachment(RootComponent);
}

void ABuildingBase::BeginPlay()
{
	Super::BeginPlay();

	UBuildingWidgetBase* buildingUI = CreateWidget<UBuildingWidgetBase>(GetWorld(), _xBuildingUI);
	buildingUI->AddToViewport(0);
}

