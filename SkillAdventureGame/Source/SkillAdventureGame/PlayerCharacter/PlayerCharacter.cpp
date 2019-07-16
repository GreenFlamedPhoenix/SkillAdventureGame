// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "Controllers/PlayerControllers/PlayerCharacterController.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	PlayerCharacterController = Cast<APlayerCharacterController>(GetWorld()->GetFirstPlayerController());
	PlayerCharacterController->SetPlayerCharacter(this);
}