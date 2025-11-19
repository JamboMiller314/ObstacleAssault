// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	MovePlatform(DeltaTime);
	

}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	FVector Location = GetActorLocation();

	Location = Location + (PlatformVelocity * DeltaTime);
	SetActorLocation(Location);

	DistanceMoved = FVector::Dist(StartLocation, Location);

	if (DistanceMoved > MaxMoveDistance)
	{
		float OverShoot = DistanceMoved - MaxMoveDistance;
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		FVector NewStartLocation = StartLocation + MoveDirection * MaxMoveDistance;
		SetActorLocation(NewStartLocation);
		StartLocation = NewStartLocation;

		PlatformVelocity = -PlatformVelocity;
	}
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	FRotator Rotation = GetActorRotation();

	Rotation = Rotation + (PlatformRotationSpeed * DeltaTime);
	SetActorRotation(Rotation);
}

