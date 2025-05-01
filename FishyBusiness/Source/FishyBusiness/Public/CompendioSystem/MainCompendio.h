// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CompendioPageBase.h"
#include "Blueprint/UserWidget.h"
#include "Components/CanvasPanel.h"
#include "EventManager/EventWrapper.h"
#include "MainCompendio.generated.h"

/**
 * 
 */
UCLASS()
class FISHYBUSINESS_API UMainCompendio : public UUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(meta = (BindWidget))
	UCanvasPanel* _xCanvasPanel;

	//list of 2 elements
	TArray<UUserWidget*> _xActualPages; 
	
public:
	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<UCompendioPageBase>> xPageList;

public:
	virtual void NativeConstruct() override;
	void ShowMainCompendio(EventParameters parameters);
	void CreatePages(EventParameters parameters);

private:
	void AddPage(int index, int page, bool isCatalogued);
	void RemovePage();
};
