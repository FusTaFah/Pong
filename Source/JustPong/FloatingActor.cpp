// Fill out your copyright notice in the Description page of Project Settings.


#include "FloatingActor.h"
#include "JustPong.h"

// Sets default values
AFloatingActor::AFloatingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	USceneComponent* ExistingRootComponent = GetRootComponent();
	if (!ExistingRootComponent) {
		VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
		VisualMesh->SetupAttachment(RootComponent);

		static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));

		if (CubeVisualAsset.Succeeded()) {
			
			VisualMesh->SetStaticMesh(CubeVisualAsset.Object);
			VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		}
	}
}

// Called when the game starts or when spawned
void AFloatingActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFloatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector new_location = GetActorLocation();
	FRotator new_rotation = GetActorRotation();
	float running_time = GetGameTimeSinceCreation();
	float delta_height = (FMath::Sin(running_time + DeltaTime) - FMath::Sin(running_time));
	new_location.Z += delta_height * 20.0f;
	float delta_rotation = DeltaTime * 20.0f;
	new_rotation.Yaw += delta_rotation;
	SetActorLocationAndRotation(new_location, new_rotation);
}

