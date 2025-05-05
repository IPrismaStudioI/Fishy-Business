// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "QuestModuleUI.h"
#include "CompendioSystem/CompendioPageBase.h"
#include "Components/CanvasPanel.h"
#include "Components/RichTextBlock.h"
#include "Components/VerticalBox.h"
#include "CompendioPageQuest.generated.h"

/**
 * 
 */
UCLASS()
class FISHYBUSINESS_API UCompendioPageQuest : public UCompendioPageBase
{
	GENERATED_BODY()

private:
	UPROPERTY(meta = (BindWidget))
	UCanvasPanel* _xQuestCanvas;
	UPROPERTY(meta = (BindWidget))
	URichTextBlock* _xQuestName;
	UPROPERTY(meta = (BindWidget))
	URichTextBlock* _xQuestDescription;
	UPROPERTY(meta = (BindWidget))
	URichTextBlock* _xQuestStatus;
	UPROPERTY(meta = (BindWidget))
	UVerticalBox* _xBoxTasks;
	
public:
	UPROPERTY(EditAnywhere)
	UTexture2D* _xPageTexture;
	UPROPERTY(EditAnywhere)
	FString _sQuestID;
	UPROPERTY(EditAnywhere)
	TSubclassOf<UQuestModuleUI> _xQuestTaskUI;

public:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

	void FillInformations(bool isCatalogued) override;

private:
	void FillQuest();
};
