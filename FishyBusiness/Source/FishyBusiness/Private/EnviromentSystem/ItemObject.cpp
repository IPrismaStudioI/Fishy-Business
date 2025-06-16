// Fill out your copyright notice in the Description page of Project Settings.


#include "EnviromentSystem/ItemObject.h"

#include "Components/SphereComponent.h"
#include "FishyBusiness/FishyBusinessGameModeBase.h"
#include "PlayerSystem/PlayerCharacter.h"

// Sets default values
AItemObject::AItemObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	xSphereTrigger = CreateDefaultSubobject<USphereComponent>(TEXT("SphereTrigger"));
	xSphereTrigger->SetupAttachment(RootComponent);
	xSphereTrigger->OnComponentBeginOverlap.AddDynamic(this, &AItemObject::OnBeginOverlap);
}

// Called when the game starts or when spawned
void AItemObject::BeginPlay()
{
	Super::BeginPlay();
	
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	//UEventBus* eventBusInput = gamemode->xInputEventBus;
	//UEventWrapper::RegisterEvent(eventBusInput, EventListInput::PICKUP_ITEM_INPUT, MakeShared<TFunction<void(const EventParameters&)>>([this](const EventParameters& Params) { OnInteractEvent(Params); }));
}

// Called every frame
void AItemObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AItemObject::OnInteractEvent(EventParameters params)
{
	OnInteract();
}

void AItemObject::OnInteract()
{
	if (sItemID != "")
	{
		xPlayerCharacter->xMaterialInventory->AddItem(sItemID, iItemAmount);
	}
}

void AItemObject::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (APlayerCharacter* Player = Cast<APlayerCharacter>(OtherActor))
	{
		xPlayerCharacter = Player;
	
		EnableInput(Cast<APlayerController>(xPlayerCharacter->GetController()));
		if (InputComponent)
		{
			InputComponent->BindAction("InteractItem", IE_Pressed, this, &AItemObject::OnInteract);
		}
	}
}

