// Fill out your copyright notice in the Description page of Project Settings.


#include "IronOreDeposit.h"

// Sets default values
AIronOreDeposit::AIronOreDeposit()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	DepositHealth = 300;
}

void AIronOreDeposit::TakeDamage_Implementation(int32 inDamage)
{
	DepositHealth -= inDamage;
	UE_LOG(LogTemp, Warning, TEXT("Deposit took damage!"))
	if (DepositHealth <= 0)
	{
		this->Destroy();
	}
}