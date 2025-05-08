// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/CanvasPanel.h"
#include "Components/Image.h"
#include "Components/VerticalBox.h"
#include "DIalogueSystem/DialogueTriggers/ButtonDialogueTriggerBase.h"
#include "EventManager/EventWrapper.h"
#include "BuildingWidgetBase.generated.h"

/**
 * 
 */
UCLASS()
class FISHYBUSINESS_API UBuildingWidgetBase : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta = (BindWidget))
	UImage* _xNpcImage;
	UPROPERTY(meta = (BindWidget))
	UCanvasPanel* _xCanvas;

public:
	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UVerticalBox* _xMainMenu;
	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UButton* _xDialogueVerticalBoxBtn;
	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UButton* _xExitDialogueVerticalBoxBtn; 
	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UVerticalBox* _xDialogueMenu;
	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UButton* _xExitBuildingBtn; 

public:
	virtual void NativeConstruct() override;

protected:
	void HideCanvas();
	void ShowCanvas(EventParameters parameters);
	void ShowMenu(EventParameters parameters);

	UFUNCTION()
	void ShowDialogueMenu();
	UFUNCTION()
	void HideDialogueMenu();
	UFUNCTION()
	void ShowMainMenuEvent();

public:
	UFUNCTION(BlueprintCallable)
	void ExitBuilding();
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnOpenBuilding();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void OnCloseBuilding();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnShowMainMenuUI();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnShowDialogueMenuUI();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnHideDialogueMenuUI();
};
