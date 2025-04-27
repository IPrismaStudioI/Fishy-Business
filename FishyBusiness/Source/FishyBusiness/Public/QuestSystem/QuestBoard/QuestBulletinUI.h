// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "QuestBulletinUI.generated.h"

/**
 * 
 */
UCLASS()
class FISHYBUSINESS_API UQuestBulletinUI : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(meta = (BindWidget))
	UImage* _xIcon;
	UPROPERTY(meta = (BindWidget))
	UButton* _xBulletinBtn;

	FString _sQuestID;
	
public:
	virtual void NativeConstruct() override;

};
