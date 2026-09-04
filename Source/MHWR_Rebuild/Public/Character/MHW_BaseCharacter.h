#pragma once

#include "CoreMinimal.h"
#include "MoveState.h"
#include "Component/CombatComponent/MHW_BaseCombatComponent.h"
#include "Component/CombatComponent/MHW_ICombatComponent.h"
#include "GameFramework/Character.h"
#include "MHW_BaseCharacter.generated.h"

class UMHW_MoveParameters;
class UCameraComponent;
class USpringArmComponent;
class IMHW_IAnimInstance;
enum class EMoveState : uint8;

UCLASS()
class MHWR_REBUILD_API AMHW_BaseCharacter : public ACharacter,public IMHW_ICombatComponent
{
	GENERATED_BODY()
	
#define GetValidCC()\
	CombatComponent = IsValid(CombatComponent) ? CombatComponent.Get() : NewObject<UMHW_BaseCombatComponent>(this, UMHW_BaseCombatComponent::StaticClass(), TEXT("CombatComponent"));
	
public:
	AMHW_BaseCharacter();
	UFUNCTION(BlueprintCallable, Category="MHW")
	virtual UMHW_BaseCombatComponent* GetCombatComponent() override;
	virtual void PossessedBy(AController* NewController) override;
	virtual  void OnRep_Controller() override;
	virtual void BeginPlay() override;
	
#pragma region //绑定给controller的回调，内部直接调用了combat组件内容
	void Equip();
	void UnEquip();
	void Aim();
	void UnAim();
#pragma endregion
	
protected:
	virtual void OnPlayerControllerChanged();
	
private:
#pragma region  //Component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,meta=(AllowPrivateAccess="true"))
	TObjectPtr<UMHW_BaseCombatComponent> CombatComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,meta=(AllowPrivateAccess="true"))
	TObjectPtr<USpringArmComponent> SpringArm;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,meta=(AllowPrivateAccess="true"))
	TObjectPtr<UCameraComponent> Camera;
	
#pragma endregion
	
#pragma region //Locomotion
public:
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable, Category = "MHW")
	void OnCombatStateChanged(ECombatState NewCombatState);
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable, Category = "MHW")
	void OnEquipWeaponChange(EWeaponType NewWeaponType);
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable, Category = "MHW")
	void OnMoveStateChange(EMoveState NewMoveState);
private:
	UPROPERTY(BlueprintReadWrite,Category="MHW",meta=(AllowPrivateAccess="true"))
	EMoveState MoveState = EMoveState::Idle;
	UPROPERTY(BlueprintReadOnly,EditDefaultsOnly,Category="MHW",meta=(AllowPrivateAccess="true"))
	TObjectPtr<UMHW_MoveParameters> MoveParameters;
	
	UFUNCTION(BlueprintCallable,Category="MHW")
	void UpdateMoveParameters(EMoveState NewMoveState);
#pragma endregion

#pragma region  //Getter  Setter
public:
	EMoveState GetMoveState() const
	{
		return MoveState;
	}

	void SetMoveState(const EMoveState NewMoveState)
	{
		MoveState = NewMoveState;
	}
#pragma endregion
};
