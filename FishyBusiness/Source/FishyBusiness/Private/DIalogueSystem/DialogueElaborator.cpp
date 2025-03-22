// Fill out your copyright notice in the Description page of Project Settings.


#include "DIalogueSystem/DialogueElaborator.h"

#include "EventManager/EventList.h"
#include "EventManager/EventWrapper.h"
#include "FishyBusiness/FishyBusinessGameModeBase.h"

// Sets default values for this component's properties
UDialogueElaborator::UDialogueElaborator()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDialogueElaborator::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UDialogueElaborator::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UDialogueElaborator::StartDialogue(FDialogue dialogue)
{
	if (!_bIsRunning)
	{
		//TODO: aggiungere la parte UI
		
		_bIsRunning = true;

		_xActualDialogue = dialogue;

		StartMonologue();
	}
}

void UDialogueElaborator::StartMonologue()
{
	//TODO: aggiungere la parte UI
	
	ClearCurrent();
	AddToCurrent("");

	for (FSentence sentence : _xActualDialogue.xDialogueParts[_iCurrentMonologueIndex].sSentences)
	{
		AddToCurrent(sentence.sSentence);
	}

	DisplayNextSentence();
}

void UDialogueElaborator::DisplayNextSentence()
{
	RemoveFromCurrent();

	if (_sCurrentText.Num() == 0)
	{
		if (_iCurrentMonologueIndex < _xActualDialogue.xDialogueParts.Num())
		{
			_iCurrentMonologueIndex++;
			StartMonologue();
		}
		else
		{
			if (_xActualDialogue.bHasChoices)
			{
				//TODO: aggiungere la parte UI
				
				EndDialogue();
			}
			else
			{
				EndDialogue();
			}
		}
	}

	TypeSentence();
}

void UDialogueElaborator::TypeSentence()
{
	//TODO: aggiungere la parte UI
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	
	EventParameters eventParameters;
	eventParameters.Add(UParameterWrapper::CreateParameter<FString>(_sCurrentText[0]));

	gamemode->xDialogueEventManager->TriggerEvent(EventListDialogue::CHANGE_SENTENCE, eventParameters);
}

void UDialogueElaborator::EndDialogue()
{
	_iCurrentMonologueIndex = 0;
	_xActualDialogue = FDialogue();

	//TODO: aggiungere la parte UI

	_bIsRunning = false;
}

void UDialogueElaborator::ClearCurrent()
{
	_sCurrentText.Empty();
}

void UDialogueElaborator::AddToCurrent(FString sentence)
{
	_sCurrentText.Add(sentence);
}

void UDialogueElaborator::RemoveFromCurrent()
{
	_sCurrentText.RemoveAt(0);
}

FString UDialogueElaborator::GetFromCurrent()
{
	return _sCurrentText[0];
}

