#pragma once

#include "CoreMinimal.h"
#include "MHW_CombatState.h"
#include "Component/MHW_ActorComponentBase.h"
#include "MHW_BaseCombatComponent.generated.h"


enum class ECombatState : uint8;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MHWR_REBUILD_API UMHW_BaseCombatComponent : public UMHW_BaseActorComponent
{
public:
	

private:
	GENERATED_BODY()

public:
	UMHW_BaseCombatComponent();
	void Equip(EWeaponType InEquipWeapon);
	void UnEquip();
	void Aim();
	void UnAim();
	
private:
	UPROPERTY(BlueprintReadWrite,Category="MHW",meta=(AllowPrivateAccess="true"))
	ECombatState CombatState = ECombatState::ECS_UnEquipped;

	//这里指的是装备在手上的武器类型。如果是未持有则是none
	UPROPERTY(blueprintReadOnly, Category = "MHW", meta = (AllowPrivateAccess = "true"))
	EWeaponType EquipWeaponType = EWeaponType::EWT_None;
	
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
	
	EWeaponType GetEquipWeaponType() const
	{
		return EquipWeaponType;
	}

	void SetEquipWeaponType(const EWeaponType NewEquipWeaponType)
	{
		this->EquipWeaponType = NewEquipWeaponType;
	}
#pragma endregion
};
