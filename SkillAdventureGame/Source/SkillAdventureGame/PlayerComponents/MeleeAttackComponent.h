// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/CombatInterface.h"
#include "Components/ActorComponent.h"
#include "MeleeAttackComponent.generated.h"
class APlayerCharacter;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SKILLADVENTUREGAME_API UMeleeAttackComponent : public UActorComponent, public ICombatInterface
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMeleeAttackComponent();

	virtual void BeginPlay() override;

	UPROPERTY()
	APlayerCharacter* PlayerCharacter;

	UFUNCTION()
	void MeleeAttack();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool bIsAttacking = false;
};