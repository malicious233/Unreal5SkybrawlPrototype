// Copyright Epic Games, Inc. All Rights Reserved.

#include "SkybrawlProject2022GameMode.h"
#include "SkybrawlProject2022Character.h"
#include "UObject/ConstructorHelpers.h"

ASkybrawlProject2022GameMode::ASkybrawlProject2022GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
