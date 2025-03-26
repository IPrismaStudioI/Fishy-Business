#pragma once

#include "CoreMinimal.h"
#include "PaperFlipbook.h"
#include "Components/ActorComponent.h"
#include "Movement.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FISHYBUSINESS_API UMovement : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMovement();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	//actual sprite
	UPROPERTY(EditAnywhere)
	UPaperFlipbook* xCockPit;
	UPROPERTY(EditAnywhere)
	UPaperFlipbook* Hull;
	UPROPERTY(EditAnywhere)
	UPaperFlipbook* xEngine;

private:
	//sprite lists
	UPROPERTY(EditAnywhere)
	TMap<FString, UPaperFlipbook*> _xCockPitFlipBook;
	UPROPERTY(EditAnywhere)
	TMap<FString, UPaperFlipbook*> _xHullFlipBook;
	UPROPERTY(EditAnywhere)
	TMap<FString, UPaperFlipbook*> _xEngineFlipBook;

	float _fxDirection;
	float _fyDirection;

	/// <summary>changes the flipbook with the correct one depending on the direction</summary>
	void SetFlipbook(FString direction);

	/// <summary>checks when the character is moving vertically</summary>
	void OnMovingVertical(float vector);

	/// <summary>checks when the character is moving horizontally</summary>
	void OnMovingHorizontal(float vector);

	/// <summary>checks the direction and calls SetFlipbook() depending on the direction</summary>
	void CheckDirection();

public:    
	virtual void SetupInputBindings();
};
