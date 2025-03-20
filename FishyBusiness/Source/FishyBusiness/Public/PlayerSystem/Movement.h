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

private:
	UPROPERTY(EditAnywhere)
	UPaperFlipbook* _xCockPit;
	UPROPERTY(EditAnywhere)
	UPaperFlipbook* _xHull;
	UPROPERTY(EditAnywhere)
	UPaperFlipbook* _xEngine;
	
	UPROPERTY(EditAnywhere)
	TMap<FString, UPaperFlipbook*> _xCockPitFlipBook;
	UPROPERTY(EditAnywhere)
	TMap<FString, UPaperFlipbook*> _xHullFlipBook;
	UPROPERTY(EditAnywhere)
	TMap<FString, UPaperFlipbook*> _xEngineFlipBook;

	float _fxDirection;
	float _fyDirection;
	
	void SetFlipbook(FString direction);
	void OnMovingVertical(float vector);
	void OnMovingHorizontal(float vector);
	void CheckDirection();

public:    
	virtual void SetupInputBindings();
};
