// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawn.h"

#include "Projectile.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Projectile.h"
// Sets default values
ABasePawn::ABasePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>("Capsule Collider");
	RootComponent = CapsuleComp;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("Base Mesh");
	BaseMesh->SetupAttachment(CapsuleComp);

	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>("Turret Mesh");
	TurretMesh->SetupAttachment(BaseMesh);

	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>("Spawn Point");
	ProjectileSpawnPoint->SetupAttachment(TurretMesh);
	
}

void ABasePawn::HandleDestruction()
{
	if(DeathParticles)
	UGameplayStatics::SpawnEmitterAtLocation(this, DeathParticles, GetActorLocation(), GetActorRotation());
	if (DeathSound)
		UGameplayStatics::PlaySoundAtLocation(this, DeathSound, GetActorLocation(), GetActorRotation());
	if (DeathCameraShake)
		GetWorld()->GetFirstPlayerController()->ClientStartCameraShake(DeathCameraShake);
}

void ABasePawn::RotateTurret(FVector LookAtTarget)
{
	FVector ToTarget = LookAtTarget - TurretMesh->GetComponentLocation();
	FRotator LookAtRotation = ToTarget.Rotation();
	LookAtRotation.Roll = 0.f;
	LookAtRotation.Pitch = 0.f;

	float DeltaSeconds = UGameplayStatics::GetWorldDeltaSeconds(this);
	TurretMesh->SetWorldRotation(FMath::RInterpTo(TurretMesh->GetComponentRotation(),LookAtRotation,DeltaSeconds,TurretRotationSpeed*DeltaSeconds));
}

void ABasePawn::Fire()
{
	//DrawDebugSphere(GetWorld(), ProjectileSpawnPoint->GetComponentLocation(), 25.f, 16, FColor::Red, false, 2.f);
	auto Projectile=GetWorld()->SpawnActor<AProjectile>(ProjectileClass, ProjectileSpawnPoint->GetComponentLocation(), ProjectileSpawnPoint->GetComponentRotation());
	Projectile->SetOwner(this);
}


// Called when the game starts or when spawned


// Called every frame


// Called to bind functionality to input


