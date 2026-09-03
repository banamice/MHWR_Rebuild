#pragma once

#include "CoreMinimal.h"
#include "MoveState.h"
#include "Component/CombatComponent/MHW_ICombatComponent.h"
#include "GameFramework/Character.h"
#include "MHW_BaseCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class IMHW_IAnimInstance;
enum class EMoveState : uint8;

UCLASS()
class MHWR_REBUILD_API AMHW_BaseCharacter : public ACharacter,public IMHW_ICombatComponent
{
	GENERATED_BODY()
	
public:
	AMHW_BaseCharacter();
	UFUNCTION(BlueprintCallable, Category="MHW")
	virtual UMHW_BaseCombatComponent* GetCombatComponent() override;
	virtual void PossessedBy(AController* NewController) override;
	virtual  void OnRep_Controller() override;
	
#pragma region //绑定给controller的回调，内部直接调用了combat组件内容
	void Equip();
	void UnEquip();
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
	
private:
	UPROPERTY(BlueprintReadWrite,Category="MHW",meta=(AllowPrivateAccess="true"))
	EMoveState MoveState = EMoveState::Idle;


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
