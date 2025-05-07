// Fill out your copyright notice in the Description page of Project Settings.


#include "DIalogueSystem/DialogueElaborator.h"

#include "Blueprint/UserWidget.h"
#include "EventManager/EventList.h"
#include "EventManager/EventWrapper.h"
#include "FishyBusiness/FishyBusinessGameModeBase.h"

// Sets default values for this component's properties
UDialogueElaborator::UDialogueElaborator()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}

// Called when the game starts
void UDialogueElaborator::BeginPlay()
{
	Super::BeginPlay();

	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	
	UEventBus* EventManager = gamemode->xDialogueEventBus;
	
	UEventWrapper::RegisterEvent(EventManager, EventListDialogue::CONTINUE_DIALOGUE, MakeShared<TFunction<void(const EventParameters&)>>([this](const EventParameters& Params) { DisplayNextSentenceEvent(Params); }));

	dialogueUIWidget = CreateWidget(GetWorld(), DialogueUI);
	dialogueUIWidget->AddToViewport(3);
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
		EventParameters eventParameters;
		eventParameters.Add(nullptr);
		AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
		gamemode->SetBIsMainOverlayVisible(true);
	
		gamemode->xDialogueEventBus->TriggerEvent(EventListDialogue::START_DIALOGUE, eventParameters);

		
		_bIsRunning = true;

		_xActualDialogue = dialogue;

		StartMonologue();
	}
}

void UDialogueElaborator::StartMonologue()
{
	EventParameters eventParameters;
	eventParameters.Add(UParameterWrapper::CreateParameter<FString>(_xActualDialogue.xDialogueParts[_iCurrentMonologueIndex].sName));
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	
	gamemode->xDialogueEventBus->TriggerEvent(EventListDialogue::CHANGE_NAME, eventParameters);
	
	ClearCurrent();
	AddToCurrent("");

	for (FSentence sentence : _xActualDialogue.xDialogueParts[_iCurrentMonologueIndex].sSentences)
	{
		AddToCurrent(sentence.sSentence);
	}

	DisplayNextSentence();
}

void UDialogueElaborator::DisplayNextSentenceEvent(EventParameters parameters)
{
	DisplayNextSentence();
}

void UDialogueElaborator::DisplayNextSentence()
{
	RemoveFromCurrent();

	if (_sCurrentText.Num() == 0)
	{
		if (_iCurrentMonologueIndex < _xActualDialogue.xDialogueParts.Num() - 1)
		{
			_iCurrentMonologueIndex++;
			StartMonologue();
		}
		else
		{
			if (_xActualDialogue.bHasChoices)
			{
				EventParameters eventParameters;
				
				FString allIDChoices = FString::Join(_xActualDialogue._sDialogueIDChoices, TEXT("|"));
				eventParameters.Add(UParameterWrapper::CreateParameter<FString>(allIDChoices));
				
				FString allAnswers = FString::Join(_xActualDialogue._sDialogueAnswers, TEXT("|"));
				eventParameters.Add(UParameterWrapper::CreateParameter<FString>(allAnswers));
				
				EndDialogue();
				AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
				gamemode->xDialogueEventBus->TriggerEvent(EventListDialogue::START_CHOICES, eventParameters);
			}
			else
			{
				EndDialogue();
				CloseDialogue();
			}
		}
	}
	else
		TypeSentence();
}

void UDialogueElaborator::TypeSentence()
{
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	
	// EventParameters eventParametersVoid;
	// FString sentenceVoid = "";
	// eventParametersVoid.Add(UParameterWrapper::CreateParameter<FString>(sentenceVoid));
	// gamemode->xDialogueEventBus->TriggerEvent(EventListDialogue::CHANGE_SENTENCE, eventParametersVoid);

	EventParameters eventParameters;
	FString sentence = GetFromCurrent();
	eventParameters.Add(UParameterWrapper::CreateParameter<FString>(sentence));
	gamemode->xDialogueEventBus->TriggerEvent(EventListDialogue::CHANGE_SENTENCE, eventParameters);
}

void UDialogueElaborator::EndDialogue()
{
	_iCurrentMonologueIndex = 0;
	_xActualDialogue = FDialogue();

	_bIsRunning = false;
}

void UDialogueElaborator::CloseDialogue()
{
	EventParameters eventParameters;
	eventParameters.Add(nullptr);
	AFishyBusinessGameModeBase* gamemode = GetWorld()->GetAuthGameMode<AFishyBusinessGameModeBase>();
	
	gamemode->xDialogueEventBus->TriggerEvent(EventListDialogue::END_DIALOGUE, eventParameters);

	gamemode->SetBIsMainOverlayVisible(false);
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

