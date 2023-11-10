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
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation();
	if (MoveForward) {
		CurrentLocation.X += 1;
	}
	else {
		CurrentLocation.X -= 1;
	}

	if (CurrentLocation.X < StartLocation.X) {
		MoveForward = true;
	}
	if (CurrentLocation.X > StartLocation.X + MaxDistance) {
		MoveForward = false;
	}

	SetActorLocation(CurrentLocation);
}

