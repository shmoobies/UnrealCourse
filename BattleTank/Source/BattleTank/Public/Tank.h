// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
<<<<<<< HEAD

=======
>>>>>>> c6965868c1ef2b9e2607f9c1c11dd54d6995a53e
#include "TankAimingComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);
	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetBarrelBarrelReference(UTankBarrel* BarrelToSet);

protected:
	UTankAimingComponent* TankAimingComponent = nullptr;

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UStaticMeshComponent* BarrelToSet);

protected:
	UTankAimingComponent * TankAimingComponent = nullptr;

private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = Firing)
<<<<<<< HEAD
		float LaunchSpeed = 100000.0; //TODO find sensible default
=======
		float LaunchSpeed = 100000; //TODO find sensible default
>>>>>>> c6965868c1ef2b9e2607f9c1c11dd54d6995a53e

	
	
};
