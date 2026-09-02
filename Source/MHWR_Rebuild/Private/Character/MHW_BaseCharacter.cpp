// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/MHW_BaseCharacter.h"


// Sets default values
AMHW_BaseCharacter::AMHW_BaseCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMHW_BaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMHW_BaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AMHW_BaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

