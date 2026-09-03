#include "Character/MHW_BaseCharacter.h"

#include "Camera/CameraComponent.h"
#include "Component/CombatComponent/MHW_BaseCombatComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Locomotion/MHW_BaseAnimInstance.h"
#include "Locomotion/MHW_IAnimInstance.h"


AMHW_BaseCharacter::AMHW_BaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	
	CombatComponent = CreateDefaultSubobject<UMHW_BaseCombatComponent>(TEXT("CombatComponent"));
	
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetMesh());
	SpringArm->TargetArmLength = 250.f;
	SpringArm->SetRelativeRotation(FRotator(0.f, 90.f, 0.f));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	
}

UMHW_BaseCombatComponent* AMHW_BaseCharacter::GetCombatComponent()
{
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

void AMHW_BaseCharacter::Equip()
{
	if (!CombatComponent) return;
	CombatComponent->Equip();

	if (IMHW_IAnimInstance* Instance =  Cast<IMHW_IAnimInstance>(GetMesh()->GetAnimInstance()))
	{
		Instance->SetCombatState(CombatComponent->GetCombatState());
	}
}

void AMHW_BaseCharacter::UnEquip()
{
	CombatComponent->UnEquip();
	if (IMHW_IAnimInstance* Instance = Cast<IMHW_IAnimInstance>(GetMesh()->GetAnimInstance()))
	{
		Instance->SetCombatState(ECombatState::UnEquipped);
	}
}

void AMHW_BaseCharacter::OnPlayerControllerChanged()
{
	//有需要时完善	
}

