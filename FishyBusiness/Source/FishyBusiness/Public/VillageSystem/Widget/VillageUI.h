// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/CanvasPanel.h"
#include "DIalogueSystem/DialogueTriggers/ButtonDialogueTriggerBase.h"
#include "VillageUI.generated.h"

/**
 * 
 */
UCLASS()
class FISHYBUSINESS_API UVillageUI : public UUserWidget
{
	GENERATED_BODY()

private:
	bool _bIsInBuilding;
	
public:
	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UButtonDialogueTriggerBase* _xFishShopBtn;
	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UButtonDialogueTriggerBase* _xLighthouseBtn;
	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UButtonDialogueTriggerBase* _xWorkshopBtn;
	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UButtonDialogueTriggerBase* _xArchiveBtn;
	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UButtonDialogueTriggerBase* _xCarpentryBtn;
	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UButton* _xExitVillageBtn;
	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UCanvasPanel* _xCanvas;

public:
	virtual void NativeConstruct() override;

private:
	void ShowWidget(EventParameters parameters);
	void HideWidget();
	void SetIsInBuilding();

public:
	UFUNCTION(BlueprintCallable)
	void ExitWidget();
	void ExitWidgetEvent(EventParameters parameters);
	UFUNCTION(BlueprintCallable)
	void onFishShopBtnClicked();
	UFUNCTION(BlueprintCallable)
	void onLighthouseBtnClicked();
	UFUNCTION(BlueprintCallable)
	void onWorkshopBtnClicked();
	UFUNCTION(BlueprintCallable)
	void onArchiveBtnClicked();
	UFUNCTION(BlueprintCallable)
	void onCarpentryBtnClicked();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnVisible();
};
