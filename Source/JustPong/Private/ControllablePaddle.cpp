// Fill out your copyright notice in the Description page of Project Settings.


#include "ControllablePaddle.h"
#include "EnhancedInputSubsystems.h"

// Sets default values
AControllablePaddle::AControllablePaddle()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AControllablePaddle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AControllablePaddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AControllablePaddle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	APlayerController* PC = Cast<APlayerController>(GetController());

	UEnhancedInputLocalPlayerSubsystem* enhanced_inp_subsys = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer());

	enhanced_inp_subsys->ClearAllMappings();
	enhanced_inp_subsys->AddMappingContext(InputMapping, 0);
}

