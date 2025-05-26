// Fill out your copyright notice in the Description page of Project Settings.


#include "VillageSystem/VillageManager.h"

#include "Blueprint/UserWidget.h"
#include "PlayerSystem/PlayerCharacter.h"
#include "VillageSystem/Widget/VillageUI.h"


// Sets default values
AVillageManager::AVillageManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	xRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(xRoot);
	
	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("ArriveTrigger"));
	Trigger->SetupAttachment(RootComponent);;

	Trigger->OnComponentBeginOverlap.AddDynamic(this, &AVillageManager::OnOverlapBegin);

	// static ConstructorHelpers::FObjectFinder<UCurveFloat> Curvy(TEXT("CurveFloat'/Game/TimeLines/CurveVillageManager.CurveVillageManager'"));
	// if (Curvy.Object) {
	// 	fCurve = Curvy.Object;
	// }
	//
	// ArriveTimeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("TimelineScore"));
	//
	// tickCallback.BindUFunction(this, FName{ TEXT("ChangePlayerPosition") });
	// finishedCallback.BindUFunction(this, FName{ TEXT("ApproachVillage") });
}

// Called when the game starts or when spawned
void AVillageManager::BeginPlay()
{
	Super::BeginPlay();

	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	UEventBus* eventBus = gamemode->xVillageEventBus;
	UEventBus* eventBus2 = gamemode->xQuestEventBus;
	UEventWrapper::RegisterEvent(eventBus, EventListVillage::HIDE_VILLAGE_BASE, MakeShared<TFunction<void(const EventParameters&)>>([this](const EventParameters& Params) { FreePlayer(Params); }));
	UEventWrapper::RegisterEvent(eventBus2, EventListQuest::CALL_NOTIFY, MakeShared<TFunction<void(const EventParameters&)>>([this](const EventParameters& Params) { AdvanceNotify(Params); }));
	
	UVillageUI* villageUI = CreateWidget<UVillageUI>(GetWorld(), VillageUI);
	villageUI->AddToViewport(0);

	_xTargetPosition = GetActorLocation() + (_xPosition * 2);
	
	// ArriveTimeline->AddInterpFloat(fCurve, tickCallback, FName{ TEXT("Floaty") });
	// ArriveTimeline->SetTimelineFinishedFunc(finishedCallback);
	// ArriveTimeline->SetTimelineLength(ArriveTimeLineLenght);

	APlayerController* playerController = GetWorld()->GetFirstPlayerController();
	if (playerController)
	{
		EnableInput(playerController);

		if (InputComponent)
		{
			//InputComponent->BindAction("CloseVillage", IE_Pressed, this, &AVillageManager::ExitVillage);
		}
	}
}

// Called every frame
void AVillageManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (_bIsLerping)
	{
		_fCurrentLerpTime += DeltaTime;
		float alpha = FMath::Clamp(_fCurrentLerpTime / _fLerpDuration, 0.f, 1.f);

		ChangePlayerPosition(alpha);
		
		if (alpha >= 1.f)
		{
			_bIsLerping = false;
			_fCurrentLerpTime = 0.f;
			ApproachVillage();
		}
	}
}

void AVillageManager::AdvanceNotify(EventParameters params)
{
	EBuildings building = static_cast<EBuildings>(params[0]->Getter<int>());

	XBuildingsMap[building]->Notify(true);
}

void AVillageManager::ExitVillage()
{
	EventParameters eventParameters;
	eventParameters.Add(nullptr);
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	gamemode->xVillageEventBus->TriggerEvent(EventListVillage::ESC_VILLAGE, eventParameters);
}

void AVillageManager::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                     UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	player = Cast<APlayerCharacter>(OtherActor);
	_xInitialPosition = player->GetActorLocation();
	UE_LOG(LogTemp, Warning, TEXT("START LERP!"));

	_bIsLerping = true;
	
	// ArriveTimeline->PlayFromStart(); // or PlayFromStart() etc, can be called anywhere in this class
}

void AVillageManager::ChangePlayerPosition(float lerp)
{
	player->SetMovable(false);

	FVector newPos = FMath::Lerp(_xInitialPosition, _xTargetPosition, lerp);
	player->SetActorLocation(newPos);
}

void AVillageManager::ApproachVillage()
{
	OnEnterVillage();
	EventParameters eventParameters;
	eventParameters.Add(nullptr);
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	gamemode->xVillageEventBus->TriggerEvent(EventListVillage::SHOW_VILLAGE_BASE, eventParameters);
	player->bIsMoving = false;
	UE_LOG(LogTemp, Warning, TEXT("ApproachVillage!"));
}

void AVillageManager::FreePlayer(EventParameters parameters)
{
	if (!player) return;
	OnExitVillage();
	player->SetMovable(true);
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	gamemode->SetBIsMainOverlayVisible(false);

	player = nullptr;
}
