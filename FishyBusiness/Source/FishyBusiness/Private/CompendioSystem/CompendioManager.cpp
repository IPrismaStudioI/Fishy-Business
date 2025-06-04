// Fill out your copyright notice in the Description page of Project Settings.


#include "CompendioSystem/CompendioManager.h"

#include "CompendioSystem/CompendioPageBase.h"
#include "CompendioSystem/CompendioPageFIsh.h"
#include "EventManager/EventWrapper.h"
#include "FishyBusiness/FishyBusinessGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerSystem/PlayerCharacter.h"

// Sets default values
ACompendioManager::ACompendioManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_iActualPageIndex = 1;
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
	
	// if (playerController)
	// {
	// 	EnableInput(playerController);
	//
	// 	if (InputComponent)
	// 	{
	// 		// InputComponent->BindAction("OpenCompendio", IE_Pressed, this, &ACompendioManager::OpenCompendio);
	// 		// InputComponent->BindAction("CloseCompendio", IE_Pressed, this, &ACompendioManager::CloseCompendio);
	// 		// InputComponent->BindAction("NextCompendioPage", IE_Pressed, this, &ACompendioManager::GoToNextPage);
	// 		// InputComponent->BindAction("PrevCompendioPage", IE_Pressed, this, &ACompendioManager::GoToPrevPage);
	// 	}
	// }

	// Registering functions to EventManager
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	
	UEventBus* EventManager = gamemode->xCompendioEventBus;
	UEventBus* EventManagerInput = gamemode->xInputEventBus;
	
	UEventWrapper::RegisterEvent(EventManager, EventListCompendio::CATALOGUE_FISH, MakeShared<TFunction<void(const EventParameters&)>>( [this] (const EventParameters& Params) { CatalogueFish(Params) ;}));
	UEventWrapper::RegisterEvent(EventManager, EventListCompendio::NEXT_PAGE, MakeShared<TFunction<void(const EventParameters&)>>( [this] (const EventParameters& Params) { GoToNextPageEvent(Params) ;}));
	UEventWrapper::RegisterEvent(EventManager, EventListCompendio::PREV_PAGE, MakeShared<TFunction<void(const EventParameters&)>>( [this] (const EventParameters& Params) { GoToPrevPageEvent(Params) ;}));

	UEventWrapper::RegisterEvent(EventManagerInput, EventListInput::NEXT_COMPENDIO_PAGE_INPUT, MakeShared<TFunction<void(const EventParameters&)>>( [this] (const EventParameters& Params) { GoToNextPageEvent(Params) ;}));
	UEventWrapper::RegisterEvent(EventManagerInput, EventListInput::PREV_COMPENDIO_PAGE_INPUT, MakeShared<TFunction<void(const EventParameters&)>>( [this] (const EventParameters& Params) { GoToPrevPageEvent(Params) ;}));
	UEventWrapper::RegisterEvent(EventManagerInput, EventListInput::OPEN_COMPENDIO_INPUT, MakeShared<TFunction<void(const EventParameters&)>>( [this] (const EventParameters& Params) { OpenCompendioEvent(Params) ;}));
	UEventWrapper::RegisterEvent(EventManagerInput, EventListInput::CLOSE_COMPENDIO_INPUT, MakeShared<TFunction<void(const EventParameters&)>>( [this] (const EventParameters& Params) { CloseCompendioEvent(Params) ;}));

}

// Called every frame 
void ACompendioManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACompendioManager::OpenCompendioEvent(EventParameters parameters)
{
	OpenCompendio();
}

void ACompendioManager::OpenCompendio()
{
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	if (gamemode->GetIsMainOverlayVisible() == true && _bIsOpen == false) return;
	
	_iActualPageIndexPair = 0;
	_iActualPageIndex = 1;

	_bIsOpen = !_bIsOpen;
	Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(),0))->SetCompendioMovable(!_bIsOpen);
	gamemode->SetBIsMainOverlayVisible(_bIsOpen);
	
	EventParameters eventParameters;
	eventParameters.Add(UParameterWrapper::CreateParameter<int>(_iActualPageIndexPair));
	eventParameters.Add(UParameterWrapper::CreateParameter<int>(_iActualPageIndex));

	TArray<FString> fishesID;
	gamemode->xCatalogueFishComponent->_xFishCatalogued.GenerateKeyArray (fishesID);
	
	if ((_iActualPageIndexPair > 0 && _iActualPageIndex > 1) && (_iActualPageIndexPair < fishesID.Num() - 2 && _iActualPageIndex < fishesID.Num() - 1))
	{
		eventParameters.Add(UParameterWrapper::CreateParameter<bool>(gamemode->xCatalogueFishComponent->_xFishCatalogued[fishesID[_iActualPageIndexPair]]));
		eventParameters.Add(UParameterWrapper::CreateParameter<bool>(gamemode->xCatalogueFishComponent->_xFishCatalogued[fishesID[_iActualPageIndex]]));
	}
	else
	{
		bool x = false;
		eventParameters.Add(UParameterWrapper::CreateParameter<bool>(x));
		eventParameters.Add(UParameterWrapper::CreateParameter<bool>(x));
	}
	
	gamemode->xCompendioEventBus->TriggerEvent(EventListCompendio::OPEN_CLOSE_COMPENDIO, eventParameters);
}

