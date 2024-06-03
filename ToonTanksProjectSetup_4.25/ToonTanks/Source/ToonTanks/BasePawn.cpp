#include "BasePawn.h"
#include "Projectile.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Net/UnrealNetwork.h"

// Sets default values
ABasePawn::ABasePawn()
{
    PrimaryActorTick.bCanEverTick = true;

    CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>("Capsule Collider");
    RootComponent = CapsuleComp;

    BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("Base Mesh");
    BaseMesh->SetupAttachment(CapsuleComp);

    TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>("Turret Mesh");
    TurretMesh->SetupAttachment(BaseMesh);

    ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>("Spawn Point");
    ProjectileSpawnPoint->SetupAttachment(TurretMesh);

    bReplicates = true;
}

void ABasePawn::HandleDestruction()
{
    if (HasAuthority())
    {
        MulticastHandleDestruction();
    }
}

void ABasePawn::MulticastHandleDestruction_Implementation()
{
    if (DeathParticles)
        UGameplayStatics::SpawnEmitterAtLocation(this, DeathParticles, GetActorLocation(), GetActorRotation());
    if (DeathSound)
        UGameplayStatics::PlaySoundAtLocation(this, DeathSound, GetActorLocation(), GetActorRotation());
    if (DeathCameraShake)
        GetWorld()->GetFirstPlayerController()->ClientStartCameraShake(DeathCameraShake);
}

void ABasePawn::RotateTurret(FVector LookAtTarget)
{
    if (HasAuthority())
    {
        FVector ToTarget = LookAtTarget - TurretMesh->GetComponentLocation();
        FRotator LookAtRotation = ToTarget.Rotation();
        LookAtRotation.Roll = 0.f;
        LookAtRotation.Pitch = 0.f;

        float DeltaSeconds = UGameplayStatics::GetWorldDeltaSeconds(this);
        TurretMesh->SetWorldRotation(FMath::RInterpTo(TurretMesh->GetComponentRotation(), LookAtRotation, DeltaSeconds, TurretRotationSpeed * DeltaSeconds));

        MulticastRotateTurret(TurretMesh->GetComponentRotation());
    }
    else
    {
        ServerRotateTurret(LookAtTarget);
    }
}

void ABasePawn::ServerRotateTurret_Implementation(FVector LookAtTarget)
{
    RotateTurret(LookAtTarget);
}

bool ABasePawn::ServerRotateTurret_Validate(FVector LookAtTarget)
{
    return true;
}

void ABasePawn::MulticastRotateTurret_Implementation(FRotator TurretRotation)
{
    if (!HasAuthority())
    {
        TurretMesh->SetWorldRotation(TurretRotation);
    }
}

void ABasePawn::Fire()
{
    if (HasAuthority())
    {
        SpawnProjectile();
    }
    else
    {
        ServerFire();
    }
}

void ABasePawn::ServerFire_Implementation()
{
    Fire();
}

bool ABasePawn::ServerFire_Validate()
{
    return true;
}

void ABasePawn::MulticastFire_Implementation()
{
    SpawnProjectile();
}

void ABasePawn::SpawnProjectile()
{
    if (ProjectileClass)
    {
        FVector SpawnLocation = ProjectileSpawnPoint->GetComponentLocation();
        FRotator SpawnRotation = ProjectileSpawnPoint->GetComponentRotation();

        FActorSpawnParameters SpawnParams;
        SpawnParams.Owner = this;
        SpawnParams.Instigator = GetInstigator();
        SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

        AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, SpawnParams);
        if (Projectile)
        {
            Projectile->SetOwner(this);
        }
    }
}

void ABasePawn::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}
