// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"

#include "MHW_ViewModeBase.generated.h"



/**
 * 
 */
UCLASS()
class MHWR_REBUILD_API UMHW_ViewModeBase : public UMVVMViewModelBase
{
	GENERATED_BODY()
	

	
public:
	UFUNCTION(BlueprintPure, FieldNotify)
	float GetHealthPercent() const
	{
		if (MaxHealth != 0)
		{
			return (float) CurrentHealth / (float) MaxHealth;
		}
		else
			return 0;
	}
	
	void SetCurrentHealth(float NewCurrentHealth)
	{
		if (UE_MVVM_SET_PROPERTY_VALUE(CurrentHealth, NewCurrentHealth))
		{
			UE_MVVM_BROADCAST_FIELD_VALUE_CHANGED(GetHealthPercent);
		}
	}

	void SetMaxHealth(float NewMaxHealth)
	{
		if (UE_MVVM_SET_PROPERTY_VALUE(MaxHealth, NewMaxHealth))
		{
			UE_MVVM_BROADCAST_FIELD_VALUE_CHANGED(GetHealthPercent);
		}

	}

	float GetCurrentHealth() const
	{
		return CurrentHealth;
	}

	float GetMaxHealth() const
	{
		return MaxHealth;
	}
private:
	UPROPERTY(FieldNotify,Getter,Setter,BlueprintReadWrite,meta=(AllowPrivateAccess=true))
	float CurrentHealth;
	UPROPERTY(FieldNotify,Getter,Setter,BlueprintReadWrite,meta=(AllowPrivateAccess=true))
	float MaxHealth;

};
