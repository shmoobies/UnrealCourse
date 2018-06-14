// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "BattleTank.h"




void UTankTurret::Rotate(float RelativeSpeed)
{

	auto RotationChange = FMath::Clamp<float>(RelativeSpeed, -1, 1) * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation = RelativeRotation.Yaw + RotationChange;

	SetRelativeRotation(FRotator( 0, RawNewRotation, 0));

	UE_LOG(LogTemp, Warning, TEXT("Turret Rotate Called"));

}