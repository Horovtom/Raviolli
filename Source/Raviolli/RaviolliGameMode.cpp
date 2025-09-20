// Copyright Epic Games, Inc. All Rights Reserved.

#include "RaviolliGameMode.h"
#include "RaviolliPlayerController.h"
#include "RaviolliCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARaviolliGameMode::ARaviolliGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ARaviolliPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != nullptr)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}