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

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);
}

void APlayerCharacter::CreateMinigame()
{
	ActiveWidget = CreateWidget<UFishingMinigame>(GetWorld(), xFishingMinigame);

	if (ActiveWidget)
	{
		ActiveWidget->AddToViewport(); // Puts it on screen
	}
}

void APlayerCharacter::MoveForward(float inputVector)
{
	FVector ForwardDirection = GetActorForwardVector();
	AddMovementInput(ForwardDirection, inputVector);
}

void APlayerCharacter::MoveRight(float inputVector)
{
	FVector RightDirection = GetActorRightVector();
	AddMovementInput(RightDirection, inputVector * 0.66f);
}



