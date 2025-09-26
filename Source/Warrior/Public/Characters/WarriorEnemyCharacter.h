// Baris Ayik

#pragma once

#include "CoreMinimal.h"
#include "Characters/WarriorBaseCharacter.h"
#include "WarriorEnemyCharacter.generated.h"

class UEnemyCombatComponent;

/**
 * 
 */
UCLASS()
class WARRIOR_API AWarriorEnemyCharacter : public AWarriorBaseCharacter
{
	GENERATED_BODY()
	
public :
	AWarriorEnemyCharacter();
	//~ Begin IPawnCombatInterface Interface
	virtual UPawnCombatComponent* GetPawnCombatComponent() const override;
	//~ End IPawnCombatInterface Interface


protected:
	//Begin APawn Interface
	virtual void PossessedBy(AController* NewController) override;
	//End APawn Interface

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UEnemyCombatComponent* EnemyCombatComponent;

private:
	void InitEnemyStartUpData();	


public:
	FORCEINLINE UEnemyCombatComponent* GetEnemyCombatComponent() const { return EnemyCombatComponent; }
};
