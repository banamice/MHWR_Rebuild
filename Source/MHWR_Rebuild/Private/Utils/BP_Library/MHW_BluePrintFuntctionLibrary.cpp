// Fill out your copyright notice in the Description page of Project Settings.


#include "Utils/BP_Library/MHW_BluePrintFuntctionLibrary.h"

FText UMHW_BluePrintFuntctionLibrary::HealthToPercent(float InFloat)
{
	return FText::AsPercent(FMath::Clamp(InFloat, 0.0f, 1.0f));
}
