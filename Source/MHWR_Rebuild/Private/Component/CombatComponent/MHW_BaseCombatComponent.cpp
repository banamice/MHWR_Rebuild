#include "Component/CombatComponent/MHW_BaseCombatComponent.h"

#include "MHWR_Rebuild/MHWR_Rebuild.h"


UMHW_BaseCombatComponent::UMHW_BaseCombatComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UMHW_BaseCombatComponent::Equip(EWeaponType InEquipWeapon)
{
	CombatState = ECombatState::ECS_Equipped;
	EquipWeaponType = InEquipWeapon;
}

void UMHW_BaseCombatComponent::UnEquip()
{
	CombatState = ECombatState::ECS_UnEquipped;
	EquipWeaponType = EWeaponType::EWT_None;
}

void UMHW_BaseCombatComponent::Aim()
{
	CombatState = ECombatState::ECS_Aiming;
}

void UMHW_BaseCombatComponent::UnAim()
{
	CombatState = ECombatState::ECS_Equipped;
}

