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
	void HideWidget();
	UFUNCTION()
	void ExitWidget();
};
