// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Dialogue.generated.h"

USTRUCT(BlueprintType)
struct FISHYBUSINESS_API FSentence
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString sSentence;
	
	// UPROPERTY(EditAnywhere)
	// USoundWave* xAudioClip;
	
public:
	FSentence();
	FSentence(FString sentence);
};

USTRUCT(BlueprintType)
struct FISHYBUSINESS_API FMonologue
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString sName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FSentence> sSentences;
	
public:
	FMonologue();
	FMonologue(FString sName, TArray<FSentence> sentences);
};

USTRUCT(BlueprintType)
struct FISHYBUSINESS_API FDialogue
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FMonologue> xDialogueParts;
	
public:
	FDialogue();
	FDialogue(TArray<FMonologue> monologues);
};

