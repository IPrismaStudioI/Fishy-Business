// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CompendioSystem/CompendioPageBase.h"
#include "CompendioPageUpgrade.generated.h"

/**
 * 
 */
UCLASS()
class FISHYBUSINESS_API UCompendioPageUpgrade : public UCompendioPageBase
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

	void FillInformations(bool isCatalogued) override;
};
