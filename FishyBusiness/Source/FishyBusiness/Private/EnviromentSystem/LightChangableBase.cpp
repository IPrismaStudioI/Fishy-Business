// Fill out your copyright notice in the Description page of Project Settings.


#include "EnviromentSystem/LightChangableBase.h"

// Sets default values
ALightChangableBase::ALightChangableBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	xSprite = CreateDefaultSubobject<UPaperSpriteComponent>("Sprite");
	this->AddInstanceComponent(xSprite);
	SetRootComponent(xSprite);
}

// Called when the game starts or when spawned
void ALightChangableBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALightChangableBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

