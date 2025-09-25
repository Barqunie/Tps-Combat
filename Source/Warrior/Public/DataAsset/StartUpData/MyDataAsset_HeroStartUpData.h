// Baris Ayik

#pragma once

#include "CoreMinimal.h"
#include "DataAsset/StartUpData/DataAsset_StartUpDataBase.h"
#include "WarriorTypes/WarriorStructTypes.h"
#include "MyDataAsset_HeroStartUpData.generated.h"


/**
 * 
 */
UCLASS()
class WARRIOR_API UMyDataAsset_HeroStartUpData : public UDataAsset_StartUpDataBase
{
	virtual void GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1) override;
	GENERATED_BODY()
	
private:
	UPROPERTY(EditDefaultsOnly, Category = "StartUpData", meta =(TitleProperty= "InputTag"))
	TArray<FWarriorHeroAbilitySet> HeroStartUpAbilitySets;
};
