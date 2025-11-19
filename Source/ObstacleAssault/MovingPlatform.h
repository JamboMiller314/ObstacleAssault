// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

	UPROPERTY(EditAnywhere)
	FVector MyVector = FVector(1100.0f, -610.0f, 440.0f);

	UPROPERTY(EditAnywhere)
	FVector PlatformVelocity = FVector(0.f,0.f,0.f);
	
	UPROPERTY(EditAnywhere)
	float MaxMoveDistance = 100.f;

	UPROPERTY(VisibleAnywhere)
	float DistanceMoved = 0.0f;

	FVector StartLocation;
	
	UPROPERTY(EditAnywhere)
	FRotator PlatformRotationSpeed = FRotator(0.f,0.f,0.f);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void MovePlatform(float DeltaTime);
	void RotatePlatform(float DeltaTime);

};
