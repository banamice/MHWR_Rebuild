// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MHW_ICombatComponent.generated.h"

class UMHW_BaseCombatComponent;
// This class does not need to be modified.
UINTERFACE(NotBlueprintable)
class UMHW_ICombatComponent : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MHWR_REBUILD_API IMHW_ICombatComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="MHW")
	virtual UMHW_BaseCombatComponent* GetCombatComponent() = 0;
};
