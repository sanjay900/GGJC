// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "GGJCPlayerController.h"
#include "AI/Navigation/NavigationSystem.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "GGJCCharacter.h"

AGGJCPlayerController::AGGJCPlayerController()
{
}

void AGGJCPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	
}

void AGGJCPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();
	InputComponent->BindAxis("MoveForward", this, &AGGJCPlayerController::MoveUp);
	InputComponent->BindAxis("MoveRight", this, &AGGJCPlayerController::MoveRight);
}
void AGGJCPlayerController::MoveUp(float Value)
{
	if (AGGJCCharacter* MyPawn = Cast<AGGJCCharacter>(GetPawn()))
	{
		FRotator Rotation = MyPawn->GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);
		MyPawn->AddMovementInput(Direction, Value);
	}
}

void AGGJCPlayerController::MoveRight(float Value)
{
	if (AGGJCCharacter* MyPawn = Cast<AGGJCCharacter>(GetPawn()))
	{
		FRotator Rotation = MyPawn->GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);
		MyPawn->AddMovementInput(Direction, Value);
	}
}
