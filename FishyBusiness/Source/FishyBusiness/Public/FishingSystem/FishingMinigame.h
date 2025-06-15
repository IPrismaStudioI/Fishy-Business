// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FishData.h"
#include "Blueprint/UserWidget.h"
#include "Components/Border.h"
#include "Components/CanvasPanel.h"
#include "Components/Image.h"
#include "DataSystem/FishData/Fish.h"
#include "FishingMinigame.generated.h"

class AFishingSpot;
/**
 * 
 */
UCLASS()
class FISHYBUSINESS_API UFishingMinigame : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FFishData sFishID;

	UPROPERTY(BlueprintReadWrite)
	UFish* xFish;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AFishingSpot* xFishSpot;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UCanvasPanel* cCanvasPanel;
	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UImage* iFishImage;
	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UImage* iMovingBar;
	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UImage* iBackGroundBar;

	//--------------------------------------------------------------

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	float fMovingBarSpeed;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	float fMovingBarAcceleration;

private:
	float _fMovingBarDirection;
	float _fMovingBatActualDir;

	float _fMaxPosY;
	float _fMinPosY;
	
public:
 	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

private:
	void MoveBar();
	
// public:
// 	UPROPERTY(EditAnywhere, BlueprintReadWrite)
// 	float fMovingBarSpeed;
//
// 	UPROPERTY(EditAnywhere, BlueprintReadWrite)
// 	float fLooseTime;
//
// 	UPROPERTY(EditAnywhere, BlueprintReadWrite)
// 	float fFishSpeed;
//
// 	UPROPERTY(EditAnywhere, BlueprintReadWrite)
// 	float fCatchSpeed;
//
// 	UPROPERTY(EditAnywhere, BlueprintReadWrite)
// 	float fGreenAreaSize;
//
// 	void SetupParameters();
// 	
// private:
// 	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
// 	
// private:
// 	UPROPERTY(EditAnywhere)
// 	float _fMaxYPos;
//
// 	UPROPERTY(EditAnywhere)
// 	float _fMinYPos;
//
// 	// UPROPERTY(EditAnywhere)
// 	// float _fDirection;
// 	
// 	UPROPERTY(EditAnywhere)
// 	float _fActualDirection;
//
// 	UPROPERTY(EditAnywhere)
// 	float _fAcceleration;
//
// 	// UPROPERTY(EditAnywhere)
// 	// float _fFishDirection;
//
// 	UPROPERTY(EditAnywhere)
// 	float _fFishActualDirection;
// 	
// 	UPROPERTY(EditAnywhere)
// 	float _fFishAcceleration;
//
// 	UPROPERTY(EditAnywhere)
// 	UImage* _iFish;
// 	
// 	UPROPERTY(EditAnywhere)
// 	UImage* _iMovingBar;
//
// 	UPROPERTY(EditAnywhere)
// 	UImage* _iBackgroundBar;
// 	
// 	float _fProgress;
//
// 	FTimerHandle _xTimerHandle;
//
// 	float _fTimerValue;
//
// 	float _fHighLimit;
// 	float _fLowLimit;
// 	
// 	
//
// private:
//
// 	void CheckWin();
//
// 	void MoveFish();
//
// 	void MoveBar();
//
// 	void Progress();
//
// 	void SetFishDirection();
//
// 	bool CheckLimits(UImage* movingImage);
};	
