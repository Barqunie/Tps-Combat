// Baris Ayik


#include "AninInstances/Hero/WarriorHeroAnimInstance.h"
#include "Characters/WarriorHeroCharacter.h"

void UWarriorHeroAnimInstance::NativeInitializeAnimation()
{
    Super::NativeInitializeAnimation();

    if (OwningCharacter)
    {
        OwningHeroCharacter = Cast<AWarriorHeroCharacter>(OwningCharacter);
    }
}

void UWarriorHeroAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
    Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);

    if (bHasAcceleration)
    {
        IdleTimeElapsed = 0.f;
        bShloudEnterRelaxState = false;
    }
    else
    {
        IdleTimeElapsed += DeltaSeconds;
        bShloudEnterRelaxState = IdleTimeElapsed >= EnterRelaxStateTreshold;
    }
}