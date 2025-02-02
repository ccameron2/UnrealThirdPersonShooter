// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Explosion.h"

#include "Kismet/GameplayStatics.h"
#include "PhysicsEngine/RadialForceComponent.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LandmineActor.generated.h"

UCLASS()
class GAMESONE_API ALandmineActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALandmineActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* LandmineMesh;

	UFUNCTION()
		void OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);

	UPROPERTY(EditAnywhere)
		float DamageAmount = 33.0f;

	UPROPERTY(EditAnywhere)
		URadialForceComponent* ForceComp;
	UPROPERTY(EditAnywhere)
		TSubclassOf<AExplosion> ExplosionClass;
	UPROPERTY(EditAnywhere)
		USoundBase* ExplosionSound;

};
