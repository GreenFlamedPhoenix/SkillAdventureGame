// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/CombatInterface.h"
//#include "GameFramework/Actor.h"
#include "WorldDestructibles/Ores/OreDepositBase.h"
#include "IronOreDeposit.generated.h"

UCLASS()
class SKILLADVENTUREGAME_API AIronOreDeposit : public AOreDepositBase
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AIronOreDeposit();

	virtual void TakeDamage_Implementation(int32 inDamage) override;
};
