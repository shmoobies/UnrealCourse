// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"
#include "BattleTank.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController Possessing: %s"), *(ControlledTank->GetName()));
	}
}


void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	AimTowardsCrosshair();
}


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation = { 0.0, 0.0, 0.0 };  //Out Parameter
	if (GetSightRayHitLocation(HitLocation))//has a side-effect, is goint to line trace
	{
		//Get world location if linetrace through crosshair
		//If it hits the landscape
			//Tell controlled tank to aim at this point
	}
}

//Get world location of linetrace through crosshar, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	/*FHitResult Hit(ForceInit);
	FCollisionQueryParams TraceChannel = FCollisionQueryParams(FName(TEXT("AimTrace")),true, this);
	GetControlledTank()->ActorLineTraceSingle(Hit, GetPawn()->GetActorLocation(), HitLocation, ECC_Pawn, TraceChannel);
	if (Hit.bBlockingHit)
	{
		return true;
	}
	*/

	//Find crosshair position in pixel coordinates
	int32 ViewportX, ViewportY;
	GetViewportSize(ViewportX, ViewportY);
	auto ScreenLocation = FVector2D(ViewportX*CrossHairXLocation, ViewportY*CrossHairYLocation);
	
	//De-project the screen position of the crosshair to a world direction
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *LookDirection.ToString());
	}

	//line-trace along that look direction, and wee what w hit (up to max range)
	HitLocation = FVector(1.0);
	return true;


}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector WLocation; //To be discarded
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WLocation, LookDirection);
}





