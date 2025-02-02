// Fill out your copyright notice in the Description page of Project Settings.


#include "Explosion.h"

// Sets default values
AExplosion::AExplosion()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create Particle System Component set as root component.
	Explosion = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Explosion Particle Component"));
	SetRootComponent(Explosion);
	Explosion->Activate();
}

// Called when the game starts or when spawned
void AExplosion::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AExplosion::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

