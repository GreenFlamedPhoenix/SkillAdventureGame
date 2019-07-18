// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PlayerCharacterController.generated.h"
class APlayerCharacter;
class UMeleeAttackComponent;

/**
 * 
 */
UCLASS()
class SKILLADVENTUREGAME_API APlayerCharacterController : public APlayerController
{
	GENERATED_BODY()

public:
	APlayerCharacterController();
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UMeleeAttackComponent* MeleeAttackComponent;

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
	UFUNCTION()
	void ToggleWalk();
	UFUNCTION()
	void BeginSprint();
	UFUNCTION()
	void EndSprint();
	UFUNCTION()
	void AttackDelegate();

	UPROPERTY()
	bool bIsWalking = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "2. Movement Speed")
	float SprintSpeed = 950.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "2. Movement Speed")
	float JogSpeed = 500.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "2. Movement Speed")
	float WalkSpeed = 200.f;
};