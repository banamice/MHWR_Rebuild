// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/PlayerController.h"
#include "MHW_BasePlayerController.generated.h"

class AMHW_BaseCharacter;
class UMHW_InputData;
class UInputMappingContext;
/**
 * 
 */
UCLASS()
class MHWR_REBUILD_API AMHW_BasePlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	//自定义宏，方便的检测MHWCharacter是否还有效并且尝试赋值
#define GET_VALID_MHW_CHARACTER(Character) \
	Character = !(IsValid(Character) && Character.Get() == GetPawn()) ? Cast<AMHW_BaseCharacter>(GetPawn()) : Character.Get();
	
protected:
	virtual void BeginPlay() override;


	virtual void SetupInputComponent() override;
	
	
#pragma region  //成员变量
private:
	//输入数据资产
	UPROPERTY(EditDefaultsOnly,Category="MHW")
	TObjectPtr<UMHW_InputData> InputData;
	
	//先设置为base，因为这个是playerController 后续可能会用player替换
	UPROPERTY()
	TObjectPtr<AMHW_BaseCharacter> MHWCharacter;
#pragma endregion
	
	
#pragma region   //绑定回调
	UFUNCTION()
	void AimAction();
	UFUNCTION()
	void UnAimAction();
	UFUNCTION()
	void LookAction(const FInputActionValue& InputActionValue);
	UFUNCTION()
	void MoveAction(const FInputActionValue& InputActionValue);
	UFUNCTION()
	void EquipAction();
	UFUNCTION()
	void UnEquipAction();
#pragma endregion
	
public:
#pragma region   //Getter  Setter
	void SetMHWCharacter(AMHW_BaseCharacter* NewMHWCharacter){ MHWCharacter = NewMHWCharacter;}
#pragma endregion
	
};
