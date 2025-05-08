// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/CanvasPanel.h"
#include "Components/RichTextBlock.h"
#include "EventManager/EventWrapper.h"
#include "QuestBulletinFocusedUI.generated.h"

/**
 * 
 */
UCLASS()
class FISHYBUSINESS_API UQuestBulletinFocusedUI : public UUserWidget
{
	GENERATED_BODY()
	
private:
	UPROPERTY(meta = (BindWidget))
	URichTextBlock* _xQuestName;
	UPROPERTY(meta = (BindWidget))
	URichTextBlock* _xQuestDescription;
	UPROPERTY(meta = (BindWidget))
	URichTextBlock* _xQuestGiver;

	FString _sQuestID;

public:
	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UCanvasPanel* _xCanvas;
	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UButton* _xQuestExitBtn;
	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UButton* _xQuestAcceptBtn;
	
public:
	virtual void NativeConstruct() override;

	UFUNCTION()
	void QuestAccept();
	UFUNCTION()
	void CloseBulletin();
	
	void FillBulletin(EventParameters parameters);
	
	void ShowBulletin(bool isShowed);

	UFUNCTION()
	void QuitBulletin();

	UFUNCTION(BlueprintCallable)
	void OnClickAccept();
	UFUNCTION(BlueprintCallable)
	void OnClickDecline();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnVisible();

};