void ACompendioManager::CloseCompendioEvent(EventParameters parameters)
{
	CloseCompendio();
}

void ACompendioManager::CloseCompendio()
{
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	if (gamemode->GetIsMainOverlayVisible() == true && _bIsOpen == false) return;

	_bIsOpen = false;

	Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(),0))->SetCompendioMovable(!_bIsOpen);
	gamemode->SetBIsMainOverlayVisible(_bIsOpen);

	EventParameters eventParameters;
	eventParameters.Add(nullptr);
	gamemode->xCompendioEventBus->TriggerEvent(EventListCompendio::CLOSE_COMPENDIO, eventParameters);
}

void ACompendioManager::GoToNextPageEvent(EventParameters parameters)
{
	GoToNextPage();
}

void ACompendioManager::GoToNextPage()
{
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	if (!gamemode->GetIsMainOverlayVisible()) return;
	if (!_bIsOpen) return;
	
	int i;
	if (_iPageNum > _iActualPageIndex + 2)
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

void ACompendioManager::GoToPrevPageEvent(EventParameters parameters)
{
	GoToPrevPage();
}

void ACompendioManager::GoToPrevPage()
{
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	if (!gamemode->GetIsMainOverlayVisible()) return;
	if (!_bIsOpen) return;
	
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

	CallCreatePage(i , _iActualPageIndex);
}

void ACompendioManager::CreateCatalogue(TArray<TSubclassOf<UCompendioPageBase>> pageList)
{
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	gamemode->xCatalogueFishComponent->_xFishCatalogued.Add("upgrade1", false);
	gamemode->xCatalogueFishComponent->_xFishCatalogued.Add("upgrade2", false);
	for (int i = 0; i < pageList.Num(); i++)
	{
		if (pageList[i]->IsChildOf(UCompendioPageFIsh::StaticClass()))
		{
			UCompendioPageFIsh* pageFish = Cast<UCompendioPageFIsh>(pageList[i]->GetDefaultObject());
			gamemode->xCatalogueFishComponent->_xFishCatalogued.Add(pageFish->sFishID, false);
		}
	}
}

void ACompendioManager::CatalogueFish(EventParameters parameters)
{
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	FString fishId = parameters[0]->Getter<FString>();
	gamemode->xCatalogueFishComponent->_xFishCatalogued[fishId] = true;
}

void ACompendioManager::CallCreatePage(int i, int j)
{
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	EventParameters eventParameters;
	eventParameters.Add(UParameterWrapper::CreateParameter<int>(i));
	eventParameters.Add(UParameterWrapper::CreateParameter<int>(j));
	
	TArray<FString> fishesID;
	gamemode->xCatalogueFishComponent->_xFishCatalogued.GenerateKeyArray (fishesID);
	
	if (((i > 0 && j > 1) && (i <= fishesID.Num() - 1 && j <= fishesID.Num() - 2)) || ((i > 1 && j > 0) && (i <= fishesID.Num() - 2 && j <= fishesID.Num() - 1)))
	{
		eventParameters.Add(UParameterWrapper::CreateParameter<bool>(gamemode->xCatalogueFishComponent->_xFishCatalogued[fishesID[i]]));
		eventParameters.Add(UParameterWrapper::CreateParameter<bool>(gamemode->xCatalogueFishComponent->_xFishCatalogued[fishesID[j]]));
	}
	else
	{
		bool x = false;
		eventParameters.Add(UParameterWrapper::CreateParameter<bool>(x));
		eventParameters.Add(UParameterWrapper::CreateParameter<bool>(x));
	}
	
	
	gamemode->xCompendioEventBus->TriggerEvent(EventListCompendio::CREATE_PAGE, eventParameters);
}
