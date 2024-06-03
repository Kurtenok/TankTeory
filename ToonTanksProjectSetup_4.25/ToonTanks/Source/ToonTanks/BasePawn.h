#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
    GENERATED_BODY()

public:
    ABasePawn();

    void HandleDestruction();

protected:
    void RotateTurret(FVector LookAtTarget);

    UPROPERTY(EditAnywhere, Category = "Movement")
    float TurretRotationSpeed = 200.f;

    void Fire();

private:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
    class UCapsuleComponent* CapsuleComp;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
    UStaticMeshComponent* BaseMesh;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
    UStaticMeshComponent* TurretMesh;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
    USceneComponent* ProjectileSpawnPoint;

    UPROPERTY(EditDefaultsOnly, Category = "Combat")
    TSubclassOf<class AProjectile> ProjectileClass;

    UPROPERTY(EditAnywhere)
    UParticleSystem* DeathParticles;

    UPROPERTY(EditAnywhere, Category = "Combat")
    USoundBase* DeathSound;

    UPROPERTY(EditAnywhere, Category = "Combat")
    TSubclassOf<UCameraShakeBase> DeathCameraShake;

    UFUNCTION(Server, Reliable, WithValidation)
    void ServerFire();

    UFUNCTION(NetMulticast, Reliable)
    void MulticastFire();

    void SpawnProjectile();

    UFUNCTION(Server, Reliable, WithValidation)
    void ServerRotateTurret(FVector LookAtTarget);

    UFUNCTION(NetMulticast, Reliable)
    void MulticastRotateTurret(FRotator TurretRotation);

    UFUNCTION(NetMulticast, Reliable)
    void MulticastHandleDestruction();

public:
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
