// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Controllers/PlayerControllers/PlayerCharacterController.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	CameraSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera SpringArm"));
	if (CameraSpringArm)
	{
		CameraSpringArm->SetupAttachment(RootComponent);
		CameraSpringArm->TargetArmLength = 450.f;
		CameraSpringArm->bEnableCameraLag = true;
		CameraSpringArm->CameraLagSpeed = 5.f;
	}
	CharacterCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Player Camera"));
	if (CharacterCamera)
	{
		CharacterCamera->AttachTo(CameraSpringArm);
	}
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	PlayerCharacterController = Cast<APlayerCharacterController>(GetWorld()->GetFirstPlayerController());
	PlayerCharacterController->SetPlayerCharacter(this);
	CameraSpringArm->SetWorldRotation(FRotator(-30.f, 0.f, 0.f));
}