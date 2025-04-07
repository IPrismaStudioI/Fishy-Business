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
	UPROPERTY(meta = (BindWidget))
	UButtonDialogueTriggerBase* _xFishShopBtn;
	UPROPERTY(meta = (BindWidget))
	UButtonDialogueTriggerBase* _xLighthouseBtn;
	UPROPERTY(meta = (BindWidget))
	UButtonDialogueTriggerBase* _xWorkshopBtn;
	UPROPERTY(meta = (BindWidget))
	UButtonDialogueTriggerBase* _xArchiveBtn;
	UPROPERTY(meta = (BindWidget))
	UButtonDialogueTriggerBase* _xCarpentryBtn;
	UPROPERTY(meta = (BindWidget))
	UButton* _xExitVillageBtn;
	UPROPERTY(meta = (BindWidget))
	UCanvasPanel* _xCanvas;

public:
	virtual void NativeConstruct() override;

private:
	UFUNCTION()
	void onFishShopBtnClicked();
	UFUNCTION()
	void onLighthouseBtnClicked();
	UFUNCTION()
	void onWorkshopBtnClicked();
	UFUNCTION()
	void onArchiveBtnClicked();
	UFUNCTION()
	void onCarpentryBtnClicked();
	
	void ShowWidget(EventParameters parameters);
	UFUNCTION()
	void HideWidget();
};
