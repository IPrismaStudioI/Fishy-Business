// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerSystem/PlayerCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "PlayerSystem/MaterialInventory.h"
#include "PlayerSystem/Movement.h"
#include "PlayerSystem/PlayerCameraController.h"
#include "PlayerSystem/UniqueInventory.h"
#include "PlayerSystem/Wallet.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	xSpringArm = CreateDefaultSubobject<USpringArmComponent>("Spring Arm");
	xSpringArm->SetupAttachment(RootComponent);
	
	xCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Player Camera"));
	xCamera->SetupAttachment(xSpringArm);

	xMovement = CreateDefaultSubobject<UMovement>(TEXT("Movement"));
	
	xUniqueInventory = CreateDefaultSubobject<UUniqueInventory>("UniqueInventory");

	xFishInventory = CreateDefaultSubobject<UFishInventory>("FishInventory");
	
	xMaterialInventory = CreateDefaultSubobject<UMaterialInventory>("MaterialInventory");

	xCameraController = CreateDefaultSubobject<UPlayerCameraController>("CameraController");
	xCameraController->xCamera = xCamera;
	
	xWallet = CreateDefaultSubobject<UWallet>("Wallet");

	xCockpit = CreateDefaultSubobject<UPaperFlipbookComponent>("Cockpit");
	xCockpit->SetupAttachment(RootComponent);
	
	xHull = CreateDefaultSubobject<UPaperFlipbookComponent>("Hull");
	xHull->SetupAttachment(RootComponent);

	xEngine = CreateDefaultSubobject<UPaperFlipbookComponent>("Engine");
	xEngine->SetupAttachment(RootComponent);
	
	xCamera->SetProjectionMode(ECameraProjectionMode::Orthographic);

	xMovement->xCockPit = xCockpit->GetFlipbook();
	xMovement->Hull = xHull->GetFlipbook();
	xMovement->xEngine = xEngine->GetFlipbook();
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CheckMoving();
	
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);
}

void APlayerCharacter::SetMovable(bool option)
{
	_bIsMovable = option;
}

void APlayerCharacter::CheckMoving()
{
	if (_bIsMovable)
	{
		if (GetWorld()->GetFirstPlayerController()->IsInputKeyDown(EKeys::W)
			|| GetWorld()->GetFirstPlayerController()->IsInputKeyDown(EKeys::S)
			|| GetWorld()->GetFirstPlayerController()->IsInputKeyDown(EKeys::D)
			|| GetWorld()->GetFirstPlayerController()->IsInputKeyDown(EKeys::A))
		{
			bIsMoving = true;
		}
		else bIsMoving = false;
	}
}

void APlayerCharacter::MoveForward(float inputVector)
{
	if (!_bIsMovable) return;
	FVector ForwardDirection = GetActorForwardVector();
	AddMovementInput(ForwardDirection, inputVector);
}

void APlayerCharacter::MoveRight(float inputVector)
{
	if (!_bIsMovable) return;
	FVector RightDirection = GetActorRightVector();
	AddMovementInput(RightDirection, inputVector * 0.66f);
}



