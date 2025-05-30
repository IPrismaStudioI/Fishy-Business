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
	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UButton* _xBulletinBtn;

	FString _sQuestID;
	
public:
	virtual void NativeConstruct() override;

	UFUNCTION()
	void CheckCompleted();
	
	void EnableBulletin(bool value);

	UFUNCTION(BlueprintCallable)
	void OnClick();
	
private:
	void ShowBulletinFocused();
	void ApplyReward();
};
