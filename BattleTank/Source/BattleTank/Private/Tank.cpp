// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "BattleTank.h"


<<<<<<< HEAD
void ATank::SetBarrelBarrelReference(UTankBarrel * BarrelToSet)
=======
void ATank::SetBarrelReference(UStaticMeshComponent * BarrelToSet)
>>>>>>> c6965868c1ef2b9e2607f9c1c11dd54d6995a53e
{
	TankAimingComponent->SetBarrelReference(BarrelToSet);
}

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
<<<<<<< HEAD
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
=======

	//No need to protect pointer as added at construction
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));

>>>>>>> c6965868c1ef2b9e2607f9c1c11dd54d6995a53e
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

