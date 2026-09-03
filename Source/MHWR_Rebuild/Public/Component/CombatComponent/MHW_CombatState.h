// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MHW_CombatState.generated.h"

UENUM(BlueprintType)
enum class ECombatState : uint8
{
	UnEquipped,
	Equipped,
	Combing,
	Stunning
};
