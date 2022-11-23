// Copyright Epic Games, Inc. All Rights Reserved.


#include "SuperMarioGameModeBase.h"

#include "Player/MarioCharacter.h"

ASuperMarioGameModeBase::ASuperMarioGameModeBase()
{
	static ConstructorHelpers::FClassFinder<AMarioCharacter> MarioClass(
		TEXT("Blueprint'/Game/SuperMario/BluePrints/Mario/BP_Mario.BP_Mario_C'"));
	DefaultPawnClass = MarioClass.Class;
}
