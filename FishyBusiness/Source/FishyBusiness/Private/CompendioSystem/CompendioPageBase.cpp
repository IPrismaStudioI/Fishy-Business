// Fill out your copyright notice in the Description page of Project Settings.


#include "CompendioSystem/CompendioPageBase.h"

#include "FishyBusiness/FishyBusinessGameModeBase.h"

void UCompendioPageBase::NativeConstruct()
{
	Super::NativeConstruct();
	
	OnCreate();
}

void UCompendioPageBase::SetPageIndex(int numPage)
{
	FText text = FText::FromString(FString::FromInt(numPage));
	_xNumPageText->SetText(text);
}
