// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MHW_CombatState.generated.h"

UENUM(BlueprintType)
enum class ECombatState : uint8
{
	ECS_None,
	ECS_UnEquipped,
	ECS_Equipped,
	ECS_Combing,
	ECS_Stunning,
	ECS_Aiming,
	
	
	ECS_Max
};

UENUM(BlueprintType)
enum class EWeaponType : uint8
{
	EWT_None,
	EWT_LongSword,
	EWT_ChargeAxe,
	
	
	EWT_Max
};
