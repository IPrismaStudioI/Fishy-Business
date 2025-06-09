// Fill out your copyright notice in the Description page of Project Settings.


#include "CompendioSystem/MainCompendio.h"

#include "FishyBusiness/FishyBusinessGameModeBase.h"

void UMainCompendio::NativeConstruct()
{
	Super::NativeConstruct();
	// Registering functions to EventManager
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	
	_xCanvasPanel->SetVisibility(ESlateVisibility::Hidden);

	UEventBus* EventManager = gamemode->xCompendioEventBus;

	_xNextBtn->OnClicked.AddDynamic(this, &UMainCompendio::OnNextClick);
	_xPrevBtn->OnClicked.AddDynamic(this, &UMainCompendio::OnPrevClick);
	_xUpgradePageBtn->OnClicked.AddDynamic(this, &UMainCompendio::OnUpgradeClick);
	_xFishPageBtn->OnClicked.AddDynamic(this, &UMainCompendio::OnFishClick);
	_xQuestPageBtn->OnClicked.AddDynamic(this, &UMainCompendio::OnQuestClick);
	
	UEventWrapper::RegisterEvent(EventManager, EventListCompendio::OPEN_CLOSE_COMPENDIO, MakeShared<TFunction<void(const EventParameters&)>>( [this] (const EventParameters& Params) { ShowMainCompendio(Params) ;}));
	UEventWrapper::RegisterEvent(EventManager, EventListCompendio::CLOSE_COMPENDIO, MakeShared<TFunction<void(const EventParameters&)>>( [this] (const EventParameters& Params) { HideMainCompendio(Params) ;}));
	UEventWrapper::RegisterEvent(EventManager, EventListCompendio::CREATE_PAGE, MakeShared<TFunction<void(const EventParameters&)>>( [this] (const EventParameters& Params) { CreatePages(Params) ;}));
}

void UMainCompendio::OnNextClick()
{
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	EventParameters eventParameters;
	eventParameters.Add(nullptr);
	gamemode->xCompendioEventBus->TriggerEvent(EventListCompendio::NEXT_PAGE, eventParameters);
}

void UMainCompendio::OnPrevClick()
{
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	EventParameters eventParameters;
	eventParameters.Add(nullptr);
	gamemode->xCompendioEventBus->TriggerEvent(EventListCompendio::PREV_PAGE, eventParameters);
}

void UMainCompendio::OnUpgradeClick()
{
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	EventParameters eventParameters;
	eventParameters.Add(UParameterWrapper::CreateParameter<int>(iUpgradePageIndex));
	gamemode->xCompendioEventBus->TriggerEvent(EventListCompendio::THIS_PAGE, eventParameters);
}

void UMainCompendio::OnFishClick()
{
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	EventParameters eventParameters;;
	eventParameters.Add(UParameterWrapper::CreateParameter<int>(iFishPageIndex));
	gamemode->xCompendioEventBus->TriggerEvent(EventListCompendio::THIS_PAGE, eventParameters);
}

void UMainCompendio::OnQuestClick()
{
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	EventParameters eventParameters;;
	eventParameters.Add(UParameterWrapper::CreateParameter<int>(iQuestPageIndex));
	gamemode->xCompendioEventBus->TriggerEvent(EventListCompendio::THIS_PAGE, eventParameters);
}

void UMainCompendio::ShowMainCompendio(EventParameters parameters)
{
	if (_xCanvasPanel->GetVisibility() == ESlateVisibility::Visible)
	{
		_xCanvasPanel->SetVisibility(ESlateVisibility::Hidden);
		RemovePage();
	}
	else
	{
		_xCanvasPanel->SetVisibility(ESlateVisibility::Visible);
		int firstPage = parameters[0]->Getter<int>();
		int secondPage = parameters[1]->Getter<int>();
		bool cataloguedFirstPage = parameters[2]->Getter<bool>();
		bool cataloguedSecondPage = parameters[3]->Getter<bool>();
		AddPage(firstPage, 0, cataloguedFirstPage);
		AddPage(secondPage, 1, cataloguedSecondPage);
	}
}

void UMainCompendio::HideMainCompendio(EventParameters parameters)
{
	if (_xCanvasPanel->GetVisibility() == ESlateVisibility::Visible)
	{
		_xCanvasPanel->SetVisibility(ESlateVisibility::Hidden);
		RemovePage();
	}
}

void UMainCompendio::CreatePages(EventParameters parameters)
{
	if (!_xCanvasPanel->IsVisible()) return;
	
	int firstPage = parameters[0]->Getter<int>();
	int secondPage = parameters[1]->Getter<int>();
	bool cataloguedFirstPage = parameters[2]->Getter<bool>();
	bool cataloguedSecondPage = parameters[3]->Getter<bool>();

	RemovePage();
	AddPage(firstPage, 0, cataloguedFirstPage);
	AddPage(secondPage, 1, cataloguedSecondPage);
}

void UMainCompendio::AddPage(int index, int page, bool isCatalogued)
{
	_xActualPages.Add(CreateWidget(GetWorld(), xPageList[index]));
	_xActualPages[page]->AddToViewport(2);
	Cast<UCompendioPageBase>(_xActualPages[page])->SetPageIndex(index + 1);
	Cast<UCompendioPageBase>(_xActualPages[page])->FillInformations(isCatalogued);
	UpdateCompendiumF();
}

void UMainCompendio::RemovePage()
{
	for (auto Element : _xActualPages)
	{
		Element->RemoveFromParent();
	}

	_xActualPages.Empty();
}

void UMainCompendio::OnClickOpenClose()
{
	EventParameters eventParameters;
	eventParameters.Add(nullptr);
	ShowMainCompendio(eventParameters);
}
