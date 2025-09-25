// Baris Ayik


#include "AninInstances/Hero/WarriorHeroLinkedAnimLayer.h"
#include "AninInstances/Hero/WarriorHeroAnimInstance.h"

UWarriorHeroAnimInstance* UWarriorHeroLinkedAnimLayer::GetHeroAnimInstance() const
{
	return Cast<UWarriorHeroAnimInstance>(GetOwningComponent()->GetAnimInstance());
  
}
