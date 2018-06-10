// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
private:
		UPROPERTY(EditAnywhere)
		float CrossHairXLocation = 0.5;
		UPROPERTY(EditAnywhere)
		float CrossHairYLocation = 0.33333;


	
	
	ATank * GetControlledTank() const;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;



	//Start the tank moving the barrel so that a show would hit where
	//the crosshair intersects the world
	void AimTowardsCrosshair();

	//Return an Out parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& HitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const;
	
	
};
