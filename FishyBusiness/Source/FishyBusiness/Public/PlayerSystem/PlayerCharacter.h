// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MaterialInventory.h"
#include "Movement.h"
#include "PaperFlipbookComponent.h"
#include "FishingSystem/FishingMinigame.h"
#include "FishingSystem/FishInventory.h"
#include "PlayerCameraController.h"
#include "UniqueInventory.h"
#include "Wallet.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "QuestSystem/AC_QuestLog.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class FISHYBUSINESS_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

private:
	UPROPERTY()
	UCharacterMovementComponent* _xCharacterMovementComponent;

	bool _bIsMovable = true;
	bool _bIsCompendioMovable = true;
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCameraComponent* xCamera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USpringArmComponent* xSpringArm;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UMovement* xMovement;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UUniqueInventory* xUniqueInventory;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UMaterialInventory* xMaterialInventory;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UPlayerCameraController* xCameraController;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UWallet* xWallet;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPaperFlipbookComponent* xCockpit;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPaperFlipbookComponent* xHull;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPaperFlipbookComponent* xEngine;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UFishInventory* xFishInventory;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsMoving = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UAC_QuestLog* xQuestLog;

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Sets default values for this character's properties
	APlayerCharacter();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void SetMovable(bool option);
	UFUNCTION(BlueprintCallable)
	void SetCompendioMovable(bool option);

	void MoveForwardEvent(EventParameters params);
	void MoveRightEvent(EventParameters params);
	
private:	
	/// <summary>moves the character on forward axis </summary>
	void MoveForward(float inputVector);

	/// <summary>moves the character on right axis</summary>
	void MoveRight(float inputVector);

	void CheckMoving();
};
