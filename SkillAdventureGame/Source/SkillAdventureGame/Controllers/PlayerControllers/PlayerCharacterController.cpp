// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacterController.h"
#include "PlayerCharacter/PlayerCharacter.h"


void APlayerCharacterController::BeginPlay()
{
	this->SetInputMode(FInputModeGameOnly());
	this->bShowMouseCursor = false;
}

void APlayerCharacterController::SetPlayerCharacter(APlayerCharacter* inCharacter)
{
	PlayerCharacter = inCharacter;
}

void APlayerCharacterController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("Move Forward", this, &APlayerCharacterController::MoveForward);
	InputComponent->BindAxis("Move Right", this, &APlayerCharacterController::MoveRight);
	InputComponent->BindAxis("Look Horizontal", this, &APlayerCharacterController::AddYawInput);
	InputComponent->BindAxis("Look Vertical", this, &APlayerCharacterController::AddPitchInput);

	InputComponent->BindAction("Jump", IE_Pressed, this, &APlayerCharacterController::BeginJump);
	InputComponent->BindAction("Jump", IE_Released, this, &APlayerCharacterController::EndJump);
}

void APlayerCharacterController::MoveForward(float Axis)
{
	if (PlayerCharacter)
	{
		if (Axis != 0.f)
		{
			FVector Direction = PlayerCharacter->GetActorForwardVector();
			PlayerCharacter->AddMovementInput(Direction, Axis);
		}
	}
	else{UE_LOG(LogTemp, Error, TEXT("Issue with player character!")) return;}
}

void APlayerCharacterController::MoveRight(float Axis)
{
	if (PlayerCharacter)
	{
		if (Axis != 0.f)
		{
			FVector Direction = PlayerCharacter->GetActorRightVector();
			PlayerCharacter->AddMovementInput(Direction, Axis);
		}
	}
	else{UE_LOG(LogTemp, Error, TEXT("Issue with player character!")) return;}
}

void APlayerCharacterController::BeginJump()
{
	PlayerCharacter->bPressedJump = true;
}

void APlayerCharacterController::EndJump()
{
	PlayerCharacter->bPressedJump = false;
}
