// Baris Ayik


#include "DataAsset/StartUpData/DataAsset_EnemyStartUpData.h"

#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "AbilitySystem/Abilites/WarriorGameplayAbility.h"

void UDataAsset_EnemyStartUpData::GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	Super::GiveToAbilitySystemComponent(InASCToGive, ApplyLevel);

	if (!EnemyCombatAbilities.IsEmpty())
	{
		for (const TSubclassOf<UWarriorGameplayAbility>& AbilityClass : EnemyCombatAbilities)
		{
			if (!AbilityClass) continue;

			FGameplayAbilitySpec AbilitySpec(AbilityClass);

			AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
			AbilitySpec.Level = ApplyLevel;

			InASCToGive->GiveAbility(AbilitySpec);

		}
	}
}

