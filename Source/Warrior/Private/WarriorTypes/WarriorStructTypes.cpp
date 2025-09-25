// Baris Ayik


#include "WarriorTypes/WarriorStructTypes.h"
#include "AbilitySystem/Abilites/WarriorGameplayAbility.h"

bool FWarriorHeroAbilitySet::IsValid() const
{
	return InputTag.IsValid() && *AbilityToGrant;
}
