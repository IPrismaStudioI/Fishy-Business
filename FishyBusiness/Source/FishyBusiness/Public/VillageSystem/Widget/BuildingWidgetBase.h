// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/CanvasPanel.h"
#include "Components/Image.h"
#include "Components/VerticalBox.h"
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
	UVerticalBox* _xMainMenu;
	UPROPERTY(meta = (BindWidget))
	UImage* _xNpcImage;
	UPROPERTY(meta = (BindWidget))
	UCanvasPanel* _xCanvas;

public:
	virtual void NativeConstruct() override;

private:
	void HideCanvas();
};
