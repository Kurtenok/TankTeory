#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
    GENERATED_BODY()

public:
    ATank();

    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
    virtual void Tick(float DeltaTime) override;

    void HandleDestruction();
    APlayerController* GetPlayerController() { return PlayerController; }
    bool bAlive = true;

protected:
    virtual void BeginPlay() override;

private:
    UPROPERTY(VisibleDefaultsOnly, Category = "Components")
    class USpringArmComponent* SpringArm;

    UPROPERTY(VisibleDefaultsOnly, Category = "Components")
    class UCameraComponent* Camera;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = "Movement")
    float MoveSpeed = 400.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = "Movement")
    float RotationSpeed = 100.f;

    void Move(float Value);
    void Turn(float Value);

    UFUNCTION(Server, Reliable, WithValidation)
    void ServerMove(float Value);

    UFUNCTION(Server, Reliable, WithValidation)
    void ServerTurn(float Value);

    UFUNCTION(NetMulticast, Reliable)
    void MulticastMove(const FVector& NewLocation);

    UFUNCTION(NetMulticast, Reliable)
    void MulticastTurn(const FRotator& NewRotation);

    UPROPERTY(ReplicatedUsing = OnRep_CurrentLocation)
    FVector CurrentLocation;

    UPROPERTY(ReplicatedUsing = OnRep_CurrentRotation)
    FRotator CurrentRotation;

    UFUNCTION()
    void OnRep_CurrentLocation();

    UFUNCTION()
    void OnRep_CurrentRotation();

    APlayerController* PlayerController;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
