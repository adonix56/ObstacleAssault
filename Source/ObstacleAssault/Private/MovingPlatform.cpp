// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MoveForward = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	//SetActorLocation(MyVector);
	UE_LOG(LogTemp, Warning, TEXT("Okay We Got IT"));
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation();
	float MoveDistance = FVector::DistSquared(StartLocation, CurrentLocation);
	CurrentLocation += PlatformVelocity * DeltaTime * ((MoveForward) ? 1 : -1);

	if (MoveDistance > MaxDistance * MaxDistance) {
		UE_LOG(LogTemp, Warning, TEXT("Okay We Got IT"));
		StartLocation += PlatformVelocity.GetSafeNormal() * MaxDistance * ((MoveForward) ? 1 : -1);
		MoveForward = !MoveForward;
	}

	SetActorLocation(CurrentLocation);
}

