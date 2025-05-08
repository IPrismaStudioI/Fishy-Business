// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CompendioSystem/CompendioPageBase.h"
#include "DataSystem/FishData/Fish.h"
#include "Components/RichTextBlock.h"
#include "CompendioPageFIsh.generated.h"

/**
 * 
 */
UCLASS()
class FISHYBUSINESS_API UCompendioPageFIsh : public UCompendioPageBase
{
	GENERATED_BODY()

private:
	UPROPERTY(meta = (BindWidget))
	URichTextBlock* _xFishName;
	UPROPERTY(meta = (BindWidget))
	URichTextBlock* _xFishDescription;
	UPROPERTY(meta = (BindWidget))
	URichTextBlock* _xFishSName;
	UPROPERTY(meta = (BindWidget))
	URichTextBlock* _xLocation;
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString sFishID;

public:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

	void FillInformations(bool isCatalogued) override;
};
