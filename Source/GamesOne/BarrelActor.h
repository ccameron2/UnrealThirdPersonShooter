// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BarrelActor.generated.h"

class URadialForceComponent;

UCLASS()
class GAMESONE_API ABarrelActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABarrelActor();

	void Explode();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* BarrelMesh;
	UPROPERTY(EditAnywhere)
		URadialForceComponent* ForceComp;
	UPROPERTY(EditAnywhere)
		float ForceAmount = 990.0f;
	UPROPERTY(EditAnywhere)
		float TorqueAmount = 10.0f;


};
