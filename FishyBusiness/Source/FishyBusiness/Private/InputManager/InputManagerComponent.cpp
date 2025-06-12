// Fill out your copyright notice in the Description page of Project Settings.


#include "InputManager/InputManagerComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EventManager/EventWrapper.h"
#include "EnhancedInputComponent.h"
#include "FishyBusiness/FishyBusinessGameModeBase.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UInputManagerComponent::UInputManagerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

// Called every frame
void UInputManagerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

// Called when the game starts
void UInputManagerComponent::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* PlayerController = Cast<APlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
	    
	Subsystem->ClearAllMappings();
	Subsystem->AddMappingContext(_xInputMapping, 0);

	if (UEnhancedInputComponent* input = Cast<UEnhancedInputComponent>(PlayerController->InputComponent))
	{
		input->BindAction(InputActions->START_FISHING_INPUT, ETriggerEvent::Started, this, &UInputManagerComponent::CallStartFishing);
		input->BindAction(InputActions->OPEN_COMPENDIO_INPUT, ETriggerEvent::Started, this, &UInputManagerComponent::CallOpenCompendio);
		input->BindAction(InputActions->CLOSE_COMPENDIO_INPUT, ETriggerEvent::Started, this, &UInputManagerComponent::CallCloseCompendio);
		input->BindAction(InputActions->NEXT_COMPENDIO_PAGE_INPUT, ETriggerEvent::Started, this, &UInputManagerComponent::CallNextCompendioPage);
		input->BindAction(InputActions->PREV_COMPENDIO_PAGE_INPUT, ETriggerEvent::Started, this, &UInputManagerComponent::CallPrevCompendioPage);
		input->BindAction(InputActions->CLOSE_VILLAGE_INPUT, ETriggerEvent::Started, this, &UInputManagerComponent::CallCloseVillage);
		input->BindAction(InputActions->MOVE_FORWARD_INPUT, ETriggerEvent::Triggered, this, &UInputManagerComponent::CallMoveForward);
		input->BindAction(InputActions->MOVE_RIGHT_INPUT, ETriggerEvent::Triggered, this, &UInputManagerComponent::CallMoveRight);
	}
}

void UInputManagerComponent::CallStartFishing()
{
	EventParameters eventParameters;
	eventParameters.Add(nullptr);
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	gamemode->xInputEventBus->TriggerEvent(EventListInput::START_FISHING_INPUT, eventParameters);
}

void UInputManagerComponent::CallOpenCompendio()
{
	EventParameters eventParameters;
	eventParameters.Add(nullptr);
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	gamemode->xInputEventBus->TriggerEvent(EventListInput::OPEN_COMPENDIO_INPUT, eventParameters);
}

void UInputManagerComponent::CallCloseCompendio()
{
	EventParameters eventParameters;
	eventParameters.Add(nullptr);
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	gamemode->xInputEventBus->TriggerEvent(EventListInput::CLOSE_COMPENDIO_INPUT, eventParameters);
}

void UInputManagerComponent::CallNextCompendioPage()
{
	EventParameters eventParameters;
	eventParameters.Add(nullptr);
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	gamemode->xInputEventBus->TriggerEvent(EventListInput::NEXT_COMPENDIO_PAGE_INPUT, eventParameters);
}

void UInputManagerComponent::CallPrevCompendioPage()
{
	EventParameters eventParameters;
	eventParameters.Add(nullptr);
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	gamemode->xInputEventBus->TriggerEvent(EventListInput::PREV_COMPENDIO_PAGE_INPUT, eventParameters);
}

void UInputManagerComponent::CallCloseVillage()
{
	EventParameters eventParameters;
	eventParameters.Add(nullptr);
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	gamemode->xInputEventBus->TriggerEvent(EventListInput::CLOSE_VILLAGE_INPUT, eventParameters);
}

void UInputManagerComponent::CallMoveForward(const FInputActionInstance& Instance)
{
	float FloatValue = Instance.GetValue().Get<float>();
	
	EventParameters eventParameters;
	eventParameters.Add(UParameterWrapper::CreateParameter<float>(FloatValue));
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	gamemode->xInputEventBus->TriggerEvent(EventListInput::MOVE_FORWARD_INPUT, eventParameters);
}

void UInputManagerComponent::CallMoveRight(const FInputActionInstance& Instance)
{
	float FloatValue = Instance.GetValue().Get<float>();
	
	EventParameters eventParameters;
	eventParameters.Add(UParameterWrapper::CreateParameter<float>(FloatValue));
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	gamemode->xInputEventBus->TriggerEvent(EventListInput::MOVE_RIGHT_INPUT, eventParameters);
}
