// Fill out your copyright notice in the Description page of Project Settings.


#include "EnviromentSystem/LightChanger.h"

// Sets default values
ALightChanger::ALightChanger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALightChanger::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALightChanger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

