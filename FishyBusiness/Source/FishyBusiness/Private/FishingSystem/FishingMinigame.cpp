// Fill out your copyright notice in the Description page of Project Settings.


#include "FishingSystem/FishingMinigame.h"

#include "Blueprint/WidgetTree.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/Image.h"
#include "FishyBusiness/FishyBusinessGameModeBase.h"


void UFishingMinigame::NativeConstruct()
{
 	Super::NativeConstruct();

	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	
	xFish = gamemode->GetFishFromDT(sFishID);
//
// 	UCanvasPanel* Canvas = WidgetTree->ConstructWidget<UCanvasPanel>(UCanvasPanel::StaticClass(), TEXT("RootCanvas"));
// 	WidgetTree->RootWidget = Canvas;
//
// 	UImage* MyImage = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass(), TEXT("MyImage"));
// 	Canvas->AddChild(MyImage);
//
// 	//this->UpdateCanTick();
// 	//PrimaryWidgetTick.bStartWithTickEnabled = true;
// 	
// 	//bIsFocusable = true;
// 	SetKeyboardFocus();
//
// 	_fTimerValue = FMath::FRandRange(0.5f, 4.0f);
//
// 	_fFishActualDirection = FMath::RandBool() ? 1.0f : -1.0f;s
}


void UFishingMinigame::MoveBar()
{
	_fMovingBatActualDir = FMath::Clamp(_fMovingBatActualDir *fMovingBarAcceleration +
										   _fMovingBatActualDir, -0.9f, 0.6f);


	if (UCanvasPanelSlot* CanvasSlot = Cast<UCanvasPanelSlot>(bBorder->Slot))
	{
		
		float posX = CanvasSlot->GetPosition().X;

		float posY = CanvasSlot->GetPosition().Y + _fMovingBatActualDir * fMovingBarSpeed;		

		FVector2D pos = FVector2D(posX, posY);
		
		CanvasSlot->SetPosition(pos);
	}
}

void UFishingMinigame::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if (GetWorld()->GetFirstPlayerController()->IsInputKeyDown(EKeys::SpaceBar))
	{
		_fMovingBarDirection = -1.0f;
	}
	else
	{
		_fMovingBarDirection = 1.0f;
	}

	MoveBar();
}

#pragma region Comments
// void UFishingMinigame::SetupParameters()
// {
// 	UCanvasPanelSlot* CanvasSlot = Cast<UCanvasPanelSlot>(_iBackgroundBar->Slot);
// 	float y = CanvasSlot->GetPosition().Y;
// 	//_fHighLimit = _iBackgroundBar->GetRenderTransformPivot().Y - (_iBackgroundBar->GetBrush().ImageSize.Y / 2.0f);
// 	//_fLowLimit = _iBackgroundBar->GetRenderTransformPivot().Y + (_iBackgroundBar->GetBrush().ImageSize.Y / 2.0f);
// 	// fMovingBarSpeed = barSpeed;
// 	// fLooseTime = looseTime;
// 	// fFishSpeed = fishSpeed;
// 	// fCatchSpeed = catchSpeed;
// 	// fGreenAreaSize = greenAreaSize;
// }
//
// void UFishingMinigame::CheckWin()
// {
// 	if (_fProgress >= 100.0f)
// 	{
// 		//victory
// 	}
// 	else if (_fProgress <= 0.0f)
// 	{
// 		//wait time
// 		//loose
// 	}
// }
//
// void UFishingMinigame::MoveFish()
// {
// 	if (UCanvasPanelSlot* CanvasSlot = Cast<UCanvasPanelSlot>(_iFish->Slot))
// 	{
// 		float CurrentY = _fFishActualDirection * _fFishAcceleration; //+=
// 		FVector2D NewPosition(CanvasSlot->GetPosition().X, CurrentY);
// 		CanvasSlot->SetPosition(NewPosition);
// 	}
// }
//
// void UFishingMinigame::MoveBar()
// {
// 	if (_iMovingBar)
// 	{
// 		if (GetWorld()->GetFirstPlayerController()->IsInputKeyDown(EKeys::SpaceBar))
// 		{
// 			_fActualDirection = -1.0f;
// 		}
// 		else
// 		{
// 			_fActualDirection = 1.0f;
// 		}
// 		
// 		if (UCanvasPanelSlot* CanvasSlot = Cast<UCanvasPanelSlot>(_iMovingBar->Slot))
// 		{
// 			float CurrentY = _fActualDirection * _fAcceleration; //+=
// 			FVector2D NewPosition(CanvasSlot->GetPosition().X, CurrentY);
// 			CanvasSlot->SetPosition(NewPosition);
// 		}
// 	}
// }
//
// void UFishingMinigame::Progress()
// {
// 	if (_iMovingBar->GetRenderTransformPivot().Y == _iFish->GetRenderTransformPivot().Y)
// 	{
// 		_fProgress += fCatchSpeed;
// 	}
// 	else
// 	{
// 		_fProgress -= fCatchSpeed;
// 	}
// 	CheckWin();
// }
//
// void UFishingMinigame::SetFishDirection()
// {
// 	_fTimerValue = FMath::FRandRange(0.5f, 4.0f);
// 	_fFishActualDirection *= -1;
// }
//
// bool UFishingMinigame::CheckLimits(UImage* movingImage)
// {
// 	if (movingImage->GetRenderTransformPivot().Y <= _fHighLimit - (movingImage->GetBrush().ImageSize.Y / 2.0f) ||
// 		movingImage->GetRenderTransformPivot().Y >= _fLowLimit + (movingImage->GetBrush().ImageSize.Y / 2.0f))
// 	{
// 		return true;
// 	}
// 	return false;
// }
//
// void UFishingMinigame::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
// {
// 	Super::NativeTick(MyGeometry, InDeltaTime);
//
// 	GetWorld()->GetTimerManager().SetTimer(
// 	_xTimerHandle,
// 	this,
// 	&UFishingMinigame::SetFishDirection,
// 	_fTimerValue,     // Wait x seconds
// 	true);
//
// 	if (CheckLimits(_iFish))
// 	{
// 		_fFishActualDirection *= -1;
// 	}
//
// 	MoveFish();
// 	MoveBar();
// }
#pragma endregion
