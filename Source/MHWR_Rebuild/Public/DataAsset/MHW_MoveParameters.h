// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/MoveState.h"
#include "Engine/DataAsset.h"
#include "Locomotion/MoveParameters/MoveParameters.h"
#include "MHW_MoveParameters.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class MHWR_REBUILD_API UMHW_MoveParameters : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="MHW")
	TMap<EMoveState,FMoveParameters> MoveParametersMap;
	
};
