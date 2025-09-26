// Baris Ayik


#include "Components/Combat/PawnCombatComponent.h"
#include "Items/Weapons/WarriorWeaponBase.h"
#include "Components/BoxComponent.h"
#include "WarriorDebugHelper.h"


void UPawnCombatComponent::RegisterSpawnedWeapon(const FGameplayTag InWeaponTagToRegister, AWarriorWeaponBase* InWeaponToRegister, bool bRegisterAsEquippedWeapon)
{
	checkf(!CharacterCarriedWeaponMap.Contains(InWeaponTagToRegister), TEXT("A named named %s has already been added as carried weapon"), *InWeaponTagToRegister.ToString());
	check(InWeaponToRegister);

	CharacterCarriedWeaponMap.Emplace(InWeaponTagToRegister, InWeaponToRegister);

	InWeaponToRegister->OnWeaponHitTarget.BindUObject(this, &ThisClass::OnHitTargetActor);
	InWeaponToRegister->OnWeaponPulledFromTarget.BindUObject(this, &ThisClass::OnWeaponPulledFromTarget);

	if(bRegisterAsEquippedWeapon)
		{
		CurrentEqquippedWeaponTag = InWeaponTagToRegister;
		}

	const FString WeaponString = FString::Printf(TEXT("A weapon named: %s has been registered using the taf %s"), *InWeaponToRegister->GetName(), *InWeaponTagToRegister.ToString());
	Debug::Print(WeaponString);
}

AWarriorWeaponBase* UPawnCombatComponent::GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const
{
	if(CharacterCarriedWeaponMap.Contains(InWeaponTagToGet))
	{
		if(AWarriorWeaponBase* const* FoundWeapon = CharacterCarriedWeaponMap.Find(InWeaponTagToGet))
		{
			return *FoundWeapon;
		}
	}

	return nullptr;
}

AWarriorWeaponBase* UPawnCombatComponent::GetCharacterCurrentEquippedWeapon() const
{
	if(!CurrentEqquippedWeaponTag.IsValid())
	{
	
			return nullptr;
	}
	return GetCharacterCarriedWeaponByTag(CurrentEqquippedWeaponTag);
}

void UPawnCombatComponent::ToggleWeaponCollision(bool bShouldEnable, EToggleDamageType ToggleDamageType)
{
	if (ToggleDamageType == EToggleDamageType::CurrentEquippedWeapon)
	{
		AWarriorWeaponBase* WeaponToToggle = GetCharacterCurrentEquippedWeapon();

		check(WeaponToToggle)

			if (bShouldEnable)
			{
				WeaponToToggle->GetWeaponCollisionBox()->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
			}
			else
			{
				WeaponToToggle->GetWeaponCollisionBox()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
				OverlappedActors.Empty();
			}
	}

	//TO DO: Body collision Boxes
}

void UPawnCombatComponent::OnHitTargetActor(AActor* HitActor)
{
}

void UPawnCombatComponent::OnWeaponPulledFromTarget(AActor* InteractedActor)
{
}
