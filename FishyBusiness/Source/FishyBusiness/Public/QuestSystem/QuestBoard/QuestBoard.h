// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "QuestBoardUI.h"
#include "QuestBulletinFocusedUI.h"
#include "QuestBulletinUI.h"
#include "Components/ActorComponent.h"
#include "QuestBoard.generated.h"

USTRUCT()
struct FQuestUIElement
{
	GENERATED_BODY()

public:
	FString sQuestID;
	bool bIsActive;
	bool operator==(const FQuestUIElement& Other) const
	{
		return sQuestID == Other.sQuestID;
	}
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FISHYBUSINESS_API UQuestBoard : public UActorComponent
{
	GENERATED_BODY()
	
private:
	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UQuestBoardUI> _xQuestBoardUI;
	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UQuestBulletinFocusedUI> _xQuestBulletinFocusedUI;
	UPROPERTY(EditAnywhere, Category = "UI")
	UTexture2D* _xEmptyIconBulletin;

	UPROPERTY() 
	TMap<UQuestBulletinUI*, FQuestUIElement> _mQuestUIElements;
	
private:	
	void SetupQuestUIElements();
	int FindQuestID(FString questID);
	bool FindQuestActive(FString questID);
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Sets default values for this component's properties
	UQuestBoard();
	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void FillQuestBulletins(EventParameters parameters);
	void ActiveFillQuestBulletins(EventParameters parameters);
	void BulletinCheck();
	void AddQuest(EventParameters parameters);
	void RemoveQuestFromBoard(EventParameters parameters);
};