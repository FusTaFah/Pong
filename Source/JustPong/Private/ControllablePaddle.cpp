// Fill out your copyright notice in the Description page of Project Settings.


#include "ControllablePaddle.h"
#include "EnhancedInputSubsystems.h"
#include "ControlMapping.h"
#include "EnhancedInputComponent.h"
#include "JustPong/JustPong.h"

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
void AControllablePaddle::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	APlayerController* PC = Cast<APlayerController>(GetController());

	UEnhancedInputLocalPlayerSubsystem* enhanced_inp_subsys = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer());

	enhanced_inp_subsys->ClearAllMappings();
	enhanced_inp_subsys->AddMappingContext(InputMapping, 0);

	UEnhancedInputComponent* enhanced_input = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	enhanced_input->BindAction(InputActions->InputMovePaddle, ETriggerEvent::Triggered, this, &AControllablePaddle::MovePaddle);
	LogTextInfo("I am moving!");

}

void AControllablePaddle::MovePaddle(const FInputActionValue& value) {
	const float move_value = value.Get<float>();
	FVector3d currentPos = GetActorLocation();
	FVector movement_direction(move_value, 0.0f, 0.0f);
	AddMovementInput(movement_direction, 20.0f);
	

}