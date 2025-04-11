// Fill out your copyright notice in the Description page of Project Settings.


#include "FishingSystem/FishingMinigame.h"

#include "Blueprint/WidgetTree.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/Image.h"

class UCanvasPanel;

void UFishingMinigame::NativeConstruct()
{
	Super::NativeConstruct();

	UCanvasPanel* Canvas = WidgetTree->ConstructWidget<UCanvasPanel>(UCanvasPanel::StaticClass(), TEXT("RootCanvas"));
	WidgetTree->RootWidget = Canvas;

	UImage* MyImage = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass(), TEXT("MyImage"));
	Canvas->AddChild(MyImage);

	//this->UpdateCanTick();
	//PrimaryWidgetTick.bStartWithTickEnabled = true;
	
	//bIsFocusable = true;
	SetKeyboardFocus();

	_fTimerValue = FMath::FRandRange(0.5f, 4.0f);
}


void UFishingMinigame::SetupParameters(float barSpeed, float looseTime, float fishSpeed, float catchSpeed,
                                       float greenAreaSize)
{
	fMovingBarSpeed = barSpeed;
	fLooseTime = looseTime;
	fFishSpeed = fishSpeed;
	fCatchSpeed = catchSpeed;
	fGreenAreaSize = greenAreaSize;
}

void UFishingMinigame::CheckWin()
{
	if (_fProgress >= 100.0f)
	{
		//victory
	}
	else if (_fProgress <= 0.0f)
	{
		//wait time
		//loose
	}
}

void UFishingMinigame::MoveFish()
{
	if (UCanvasPanelSlot* CanvasSlot = Cast<UCanvasPanelSlot>(_iFish->Slot))
	{
		float CurrentY = _fFishActualDirection * _fFishAcceleration; //+=
		FVector2D NewPosition(CanvasSlot->GetPosition().X, CurrentY);
		CanvasSlot->SetPosition(NewPosition);
	}
}

void UFishingMinigame::MoveBar()
{
	if (_iMovingBar)
	{
		if (GetWorld()->GetFirstPlayerController()->IsInputKeyDown(EKeys::SpaceBar))
		{
			_fActualDirection = -1.0f;
		}
		else
		{
			_fActualDirection = 1.0f;
		}
		
		if (UCanvasPanelSlot* CanvasSlot = Cast<UCanvasPanelSlot>(_iMovingBar->Slot))
		{
			float CurrentY = _fActualDirection * _fAcceleration; //+=
			FVector2D NewPosition(CanvasSlot->GetPosition().X, CurrentY);
			CanvasSlot->SetPosition(NewPosition);
		}
	}
}

void UFishingMinigame::Progress()
{
	if (_iMovingBar->GetRenderTransformPivot().Y == _iFish->GetRenderTransformPivot().Y)
	{
		_fProgress += fCatchSpeed;
	}
	else
	{
		_fProgress -= fCatchSpeed;
	}
	CheckWin();
}

void UFishingMinigame::SetFishDirection()
{
	_fTimerValue = FMath::FRandRange(0.5f, 4.0f);
	_fFishActualDirection *= -1;
}

void UFishingMinigame::Tick(float DeltaTime)
{
	GetWorld()->GetTimerManager().SetTimer(
	_xTimerHandle,
	this,
	&UFishingMinigame::SetFishDirection,
	_fTimerValue,     // Wait x seconds
	true     // loop
);
}
