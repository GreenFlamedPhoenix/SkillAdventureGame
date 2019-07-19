// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WorldDestructibles/Ores/OreDepositBase.h"
#include "EmeraldOreDeposit.generated.h"

/**
 * 
 */
UCLASS()
class SKILLADVENTUREGAME_API AEmeraldOreDeposit : public AOreDepositBase
{
	GENERATED_BODY()
	
public:
	AEmeraldOreDeposit();
	virtual void TakeDamage_Implementation(int32 inDamage) override;
};
