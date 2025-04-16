// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperFlipbookComponent.h"
#include "FishingSystem/FishingMinigame.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class FISHYBUSINESS_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UCameraComponent* xCamera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USpringArmComponent* xSpringArm;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	class UMovement* xMovement;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	class UUniqueInventory* xUniqueInventory;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	class UMaterialInventory* xMaterialInventory;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	class UPlayerCameraController* xCameraController;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	class UWallet* xWallet;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPaperFlipbookComponent* xCockpit;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPaperFlipbookComponent* xHull;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPaperFlipbookComponent* xEngine;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UFishingMinigame> xFishingMinigame;

	void CreateMinigame();
	
private:
	UFishingMinigame* ActiveWidget;
	
	/// <summary>moves the character on forward axis </summary>
	void MoveForward(float inputVector);

	/// <summary>moves the character on right axis</summary>
	void MoveRight(float inputVector);
};
