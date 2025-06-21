// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CompendioPageBase.h"
#include "MainCompendio.h"
#include "DataSystem/FishData/Fish.h"
#include "EventManager/EventWrapper.h"
#include "GameFramework/Actor.h"
#include "CompendioManager.generated.h"

UCLASS()
class FISHYBUSINESS_API ACompendioManager : public AActor
{
	GENERATED_BODY()
	
private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UMainCompendio> _xMainCompendio;
	
	UPROPERTY()
	int _iPageNum;

	bool _bIsOpen = false;
	int _iActualPageIndex = 1;
	int _iActualPageIndexPair = 0;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Sets default values for this actor's properties
	ACompendioManager();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void OpenCompendio();
	UFUNCTION(BlueprintCallable)
	void CloseCompendio();

	void GoToThisPage(EventParameters parameters);
	
	void GoToPrevPage();
	void GoToPrevPageEvent(EventParameters parameters);
	void GoToNextPage();
	void GoToNextPageEvent(EventParameters parameters);
	void CreateCatalogue(TArray<TSubclassOf<UCompendioPageBase>> pageList);
	void CatalogueFish(EventParameters parameters);

private:
	void CallCreatePage(int i, int j);
	
};