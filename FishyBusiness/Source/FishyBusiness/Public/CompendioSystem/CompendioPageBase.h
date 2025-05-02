// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "EventManager/EventWrapper.h"
#include "CompendioPageBase.generated.h"

/**
 * 
 */
UCLASS()
class FISHYBUSINESS_API UCompendioPageBase : public UUserWidget
{
	GENERATED_BODY()
protected:
	UPROPERTY(meta = (BindWidget))
	UImage* _xPageImage;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* _xNumPageText;
	
public:
	virtual void NativeConstruct() override;
	
	void SetPageIndex(int numPage);
	virtual void FillInformations(bool isCatalogued);
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnCreate();
};
