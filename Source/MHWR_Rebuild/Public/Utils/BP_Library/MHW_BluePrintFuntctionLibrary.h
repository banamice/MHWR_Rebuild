// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MHW_BluePrintFuntctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class MHWR_REBUILD_API UMHW_BluePrintFuntctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintPure, Category="MVVM|Conversion")
	static FText HealthToPercent( float InFloat);
};
