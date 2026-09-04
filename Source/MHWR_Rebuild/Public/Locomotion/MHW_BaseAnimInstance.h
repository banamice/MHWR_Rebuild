// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MHW_IAnimInstance.h"
#include "Animation/AnimInstance.h"
#include "Character/MoveState.h"
#include "Component/CombatComponent/MHW_CombatState.h"
#include "MoveParameters/MoveParameters.h"
#include "MHW_BaseAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class MHWR_REBUILD_API UMHW_BaseAnimInstance : public UAnimInstance,public IMHW_IAnimInstance
{
	GENERATED_BODY()
	
public:
	virtual void SetCombatState_Implementation(ECombatState InCombatState) override;
	virtual void SetMoveState_Implementation(EMoveState InMoveState) override;

private:
	UPROPERTY(BlueprintReadWrite,Category="MHW",meta=(AllowPrivateAccess="true"))
	EMoveState MoveState = EMoveState::Idle;
	UPROPERTY(BlueprintReadWrite,Category="MHW",meta=(AllowPrivateAccess="true"))
	ECombatState CombatState = ECombatState::ECS_UnEquipped;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="MHW",meta=(AllowPrivateAccess="true"))
	FDebugOption DebugOption;
	UPROPERTY(BlueprintReadWrite,Category="MHW",meta=(AllowPrivateAccess="true"))
	EMoveDirection VelocityDirectionEnumBaseRotation = EMoveDirection::EMD_Forward;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="MHW",meta=(AllowPrivateAccess="true"))
	float MinRightDegree = 45.f;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="MHW",meta=(AllowPrivateAccess="true"))
	float MaxRightDegree = 135.f;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="MHW",meta=(AllowPrivateAccess="true"))
	float MinLeftDegree = -135.f;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="MHW",meta=(AllowPrivateAccess="true"))
	float MaxLeftDegree = -45.f;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="MHW",meta=(AllowPrivateAccess="true"))
	float DeadZone = 20.f;
};
