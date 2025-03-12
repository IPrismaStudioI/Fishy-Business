// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerSystem/PlayerCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	xSpringArm = CreateDefaultSubobject<USpringArmComponent>("Spring Arm");
	xSpringArm->SetupAttachment(RootComponent);
	xCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Player Camera"));
	xCamera->SetupAttachment(xSpringArm);

	//xSpringArm->AddRelativeRotation(FRotator(0, -90, 0));
	xCamera->SetProjectionMode(ECameraProjectionMode::Orthographic);
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

void APlayerCharacter::MoveForward(float inputVector)
{
	FVector ForwardDirection = GetActorForwardVector();
	AddMovementInput(ForwardDirection, inputVector * 0.6f);
}

void APlayerCharacter::MoveRight(float inputVector)
{
	FVector RightDirection = GetActorRightVector();
	AddMovementInput(RightDirection, inputVector);
}



