// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "QuestItemUI.h"
#include "Components/ActorComponent.h"
#include "QuestBoard.generated.h"

USTRUCT()
struct FQuestUIElement
{
	GENERATED_BODY()

public:
	FString sQuestID;
	bool bIsActive;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FISHYBUSINESS_API UQuestBoard : public UActorComponent
{
	GENERATED_BODY()
	
private:
	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UUserWidget> _xQuestBoardUI;

	UPROPERTY()
	TMap<UQuestItemUI*, FQuestUIElement> _mQuestUIElements;
	
public:	
	// Sets default values for this component's properties
	UQuestBoard();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};

