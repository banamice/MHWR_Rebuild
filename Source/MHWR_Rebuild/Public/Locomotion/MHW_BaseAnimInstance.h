// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MHW_IAnimInstance.h"
#include "Animation/AnimInstance.h"
#include "Character/MoveState.h"
#include "Component/CombatComponent/MHW_CombatState.h"
#include "MHW_BaseAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class MHWR_REBUILD_API UMHW_BaseAnimInstance : public UAnimInstance,public IMHW_IAnimInstance
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category="MHW")
	virtual void SetMoveState(EMoveState InMoveState) override;
	UFUNCTION(BlueprintCallable, Category="MHW")
	virtual void SetCombatState(ECombatState InCombatState) override;

private:
	UPROPERTY(BlueprintReadWrite,Category="MHW",meta=(AllowPrivateAccess="true"))
	EMoveState MoveState = EMoveState::Idle;
	UPROPERTY(BlueprintReadWrite,Category="MHW",meta=(AllowPrivateAccess="true"))
	ECombatState CombatState = ECombatState::UnEquipped;
};
