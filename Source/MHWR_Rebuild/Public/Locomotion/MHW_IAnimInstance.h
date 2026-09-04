// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MHW_IAnimInstance.generated.h"

enum class ECombatState : uint8;
enum class EMoveState : uint8;

UINTERFACE(Blueprintable,BlueprintType)
class UMHW_IAnimInstance : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MHWR_REBUILD_API IMHW_IAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable, Category="MHW")
	 void SetMoveState(EMoveState InMoveState) ;
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable, Category="MHW")
	 void SetCombatState(ECombatState InCombatState) ;
};
