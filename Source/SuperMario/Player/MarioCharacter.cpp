// Fill out your copyright notice in the Description page of Project Settings.


#include "MarioCharacter.h"
#include "Components/InputComponent.h"

void AMarioCharacter::BeginPlay()
{
	Super::BeginPlay();
	BindInputComponent();
}

void AMarioCharacter::BindInputComponent()
{
	
	if (!InputComponent)
	{
		return;
	}
	InputComponent->BindAxis(TEXT("MoveRight"), this, &AMarioCharacter::MoveRight);
	// InputComponent->BindAction(TEXT("DoJump"))
}

void AMarioCharacter::MoveRight(float Value)
{
	if(Value)
	{
		UE_LOG(LogTemp, Log, TEXT("%f"),Value);
	}
	
	//移动逻辑
	AddMovementInput(FVector(Value, 0, 0));
	
}

void AMarioCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}


