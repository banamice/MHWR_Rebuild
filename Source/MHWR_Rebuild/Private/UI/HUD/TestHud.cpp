// Fill out your copyright notice in the Description page of Project Settings.


#include "MHWR_Rebuild/Public/UI/HUD/TestHud.h"

#include "Blueprint/UserWidget.h"
#include "GameFramework/PlayerController.h"

void ATestHud::BeginPlay()
{
	Super::BeginPlay();
	
	check(TestWidgetClass)
	TestWidget = CreateWidget<UUserWidget>(GetWorld(), TestWidgetClass);
	TestWidget->AddToViewport();

	if (APlayerController* PlayerController = GetOwningPlayerController())
	{
		FInputModeGameAndUI InputMode;
		InputMode.SetWidgetToFocus(TestWidget->TakeWidget());
		InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
		PlayerController->SetInputMode(InputMode);
		PlayerController->bShowMouseCursor = true;
	}
}
