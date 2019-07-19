// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickUpBase.generated.h"

UCLASS()
class SKILLADVENTUREGAME_API APickUpBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickUpBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UPROPERTY()
	FTimerHandle DespawnTimer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "1. Spawning")
	int32 DespawnCountdown = 60;

	UFUNCTION()
	void ManageDespawnTimer();

};
