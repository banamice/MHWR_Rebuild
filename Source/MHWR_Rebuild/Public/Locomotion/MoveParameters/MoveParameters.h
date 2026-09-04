// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "MoveParameters.generated.h"

/**
 * 
 */
USTRUCT(Blueprintable,BlueprintType)
struct FMoveParameters
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxWalkSpeed = 600.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxAcceleration = 2048.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BrakingDeceleration = 2048.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BrakingFrictionFactor = 2.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BrakingFriction = 0.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bUseSeparateBrakingFriction = false;
};

USTRUCT(Blueprintable,BlueprintType)
struct FDebugOption
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bDrawArrow = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bDrawText = true;
};

UENUM(BlueprintType,BlueprintType)
enum class EMoveDirection : uint8
{
	EMD_Forward,
	EMD_Backward,
	EMD_Left,
	EMD_Right
};