// Fill out your copyright notice in the Description page of Project Settings.


#include "EmeraldOreDeposit.h"

AEmeraldOreDeposit::AEmeraldOreDeposit()
{
	DepositHealth = 300;
}

void AEmeraldOreDeposit::TakeDamage_Implementation(int32 inDamage)
{
	DepositHealth -= inDamage;
	UE_LOG(LogTemp, Warning, TEXT("Deposit took damage!"))
	if (DepositHealth <= 0)
	{
		this->Destroy();
	}
}