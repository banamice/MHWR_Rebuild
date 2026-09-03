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
