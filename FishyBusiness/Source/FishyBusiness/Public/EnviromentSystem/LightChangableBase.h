// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PaperSpriteComponent.h"
#include "LightChangableBase.generated.h"

UCLASS()
class FISHYBUSINESS_API ALightChangableBase : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere)
	USceneComponent* xRoot;
	UPROPERTY(EditAnywhere)
	UPaperSpriteComponent* xSprite;

public:
	UPaperSpriteComponent* GetXSprite() const
	{
		return xSprite;
	}

	// Sets default values for this actor's properties
	ALightChangableBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
