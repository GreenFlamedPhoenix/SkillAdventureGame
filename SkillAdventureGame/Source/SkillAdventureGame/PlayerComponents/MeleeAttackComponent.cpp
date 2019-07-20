// Fill out your copyright notice in the Description page of Project Settings.


#include "MeleeAttackComponent.h"
#include "PlayerCharacter/PlayerCharacter.h"
#include "CollisionQueryParams.h"
#include "DrawDebugHelpers.h"

// Sets default values for this component's properties
UMeleeAttackComponent::UMeleeAttackComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}

void UMeleeAttackComponent::BeginPlay()
{
	Super::BeginPlay();

	PlayerCharacter = Cast<APlayerCharacter>(GetWorld()->GetFirstPlayerController()->GetCharacter());
}

void UMeleeAttackComponent::MeleeAttack()
{
	if (!bIsAttacking)
	{
		UE_LOG(LogTemp, Warning, TEXT("Attacking"))
		bIsAttacking = true;

		FVector Location;
		FRotator Rotation;

		FHitResult TraceHit;
		FVector StartPoint = GetWorld()->GetFirstPlayerController()->GetFocalLocation();
		FVector EndPoint = StartPoint + GetWorld()->GetFirstPlayerController()->GetControlRotation().Vector() * 256;
		AActor* ActorToIgnore = PlayerCharacter;
		ECollisionChannel CollisionChannel = ECC_Pawn;
		FCollisionQueryParams TraceParams(FName(TEXT("Default")), true, ActorToIgnore);
		TraceParams.bTraceComplex = true;
		TraceParams.AddIgnoredActor(ActorToIgnore);

		GetWorld()->LineTraceSingleByChannel(TraceHit, StartPoint, EndPoint, ECC_Pawn, TraceParams);

		DrawDebugLine(GetWorld(), StartPoint, EndPoint, FColor::Cyan, true, 5.f);

		if (TraceHit.GetActor() != nullptr)
		{
			//UE_LOG(LogTemp, Warning, TEXT("Hit someting!"))
			ICombatInterface* CombatInterface = Cast<ICombatInterface>(TraceHit.GetActor());
			if (CombatInterface)
			{
				ICombatInterface::Execute_TakeDamage(TraceHit.GetActor(), 100);
			}
			
		}
	}
} 