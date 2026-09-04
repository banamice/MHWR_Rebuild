// Fill out your copyright notice in the Description page of Project Settings.


#include "Locomotion/MHW_BaseAnimInstance.h"

void UMHW_BaseAnimInstance::SetCombatState_Implementation(ECombatState InCombatState)
{
	IMHW_IAnimInstance::SetCombatState_Implementation(InCombatState);
	CombatState = InCombatState;
}

void UMHW_BaseAnimInstance::SetMoveState_Implementation(EMoveState InMoveState)
{
	IMHW_IAnimInstance::SetMoveState_Implementation(InMoveState);
	MoveState = InMoveState;
}

