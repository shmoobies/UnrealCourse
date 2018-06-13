// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Kismet/GameplayStatics.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

<<<<<<< HEAD
//forward declaration
class UTankBarrel; 

//Holds Barrel's properties and elevate methods
=======

>>>>>>> c6965868c1ef2b9e2607f9c1c11dd54d6995a53e
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

<<<<<<< HEAD
	void SetBarrelReference(UTankBarrel* BarrelToSet);
	//TODO SetTurretReference
=======
	void SetBarrelReference(UStaticMeshComponent* BarrelToSet);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
>>>>>>> c6965868c1ef2b9e2607f9c1c11dd54d6995a53e

	void AimAt(FVector HitLocation, float LaunchSpead);

private:

<<<<<<< HEAD
	UTankBarrel* Barrel = nullptr;

	void MoveBarrelTowards(FVector AimDirection);
=======
	UStaticMeshComponent * Barrel = nullptr;
>>>>>>> c6965868c1ef2b9e2607f9c1c11dd54d6995a53e
	
};
