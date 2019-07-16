// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"
class UCameraComponent;
class USpringArmComponent;
class APlayerCharacterController;

UCLASS()
class SKILLADVENTUREGAME_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UPROPERTY()
	UCameraComponent* CharacterCamera;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USpringArmComponent* CameraSpringArm;


	UPROPERTY()
	APlayerCharacterController* PlayerCharacterController;

	UPROPERTY()
	float SpringArmLength = 450.f;
};