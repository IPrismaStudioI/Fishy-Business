// Fill out your copyright notice in the Description page of Project Settings.


#include "FishingSystem/FishingMinigame.h"

#include "Components/Image.h"

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
