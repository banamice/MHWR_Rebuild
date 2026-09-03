#include "Component/CombatComponent/MHW_BaseCombatComponent.h"

#include "MHWR_Rebuild/MHWR_Rebuild.h"


UMHW_BaseCombatComponent::UMHW_BaseCombatComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UMHW_BaseCombatComponent::Equip()
{
	UE_LOG(LogMHW, Warning, TEXT("Equip"));
	CombatState = ECombatState::Equipped;
}

void UMHW_BaseCombatComponent::UnEquip()
{
	UE_LOG(LogMHW, Warning, TEXT("UnEquip"));
	CombatState = ECombatState::UnEquipped;
}

