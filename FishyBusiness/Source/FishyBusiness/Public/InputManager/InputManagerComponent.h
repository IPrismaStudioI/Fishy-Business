// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputDataConfig.h"
#include "Components/ActorComponent.h"
#include "InputMappingContext.h"
#include "InputManagerComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FISHYBUSINESS_API UInputManagerComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="EnhancedInput")
	UInputMappingContext* _xInputMapping;
	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
	UInputDataConfig* InputActions;
	
public:	
	// Sets default values for this component's properties
	UInputManagerComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	void CallStartFishing();
	void CallOpenCompendio();
	void CallCloseCompendio();
	void CallNextCompendioPage();
	void CallPrevCompendioPage();
	void CallCloseVillage();
	void CallMoveForward(const FInputActionInstance& Instance);
	void CallMoveRight(const FInputActionInstance& Instance);
};
