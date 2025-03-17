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
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	UPROPERTY(EditAnywhere)
	UPaperFlipbook* p_xCockPit;
	UPROPERTY(EditAnywhere)
	UPaperFlipbook* p_xHull;
	UPROPERTY(EditAnywhere)
	UPaperFlipbook* p_xEngine;
	
	UPROPERTY(EditAnywhere)
	TMap<FString, UPaperFlipbook*> p_xCockPitFlipBook;
	UPROPERTY(EditAnywhere)
	TMap<FString, UPaperFlipbook*> p_xHullFlipBook;
	UPROPERTY(EditAnywhere)
	TMap<FString, UPaperFlipbook*> p_xEngineFlipBook;

	void SetFlipbook(FString direction);
	void ChangeSprite(FVector vector);
};
