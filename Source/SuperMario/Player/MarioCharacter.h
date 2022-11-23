// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "MarioCharacter.generated.h"

/**
 * 
 */
UCLASS()
class SUPERMARIO_API AMarioCharacter : public APaperCharacter
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;

	void BindInputComponent();

	//响应用户输入轴值事件
	void MoveRight(float Value);
	
public:
	virtual void Tick(float DeltaSeconds) override;
	
};
