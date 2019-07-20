// Fill out your copyright notice in the Description page of Project Settings.


#include "EmeraldOreItem.h"
#include "PlayerCharacter/PlayerCharacter.h"

AEmeraldOreItem::AEmeraldOreItem()
{
	ItemName = "Emerald Ore Chunk";
}

/*
void AEmeraldOreItem::AddToInventory()
{
	PlayerCharacter->PlayerCraftingInventory.Emplace(ItemName) = *PlayerCharacter->PlayerCraftingInventory.Find(ItemName) + 1;
	UE_LOG(LogTemp, Warning, TEXT("Emerald chunks now %i"), *PlayerCharacter->PlayerCraftingInventory.Find(ItemName))
	this->Destroy();
} */