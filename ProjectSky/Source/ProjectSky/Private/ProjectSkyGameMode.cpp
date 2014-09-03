// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "ProjectSky.h"
#include "ProjectSkyGameMode.h"
#include "ProjectSkyPlayerController.h"
#include "ProjectSkyCharacter.h"

AProjectSkyGameMode::AProjectSkyGameMode(const class FPostConstructInitializeProperties& PCIP) : Super(PCIP)
{
	// use our custom PlayerController class
	PlayerControllerClass = AProjectSkyPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/MyCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}