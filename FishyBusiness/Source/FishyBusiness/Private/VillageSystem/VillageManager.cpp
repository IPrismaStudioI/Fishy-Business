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

	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("ArriveTrigger"));
	RootComponent = Trigger;

	Trigger->OnComponentBeginOverlap.AddDynamic(this, &AVillageManager::OnOverlapBegin);

	static ConstructorHelpers::FObjectFinder<UCurveFloat> Curvy(TEXT("CurveFloat'/Game/TimeLines/CurveVillageManager.CurveVillageManager'"));
	if (Curvy.Object) {
		fCurve = Curvy.Object;
	}

	ArriveTimeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("TimelineScore"));

	tickCallback.BindUFunction(this, FName{ TEXT("ChangePlayerPosition") });
	finishedCallback.BindUFunction(this, FName{ TEXT("ApproachVillage") });
}

// Called when the game starts or when spawned
void AVillageManager::BeginPlay()
{
	Super::BeginPlay();
	
	UUserWidget* villageUI = CreateWidget(GetWorld(), VillageUI);
	villageUI->AddToViewport(0);
	
	ArriveTimeline->AddInterpFloat(fCurve, tickCallback, FName{ TEXT("Floaty") });
	ArriveTimeline->SetTimelineFinishedFunc(finishedCallback);
	ArriveTimeline->SetTimelineLength(ArriveTimeLineLenght);
}

// Called every frame
void AVillageManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AVillageManager::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	player = Cast<APlayerCharacter>(OtherActor);
	_xInitialPosition = player->GetActorLocation();
	
	ArriveTimeline->PlayFromStart(); // or PlayFromStart() etc, can be called anywhere in this class
}

void AVillageManager::ChangePlayerPosition(float lerp)
{
	UE_LOG(LogTemp, Warning, TEXT("ChangePlayerPosition! %f"), lerp );
	
	player->SetMovable(false);
	FVector newPos = player->GetActorLocation() + _xPosition;
	FVector lerpedPos = FMath::Lerp(FVector(_xInitialPosition), FVector(newPos.X, newPos.Y, _xInitialPosition.Z), lerp);
	player->SetActorLocation(lerpedPos);
}

void AVillageManager::ApproachVillage()
{
	UE_LOG(LogTemp, Warning, TEXT("ApproachVillage!"));
}