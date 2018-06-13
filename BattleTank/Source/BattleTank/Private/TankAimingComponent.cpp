// Fill out your copyright notice in the Description page of Project Settings.

<<<<<<< HEAD

#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "BattleTank.h"
=======
#include "TankAimingComponent.h"
>>>>>>> c6965868c1ef2b9e2607f9c1c11dd54d6995a53e


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


<<<<<<< HEAD
void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
=======
void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent * BarrelToSet)
>>>>>>> c6965868c1ef2b9e2607f9c1c11dd54d6995a53e
{
	Barrel = BarrelToSet;
}

<<<<<<< HEAD
=======
// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

}

>>>>>>> c6965868c1ef2b9e2607f9c1c11dd54d6995a53e
void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel) { return; }

	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
<<<<<<< HEAD
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		ESuggestProjVelocityTraceOption::DoNotTrace

	);
	if(bHaveAimSolution)
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		
		MoveBarrelTowards(AimDirection);
	}
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection) 
{
	//Work-out difference btween current barrel rotation, and AimDirection
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;

	Barrel->Elevate(5); //TODO Remove magic number
}

=======

	//Calculate the OutLaunchVelocity
	if (UGameplayStatics::SuggestProjectileVelocity(
			this,
			OutLaunchVelocity,
			StartLocation,
			HitLocation,
			LaunchSpeed,
			false,
			0.0,
			0.0,
			ESuggestProjVelocityTraceOption::DoNotTrace
			
		)
	)
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		auto TankName = GetOwner()->GetName();
		UE_LOG(LogTemp, Warning, TEXT("%s Aiming At %s"), *TankName,*AimDirection.ToString());
	}
}

>>>>>>> c6965868c1ef2b9e2607f9c1c11dd54d6995a53e
