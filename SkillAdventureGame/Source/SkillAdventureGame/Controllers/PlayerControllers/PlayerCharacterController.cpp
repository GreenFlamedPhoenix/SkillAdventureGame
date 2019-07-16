// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacterController.h"


void APlayerCharacterController::SetPlayerCharacter(APlayerCharacter* inCharacter)
{
	PlayerCharacter = inCharacter;
}

void APlayerCharacterController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("Move Forward", this, &APlayerCharacterController::MoveForward);
}

void APlayerCharacterController::MoveForward(float Axis)
{
	if (Axis != 0.f)
	{
		UE_LOG(LogTemp, Warning, TEXT("I am moving"))
	}
}