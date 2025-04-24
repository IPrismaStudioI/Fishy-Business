// Fill out your copyright notice in the Description page of Project Settings.


#include "CompendioSystem/CompendioManager.h"

#include "CompendioSystem/CompendioPageBase.h"
#include "CompendioSystem/CompendioPageFIsh.h"
#include "EventManager/EventWrapper.h"
#include "FishyBusiness/FishyBusinessGameModeBase.h"

// Sets default values
ACompendioManager::ACompendioManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}


// Called when the game starts or when spawned
void ACompendioManager::BeginPlay()
{
	Super::BeginPlay();
	
	APlayerController* playerController = GetWorld()->GetFirstPlayerController();

	UUserWidget* mainCompendio = CreateWidget(GetWorld(), _xMainCompendio);
	mainCompendio->AddToViewport(2);

	CreateCatalogue(Cast<UMainCompendio>(mainCompendio)->xPageList);
	_iPageNum = Cast<UMainCompendio>(mainCompendio)->xPageList.Num();
	
	if (playerController)
	{
		EnableInput(playerController);

		if (InputComponent)
		{
			InputComponent->BindAction("OpenCompendio", IE_Pressed, this, &ACompendioManager::OpenCompendio);
			InputComponent->BindAction("NextCompendioPage", IE_Pressed, this, &ACompendioManager::GoToNextPage);
			InputComponent->BindAction("PrevCompendioPage", IE_Pressed, this, &ACompendioManager::GoToPrevPage);
		}
	}
}

// Called every frame
void ACompendioManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACompendioManager::OpenCompendio()
{
	EventParameters eventParameters;
	eventParameters.Add(nullptr);
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	
	gamemode->xCompendioEventBus->TriggerEvent(EventListCompendio::OPEN_CLOSE_COMPENDIO, eventParameters);
}

void ACompendioManager::GoToNextPage()
{
	int i;
	if (_iPageNum < _iActualPageIndex + 2)
	{
		_iActualPageIndex = _iActualPageIndex + 2;
		i = _iActualPageIndex - 1;
	}
	else
	{
		_iActualPageIndex = 1;
		i = _iActualPageIndex - 1;
	}
	
	CallCreatePage(_iActualPageIndex, i);
}

void ACompendioManager::GoToPrevPage()
{
	int i;
	if (_iActualPageIndex - 2 > 0)
	{
		_iActualPageIndex = _iActualPageIndex - 2;
		i = _iActualPageIndex - 1;
	}
	else
	{
		_iActualPageIndex = _iPageNum - 1;
		i = _iActualPageIndex - 1;
	}

	CallCreatePage(_iActualPageIndex, i);
}

void ACompendioManager::CreateCatalogue(TArray<UCompendioPageBase*> pageList)
{
	for (UCompendioPageBase* Element : pageList)
	{
		if (Element->IsA(UCompendioPageFIsh::StaticClass()))
			_xFishCatalogued.Add(Cast<UCompendioPageFIsh>(Element)->xFishID, false);
	}
}

void ACompendioManager::CatalogueFish(EventParameters parameters)
{
	FString fishId = parameters[0]->Getter<FString>();
	_xFishCatalogued[fishId] = true;
}

void ACompendioManager::CallCreatePage(int i, int j)
{
	EventParameters eventParameters;
	eventParameters.Add(UParameterWrapper::CreateParameter<int>(i));
	eventParameters.Add(UParameterWrapper::CreateParameter<int>(j));
	
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	
	gamemode->xCompendioEventBus->TriggerEvent(EventListCompendio::CREATE_PAGE, eventParameters);
}
