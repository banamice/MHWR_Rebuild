// Fill out your copyright notice in the Description page of Project Settings.


#include "Locomotion/MHW_BaseAnimInstance.h"

void UMHW_BaseAnimInstance::SetMoveState(EMoveState InMoveState)
{
	MoveState = InMoveState;
}

void UMHW_BaseAnimInstance::SetCombatState(ECombatState InCombatState)
{
	CombatState = InCombatState;
}
