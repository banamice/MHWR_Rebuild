// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "Blueprint/UserWidget.h"
#include "MHW_WidgetBase.generated.h"

/**
 * 
 */
UCLASS()
class MHWR_REBUILD_API UMHW_WidgetBase : public UUserWidget
{
	GENERATED_BODY()
protected:
	
	void SetCurrentHealth(float NewCurrentHealth)
	{
		CurrentHealth = NewCurrentHealth;
		OnHealthChanged_Implementation(NewCurrentHealth);
	}

	void SetMaxHealth(float NewMaxHealth)
	{
		MaxHealth = NewMaxHealth;
		UE_MVVM_BROADCAST_FIELD_VALUE_CHANGED(MaxHealth);
	}

	float GetCurrentHealth() const
	{
		return CurrentHealth;
	}

	float GetMaxHealth() const
	{
		return MaxHealth;
	}
	
	UFUNCTION(BlueprintNativeEvent)
	void OnHealthChanged_Implementation(float NewHealth);
	
	
private:
	UPROPERTY(BlueprintReadWrite,Getter,Setter,FieldNotify, Category = "MVVM",meta=(AllowPrivateAccess=true))
	float CurrentHealth;
	UPROPERTY(BlueprintReadWrite,Getter,Setter,FieldNotify, Category = "MVVM",meta=(AllowPrivateAccess=true))
	float MaxHealth;
	
};
