#include "Character/MHW_BaseCharacter.h"

#include "Camera/CameraComponent.h"
#include "Component/CombatComponent/MHW_BaseCombatComponent.h"
#include "Components/CapsuleComponent.h"
#include "DataAsset/MHW_MoveParameters.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Locomotion/MHW_BaseAnimInstance.h"


AMHW_BaseCharacter::AMHW_BaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	
	
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetMesh());
	SpringArm->TargetArmLength = 250.f;
	SpringArm->SetRelativeRotation(FRotator(0.f, 90.f, 0.f));
	SpringArm->bUsePawnControlRotation = true;
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	
	CombatComponent = CreateDefaultSubobject<UMHW_BaseCombatComponent>(TEXT("CombatComponent"));
	
}

UMHW_BaseCombatComponent* AMHW_BaseCharacter::GetCombatComponent()
{
	GetValidCC();
	return CombatComponent;
}

void AMHW_BaseCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	OnPlayerControllerChanged();
}

void AMHW_BaseCharacter::OnRep_Controller()
{
	Super::OnRep_Controller();
	OnPlayerControllerChanged();
}

void AMHW_BaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	Cast<UCharacterMovementComponent>(GetMovementComponent())->bOrientRotationToMovement = true;
}

void AMHW_BaseCharacter::Equip()
{
	GetValidCC();
	if (!CombatComponent) return;
	
	//TODO:这里正常来说需要判断可装备的武器类型。这里先暂时写死longsSword,在combatComponewnt里 以下简称CC中会在收刀时切换回none
	CombatComponent->Equip(EWeaponType::EWT_LongSword);
	
	OnEquipWeaponChange(CombatComponent->GetEquipWeaponType());
	OnCombatStateChanged(CombatComponent->GetCombatState());
}

void AMHW_BaseCharacter::UnEquip()
{
	GetValidCC();
	if (!CombatComponent) return;
	//TODO::这里就已经出现了按键冲突了。在没有装备武器的情况下右shoudler应该是奔跑的，这里先简单判断一下。后续使用状态机做
	if (CombatComponent->GetCombatState()==ECombatState::ECS_Equipped)
	{
		CombatComponent->UnEquip();
		OnEquipWeaponChange(CombatComponent->GetEquipWeaponType());
		OnCombatStateChanged(CombatComponent->GetCombatState());
	}
	//切换式奔跑
	else if (MoveState == EMoveState::Walk)
	{
		MoveState = EMoveState::Run;
		OnMoveStateChange(MoveState);
	}else if (MoveState == EMoveState::Run)
	{
		MoveState = EMoveState::Walk;
		OnMoveStateChange(MoveState);
	}
}

void AMHW_BaseCharacter::Aim()
{
	GetValidCC();
	if (!CombatComponent) return;
	CombatComponent->Aim();
	OnCombatStateChanged(CombatComponent->GetCombatState());
}

void AMHW_BaseCharacter::UnAim()
{
	GetValidCC();
	if (!CombatComponent) return;
	CombatComponent->UnAim();
	OnCombatStateChanged(CombatComponent->GetCombatState());
	
}

void AMHW_BaseCharacter::OnPlayerControllerChanged()
{
	//有需要时完善	
}

void AMHW_BaseCharacter::OnCombatStateChanged_Implementation(ECombatState NewCombatState)
{
}

void AMHW_BaseCharacter::OnEquipWeaponChange_Implementation(EWeaponType NewWeaponType)
{
}

void AMHW_BaseCharacter::OnMoveStateChange_Implementation(EMoveState NewMoveState)
{
}

void AMHW_BaseCharacter::UpdateMoveParameters(EMoveState NewMoveState)
{
	if (!GetCharacterMovement()) return;
	check(MoveParameters)
	
	GetCharacterMovement()->MaxWalkSpeed = MoveParameters->MoveParametersMap.FindRef(NewMoveState).MaxWalkSpeed;
	GetCharacterMovement()->MaxAcceleration = MoveParameters->MoveParametersMap.FindRef(NewMoveState).MaxAcceleration;
	GetCharacterMovement()->BrakingDecelerationWalking = MoveParameters->MoveParametersMap.FindRef(NewMoveState).BrakingDeceleration;
	GetCharacterMovement()->BrakingFrictionFactor = MoveParameters->MoveParametersMap.FindRef(NewMoveState).BrakingFrictionFactor;
	GetCharacterMovement()->BrakingFriction = MoveParameters->MoveParametersMap.FindRef(NewMoveState).BrakingFriction;
	GetCharacterMovement()->bUseSeparateBrakingFriction = MoveParameters->MoveParametersMap.FindRef(NewMoveState).bUseSeparateBrakingFriction;
}

