// Fill out your copyright notice in the Description page of Project Settings.

#include "MySaveGame.h"
#include "PenguinGame.h"

UMySaveGame::UMySaveGame()
{
	SaveSlotName = TEXT("SaveSlot1");
	UserIndex = 0;
	WorldContextObject = GetWorld();
}