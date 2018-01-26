// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "GGJCGameMode.h"
#include "GGJCPlayerController.h"
#include "GGJCCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGGJCGameMode::AGGJCGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AGGJCPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}