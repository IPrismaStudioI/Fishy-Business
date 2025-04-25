// Fill out your copyright notice in the Description page of Project Settings.


#include "CompendioSystem/MainCompendio.h"

#include "FishyBusiness/FishyBusinessGameModeBase.h"

void UMainCompendio::NativeConstruct()
{
	Super::NativeConstruct();
	// Registering functions to EventManager
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	
	UEventBus* EventManager = gamemode->xCompendioEventBus;
	
	UEventWrapper::RegisterEvent(EventManager, EventListCompendio::OPEN_CLOSE_COMPENDIO, MakeShared<TFunction<void(const EventParameters&)>>( [this] (const EventParameters& Params) { ShowMainCompendio(Params) ;}));
	UEventWrapper::RegisterEvent(EventManager, EventListCompendio::CREATE_PAGE, MakeShared<TFunction<void(const EventParameters&)>>( [this] (const EventParameters& Params) { CreatePages(Params) ;}));
}

void UMainCompendio::ShowMainCompendio(EventParameters parameters)
{
	if (_xCanvasPanel->IsVisible())
	{
		_xCanvasPanel->SetVisibility(ESlateVisibility::Hidden);
		RemovePage();
	}
	else
	{
		_xCanvasPanel->SetVisibility(ESlateVisibility::Visible);
		AddPage(0, 0, false);
		AddPage(1, 1, false);
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
	_xActualPages.Add(CreateWidget(GetWorld(), xPageList[index]->GetClass()));
	_xActualPages[page]->AddToViewport(2);
	Cast<UCompendioPageBase>(_xActualPages[page])->SetPageIndex(index + 1);
	Cast<UCompendioPageBase>(_xActualPages[page])->FillInformations(isCatalogued);
}

void UMainCompendio::RemovePage()
{
	for (auto Element : _xActualPages)
	{
		Element->RemoveFromParent();
		delete Element;
	}
}