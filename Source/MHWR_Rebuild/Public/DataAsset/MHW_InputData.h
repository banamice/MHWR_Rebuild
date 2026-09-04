// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "MHW_InputData.generated.h"

class UInputAction;
class UInputMappingContext;



/**
 * 
 */
UCLASS()
class MHWR_REBUILD_API UMHW_InputData : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly,Category="MHW")
	TObjectPtr<UInputMappingContext> InputMappingContext;
	UPROPERTY(EditDefaultsOnly,Category="MHW")
	TObjectPtr<UInputAction> EquipAction;
	UPROPERTY(EditDefaultsOnly,Category="MHW")
	TObjectPtr<UInputAction> UnEquipAction;
	UPROPERTY(EditDefaultsOnly,Category="MHW")
	TObjectPtr<UInputAction> LookAction;
	UPROPERTY(EditDefaultsOnly,Category="MHW")
	TObjectPtr<UInputAction> MoveAction;
	UPROPERTY(EditDefaultsOnly,Category="MHW")
	TObjectPtr<UInputAction> AimAction;
	
};
