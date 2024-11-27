// Copyright Epic Games, Inc. All Rights Reserved.

#include "PenguinGameGameMode.h"
#include "PenguinGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

APenguinGameGameMode::APenguinGameGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
