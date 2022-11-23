// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraManActor.h"

#include "Camera/CameraComponent.h"
#include "Components/BillboardComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ACameraManActor::ACameraManActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<UBillboardComponent>(TEXT("RootComp"));

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->bDoCollisionTest = false;
	CameraBoom->SetRelativeRotation(FRotator(0, -90, 0));

	MainCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("MainCamera"));
	MainCamera->SetupAttachment(CameraBoom);
	MainCamera->ProjectionMode = ECameraProjectionMode::Orthographic;
}

// Called when the game starts or when spawned
void ACameraManActor::BeginPlay()
{
	Super::BeginPlay();
	//激活相机
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	if (PlayerController)
	{
		//将相机的锁定权限设置到当前actor上，如果存在相机，则被激活
		PlayerController->SetViewTarget(this);
	}
}

// Called every frame
void ACameraManActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
