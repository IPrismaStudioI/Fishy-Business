// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CompendioPageBase.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
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
	UPROPERTY(meta = (BindWidget))
	UButton* _xPrevBtn;
	UPROPERTY(meta = (BindWidget))
	UButton* _xNextBtn;

	//list of 2 elements
	TArray<UUserWidget*> _xActualPages; 
	
public:
	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<UCompendioPageBase>> xPageList;

public:
	virtual void NativeConstruct() override;
	void ShowMainCompendio(EventParameters parameters);
	void HideMainCompendio(EventParameters parameters);
	void CreatePages(EventParameters parameters);

	UFUNCTION()
	void OnNextClick();
	UFUNCTION()
	void OnPrevClick();

private:
	void AddPage(int index, int page, bool isCatalogued);
	void RemovePage();

#pragma region Blueprint

public:
	UFUNCTION(BlueprintCallable)
	void OnClickOpenClose();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void UpdateCompendiumF();
#pragma endregion
};

