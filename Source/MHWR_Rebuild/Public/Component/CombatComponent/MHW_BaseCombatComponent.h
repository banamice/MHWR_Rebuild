#pragma once

#include "CoreMinimal.h"
#include "MHW_CombatState.h"
#include "Component/MHW_ActorComponentBase.h"
#include "MHW_BaseCombatComponent.generated.h"


enum class ECombatState : uint8;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MHWR_REBUILD_API UMHW_BaseCombatComponent : public UMHW_BaseActorComponent
{
	GENERATED_BODY()

public:
	UMHW_BaseCombatComponent();
	void Equip();
	void UnEquip();
	
private:
	UPROPERTY(BlueprintReadWrite,Category="MHW",meta=(AllowPrivateAccess="true"))
	ECombatState CombatState = ECombatState::UnEquipped;

	
#pragma region  //Getter  Setter
public:
	ECombatState GetCombatState() const
	{
		return CombatState;
	}

	void SetCombatState(const ECombatState NewCombatState)
	{
		CombatState = NewCombatState;
	}
#pragma endregion
};
