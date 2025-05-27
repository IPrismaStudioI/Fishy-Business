// Fill out your copyright notice in the Description page of Project Settings.


#include "VillageSystem/BuildingBase.h"

#include "VillageSystem/Widget/BuildingWidgetBase.h"

ABuildingBase::ABuildingBase()
{
	xOnHover = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("OnHover"));
	xOnHover->SetupAttachment(RootComponent);
	xAdvanceNotifySprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("AdvanceNotifySprite"));
	xAdvanceNotifySprite->SetupAttachment(RootComponent);
	xRestoreComponent = CreateDefaultSubobject<URestoreComponent>("Restore Component");
	this->AddInstanceComponent(xRestoreComponent);
}

void ABuildingBase::Notify(bool enable)
{
	xAdvanceNotifySprite->SetVisibility(enable);
}

void ABuildingBase::BeginPlay()
{
	Super::BeginPlay();

	UBuildingWidgetBase* buildingUI = CreateWidget<UBuildingWidgetBase>(GetWorld(), _xBuildingUI);
	buildingUI->AddToViewport(0);
}

