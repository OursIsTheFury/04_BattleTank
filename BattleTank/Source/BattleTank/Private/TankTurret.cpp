// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "BattleTank.h"
#include "Engine/World.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	// Move the Turret the right amount this frame
	// Given a max rotation speed, and the frame time
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.0f, 1.0f);
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto Rotation = RelativeRotation.Yaw + RotationChange;
	SetRelativeRotation(FRotator(0.0f, Rotation, 0.0f));
}