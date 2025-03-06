// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


class FISHYBUSINESS_API Sentence
{
private:
	UPROPERTY(EditAnywhere)
	FString _sSentence;
	
	UPROPERTY(EditAnywhere)
	USoundWave _xAudioClip;
	
public:
	Sentence(FString sentence);
};

class FISHYBUSINESS_API Monologue
{
private:
	UPROPERTY(EditAnywhere)
	FString _sName;

	UPROPERTY(EditAnywhere)
	TArray<Sentence*> _xSentences;
	
public:
	Monologue(FString name, TArray<Sentence*> sentences);
};

class FISHYBUSINESS_API Dialogue
{
private:
	UPROPERTY(EditAnywhere)
	TArray<Monologue> _xDialogueParts;
	
public:
	Dialogue(TArray<Monologue> dialogueParts);
};

