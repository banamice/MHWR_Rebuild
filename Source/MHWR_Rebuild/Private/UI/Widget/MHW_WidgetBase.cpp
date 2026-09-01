// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/MHW_WidgetBase.h"

void UMHW_WidgetBase::OnHealthChanged_Implementation_Implementation(float NewHealth)
{
	UE_LOG(LogTemp, Warning, TEXT("CurrentHealth: %f"), CurrentHealth);
}
