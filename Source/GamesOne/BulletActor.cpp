// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletActor.h"

#include "PlayableCharacter.h"

// Sets default values
ABulletActor::ABulletActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//Create bullet mesh and set as root component
	BulletMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Bullet Mesh"));
	SetRootComponent(BulletMesh);
	BulletMesh->SetSimulatePhysics(true);

	//Create projectile movement component and set speeds to editor exposed value.
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement Component"));
	ProjectileMovement->MaxSpeed = MovementSpeed;
	ProjectileMovement->InitialSpeed = MovementSpeed;
	//Set lifespan of projectile
	InitialLifeSpan = 5.0f;

}

