// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "BattleTank.h"



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIPlayerController not possessing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIPlayerController Possessing: %s"), *(ControlledTank->GetName()));
	}

	auto FirstPlayerTank = GetPlayerTank();
	if (!FirstPlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT(" AI can't locate first player tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI %s found first player tank: %s"), *(ControlledTank->GetName()),*(FirstPlayerTank->GetName()));
	}
}


ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerTank) { return nullptr; }
	return Cast<ATank>(PlayerTank);
}



