
#pragma once

#include "CoreMinimal.h"
#include "DataSystem/ItemData/BaseItem.h"
#include "QuestSystem/QuestData/Modules/DA_QuestModuleBase.h"
#include "DA_ItemCollectModule.generated.h"

/**
 * 
 */
UCLASS()
class FISHYBUSINESS_API UDA_ItemCollectModule : public UDA_QuestModuleBase
{
	GENERATED_BODY()

public:	
	UPROPERTY(EditAnywhere)
	UBaseItem* xTypeOfItem;
	
	UPROPERTY(EditAnywhere)
	int iAmount;

};
