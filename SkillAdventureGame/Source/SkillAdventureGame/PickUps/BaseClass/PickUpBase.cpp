// Fill out your copyright notice in the Description page of Project Settings.


#include "PickUpBase.h"

// Sets default values
APickUpBase::APickUpBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APickUpBase::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(DespawnTimer, this, &APickUpBase::ManageDespawnTimer, 1.f, true);
	
}

void APickUpBase::ManageDespawnTimer()
{
	if (DespawnCountdown > 0)
	{
		DespawnCountdown -= 1;
	}
	else
	{
		this->Destroy();
	}
}