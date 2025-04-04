// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
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
};
