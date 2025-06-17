// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VillageSystem/Widget/BuildingWidgetBase.h"
#include "ShopBuildingWidget.generated.h"

/**
 * 
 */
UCLASS()
class FISHYBUSINESS_API UShopBuildingWidget : public UBuildingWidgetBase
{
	GENERATED_BODY()

private:
	UPROPERTY(meta = (BindWidget)) 
	UButton* _xShopBtn;
	UPROPERTY(meta = (BindWidget)) 
	UButton* _xExitShopBtn;
	UPROPERTY(meta = (BindWidget))
	UVerticalBox* _xShopMenu;
	
public:
	virtual void NativeConstruct() override;
	
private:
	UFUNCTION()
	void ShowShopMenu();
	UFUNCTION()
	void HideShopMenu();
	
public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnShowShopMenuUI();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnHideShopMenuUI();
};
