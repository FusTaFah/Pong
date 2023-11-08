// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "InputAction.h"
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ControlMapping.generated.h"

/**
 * 
 */
UCLASS()
class JUSTPONG_API UControlMapping : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditdefaultsOnly, BlueprintReadOnly)
	UInputAction* InputMovePaddle;
};
