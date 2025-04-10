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
}

void UFishingMinigame::MoveFish()
{
}

void UFishingMinigame::MoveBar()
{
	//if (InKeyEvent.GetKey() == EKeys::SpaceBar)
	if (_iMovingBar)
	{
		if (UCanvasPanelSlot* CanvasSlot = Cast<UCanvasPanelSlot>(_iMovingBar->Slot))
		{
			float CurrentY = 1.0f; //+=
			FVector2D NewPosition(CanvasSlot->GetPosition().X, CurrentY);
			CanvasSlot->SetPosition(NewPosition);
		}
	}
}

void UFishingMinigame::Progress()
{
	if (_iMovingBar->RenderTransformPivot.Y == _iFish->RenderTransformPivot.Y)
	{
		_fProgress += fCatchSpeed;
		if (_fProgress >= 100.0f)
		{
			//victory
		}
	}
	else
	{
		_fProgress -= fCatchSpeed;
		if (_fProgress <= 0.0f)
		{
			//wait time
			//loose
		}
	}
}
