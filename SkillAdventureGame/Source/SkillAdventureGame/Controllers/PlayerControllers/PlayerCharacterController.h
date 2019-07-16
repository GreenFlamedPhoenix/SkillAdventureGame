// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerCharacterController.generated.h"
class APlayerCharacter;

/**
 * 
 */
UCLASS()
class SKILLADVENTUREGAME_API APlayerCharacterController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

	UPROPERTY()
	APlayerCharacter* PlayerCharacter;

	UFUNCTION()
	void SetPlayerCharacter(APlayerCharacter* inCharacter);

	UFUNCTION()
	void MoveForward(float Axis);
	UFUNCTION()
	void MoveRight(float Axis);
	UFUNCTION()
	void BeginJump();
	UFUNCTION()
	void EndJump();
};