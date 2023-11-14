// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "ControllablePaddle.generated.h"
UCLASS()
class JUSTPONG_API AControllablePaddle : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AControllablePaddle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enhanced Input")
	class UInputMappingContext* InputMapping;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enhanced Input")
	class UControlMapping* InputActions;
	UPROPERTY(EditDefaultsOnly)
	float MoveSpeed;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MovePaddle(const FInputActionValue& value);
};

