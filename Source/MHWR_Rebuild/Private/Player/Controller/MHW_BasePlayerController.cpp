// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/Controller/MHW_BasePlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Character/MHW_BaseCharacter.h"
#include "DataAsset/MHW_InputData.h"

void AMHW_BasePlayerController::BeginPlay()
{
	Super::BeginPlay();
} 


void AMHW_BasePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	check(InputData)
	//获取增强输入子系统
	if (GetLocalPlayer())
	{
		UEnhancedInputLocalPlayerSubsystem* System =  GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
		check(System)
		
		//正常来说应该会有本地角色的。当然如果是在DS服务器上，那么服务器会没有,但是也走不到这里来了
		
		System->AddMappingContext(InputData->InputMappingContext,0);
	}
	
	//需要cast一下，因为默认不是EnhancedInput
	UEnhancedInputComponent* Component = Cast<UEnhancedInputComponent>(InputComponent);
	check(Component)
	Component->BindAction(InputData->EquipAction,ETriggerEvent::Started,this,&AMHW_BasePlayerController::EquipAction);	
	Component->BindAction(InputData->UnEquipAction,ETriggerEvent::Started,this,&AMHW_BasePlayerController::UnEquipAction);	
	Component->BindAction(InputData->LookAction,ETriggerEvent::Triggered,this,&AMHW_BasePlayerController::LookAction);	
	Component->BindAction(InputData->MoveAction,ETriggerEvent::Triggered,this,&AMHW_BasePlayerController::MoveAction);	
	Component->BindAction(InputData->AimAction,ETriggerEvent::Started,this,&AMHW_BasePlayerController::AimAction);	
	Component->BindAction(InputData->AimAction,ETriggerEvent::Completed,this,&AMHW_BasePlayerController::UnAimAction);		
}



void AMHW_BasePlayerController::LookAction(const FInputActionValue& InputActionValue)
{
	if (InputActionValue.GetValueType() != EInputActionValueType::Axis2D)
	{
		return;
	}

	const FVector2D Vector2D = InputActionValue.Get<FVector2D>();
	AddYawInput(Vector2D.X);
	AddPitchInput(Vector2D.Y);
}

void AMHW_BasePlayerController::MoveAction(const FInputActionValue& InputActionValue)
{
	if (InputActionValue.GetValueType() != EInputActionValueType::Axis2D)
	{
		return;
	}
	const FVector2D Vector2D = InputActionValue.Get<FVector2D>();
	
	FVector ForwardVector =  FRotationMatrix(FRotator(0.f,GetControlRotation().Yaw,0.f)).GetUnitAxis(EAxis::X);
	FVector RightVector =  FRotationMatrix(FRotator(0.f,GetControlRotation().Yaw,0.f)).GetUnitAxis(EAxis::Y);
	
	GET_VALID_MHW_CHARACTER(MHWCharacter)
	if (!IsValid(MHWCharacter)) return;
	
	MHWCharacter->AddMovementInput(ForwardVector , Vector2D.Y);
	MHWCharacter->AddMovementInput(RightVector , Vector2D.X);
}

void AMHW_BasePlayerController::EquipAction()
{
	GET_VALID_MHW_CHARACTER(MHWCharacter)
	if (!IsValid(MHWCharacter)) return;
	
	MHWCharacter->Equip();
}

void AMHW_BasePlayerController::UnEquipAction()
{
	GET_VALID_MHW_CHARACTER(MHWCharacter)
	if (!IsValid(MHWCharacter)) return;
	
	MHWCharacter->UnEquip();
}

void AMHW_BasePlayerController::AimAction()
{
	GET_VALID_MHW_CHARACTER(MHWCharacter)
	if (!IsValid(MHWCharacter)) return;
	
	MHWCharacter->Aim();
}

void AMHW_BasePlayerController::UnAimAction()
{
	GET_VALID_MHW_CHARACTER(MHWCharacter)
	if (!IsValid(MHWCharacter)) return;
	
	MHWCharacter->UnAim();
}