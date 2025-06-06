#pragma once

#include "CoreMinimal.h"
#include "PaperFlipbookComponent.h"

UENUM(BlueprintType)
enum class EDirections : uint8
{
	E_NORTH       UMETA(DisplayName = "North"),
	E_SOUTH     UMETA(DisplayName = "South"),
	E_WEST      UMETA(DisplayName = "West"),
	E_EST    UMETA(DisplayName = "Est"),
	E_NORTH_EST     UMETA(DisplayName = "Nort Est"),
	E_NORTH_WEST     UMETA(DisplayName = "Nort West"),
	E_SOUTH_EST     UMETA(DisplayName = "South Est"),
	E_SOUTH_WEST     UMETA(DisplayName = "South West"),
};

#include "PaperFlipbook.h"
#include "Components/ActorComponent.h"
#include "Movement.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FISHYBUSINESS_API UMovement : public UActorComponent
{
	GENERATED_BODY()

private:
	//sprite lists
	UPROPERTY(EditAnywhere)
	TMap<EDirections, UPaperFlipbook*> _xCockPitFlipBook;
	UPROPERTY(EditAnywhere)
	TMap<EDirections, UPaperFlipbook*> _xMovingHullFlipBook;
	UPROPERTY(EditAnywhere)
	TMap<EDirections, UPaperFlipbook*> _xIdleHullFlipBook;
	UPROPERTY(EditAnywhere)
	TMap<EDirections, UPaperFlipbook*> _xEngineFlipBook;
	
	float _fxDirection;
	float _fyDirection;

	EDirections _eDirection = EDirections::E_EST;
	
	float _fX = 0.0f;
	float _fY = 0.0f;

public:
	//actual sprite
	UPROPERTY()
	UPaperFlipbook* xCockPit;
	UPROPERTY()
	UPaperFlipbookComponent* Hull;
	UPROPERTY()
	UPaperFlipbook* xEngine;

	FVector vVelocity;
	float fMaxSpeed;

	UPROPERTY(EditAnywhere)
	float fVelocityDeadZoneX;
	UPROPERTY(EditAnywhere)
	float fVelocityDeadZoneY;

public:    
	UMovement();
	virtual void SetupInputBindings();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnBoatMovement();

	/// <summary>checks the direction and calls SetFlipbook() depending on the direction</summary>
	void CheckDirection();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	/// <summary>changes the flipbook with the correct one depending on the direction</summary>
	void SetFlipbook(EDirections direction);

	/// <summary>checks when the character is moving vertically</summary>
	void OnMovingVertical(float vector);

	/// <summary>checks when the character is moving horizontally</summary>
	void OnMovingHorizontal(float vector);

};


