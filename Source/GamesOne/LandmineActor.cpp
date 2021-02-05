// Fill out your copyright notice in the Description page of Project Settings.

#include "LandmineActor.h"

#include "PlayableCharacter.h"

// Sets default values
ALandmineActor::ALandmineActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	LandmineMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Landmine Mesh"));
	LandmineMesh->SetNotifyRigidBodyCollision(true);



}

// Called when the game starts or when spawned
void ALandmineActor::BeginPlay()
{
	Super::BeginPlay();
	OnActorHit.AddDynamic(this, &ALandmineActor::OnHit);
	
}

// Called every frame
void ALandmineActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALandmineActor::OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("OnHit"));
	if (OtherActor->GetClass()->IsChildOf(APlayableCharacter::StaticClass()))
	{
		AActor* ProjectileOwner = GetOwner();
		UGameplayStatics::ApplyDamage(OtherActor, DamageAmount, ProjectileOwner->GetInstigatorController(), this, UDamageType::StaticClass());
		SelfActor->Destroy();
	}
}

