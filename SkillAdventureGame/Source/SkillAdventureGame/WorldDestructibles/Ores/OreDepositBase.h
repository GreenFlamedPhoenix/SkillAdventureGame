// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/CombatInterface.h"
#include "OreDepositBase.generated.h"

UCLASS()
class SKILLADVENTUREGAME_API AOreDepositBase : public AActor, public ICombatInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOreDepositBase();
	
	UPROPERTY()
	int32 DepositHealth;
};
