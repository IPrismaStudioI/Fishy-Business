// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Dialogue.h"
#include "Components/ActorComponent.h"
#include "DialogueElaborator.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FISHYBUSINESS_API UDialogueElaborator : public UActorComponent
{
	GENERATED_BODY()

private:
	bool _bIsRunning = false;
	FDialogue _xActualDialogue;
	TArray<FString> _sCurrentText;
	int _iCurrentMonologueIndex;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Sets default values for this component's properties
	UDialogueElaborator();
	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void StartDialogue(FDialogue dialogue);

private:
	void StartMonologue();
	void DisplayNextSentence();
	void TypeSentence();
	void EndDialogue();

	void ClearCurrent();
	void AddToCurrent(FString sentence);
	void RemoveFromCurrent();
	FString GetFromCurrent();
};
