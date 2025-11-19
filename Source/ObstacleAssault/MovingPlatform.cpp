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
	RotatePlatform(DeltaTime);

}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	

	DistanceMoved = GetDistanceMoved();

	if (DistanceMoved > MaxMoveDistance)
	{
		float OverShoot = DistanceMoved - MaxMoveDistance;
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		FVector NewStartLocation = StartLocation + MoveDirection * MaxMoveDistance;
		SetActorLocation(NewStartLocation);
		StartLocation = NewStartLocation;

		PlatformVelocity = -PlatformVelocity;
	}
	else
	{
		FVector Location = GetActorLocation();

		Location = Location + (PlatformVelocity * DeltaTime);
		SetActorLocation(Location);
	}
	

}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	FRotator RotationToAdd = RotationVelocity * DeltaTime;
	AddActorLocalRotation(RotationToAdd);

	
}

float AMovingPlatform::GetDistanceMoved()
{
	DistanceMoved = FVector::Dist(StartLocation, GetActorLocation());
	return DistanceMoved;
}

