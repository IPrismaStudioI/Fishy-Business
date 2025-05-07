// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Dialogue.h"
#include "Components/ActorComponent.h"
#include "EventManager/EventWrapper.h"
#include "DialogueElaborator.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FISHYBUSINESS_API UDialogueElaborator : public UActorComponent
{
	GENERATED_BODY()

private:
	FDialogue _xActualDialogue;
	int _iCurrentMonologueIndex;
	 
	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UUserWidget> DialogueUI;
	
public:
	UPROPERTY(BlueprintReadWrite)
	TArray<FString> _sCurrentText;
	UPROPERTY(BlueprintReadWrite)
	bool _bIsRunning = false;
	UPROPERTY(BlueprintReadWrite)
	UUserWidget* dialogueUIWidget;
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Sets default values for this component's properties
	UDialogueElaborator();
	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/// <summary>
	/// Method used to starting a specified dialogue
	/// </summary>
	/// <param name="dialogue"> Dialogue struct need to elaborate</param>
	void StartDialogue(FDialogue dialogue);

private:
	/// <summary>
	/// Start the monologue based on CurrentMonologueIndex and show the first sentence
	/// </summary>
	void StartMonologue();
	
	/// <summary>
	/// Show the first sentence available in the list of CurrentText
	/// </summary>
	void DisplayNextSentence();
	void DisplayNextSentenceEvent(EventParameters parameters);

	/// <summary>
	/// Type the entire senteces passed by param in UI
	/// </summary>
	/// <returns></returns>
	void TypeSentence();

	/// <summary>
	/// Stop dialogue, reset all to default values and hide text box in UI
	/// </summary>
	void EndDialogue();

	void CloseDialogue();

	void ClearCurrent();
	void AddToCurrent(FString sentence);
	void RemoveFromCurrent();
	FString GetFromCurrent();
};
