// Fill out your copyright notice in the Description page of Project Settings.


#include "CompendioSystem/MainCompendio.h"

#include "FishyBusiness/FishyBusinessGameModeBase.h"

void UMainCompendio::NativeConstruct()
{
	Super::NativeConstruct();
}

void UMainCompendio::ShowMainCompendio(EventParameters parameters)
{
	if (_xCanvasPanel->IsVisible())
		_xCanvasPanel->SetVisibility(ESlateVisibility::Hidden);
	else
		_xCanvasPanel->SetVisibility(ESlateVisibility::Visible);
}

void UMainCompendio::CreatePages(EventParameters parameters)
{
	if (!_xCanvasPanel->IsVisible()) return;
	
	int firstPage = parameters[0]->Getter<int>();
	int secondPage = parameters[1]->Getter<int>();

	RemovePage();
	AddPage(firstPage, 0);
	AddPage(secondPage, 1);
}

void UMainCompendio::AddPage(int index, int page)
{
	_xActualPages.Add(CreateWidget(GetWorld(), xPageList[index]->GetClass()));
	_xActualPages[page]->AddToViewport(2);
	Cast<UCompendioPageBase>(_xActualPages[page])->SetPageIndex(index + 1);
}

void UMainCompendio::RemovePage()
{
}