#include "Tower.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

void ATower::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    ATank* ClosestTank = GetClosestTank();
    if (ClosestTank && InFireRange(ClosestTank))
    {
        RotateTurret(ClosestTank->GetActorLocation());
    }
}

void ATower::HandleDestruction()
{
    Super::HandleDestruction();
    Destroy();
}

void ATower::BeginPlay()
{
    Super::BeginPlay();

    GetWorldTimerManager().SetTimer(FireRateTimerHandle, this, &ATower::CheckFireCondition, FireRate, true);
}

void ATower::CheckFireCondition()
{
    ATank* ClosestTank = GetClosestTank();
    if (ClosestTank && InFireRange(ClosestTank) && ClosestTank->bAlive)
    {
        Fire();
    }
}

bool ATower::InFireRange(ATank* TargetTank)
{
    if (TargetTank)
    {
        if (FVector::Dist(GetActorLocation(), TargetTank->GetActorLocation()) < AttackRange)
            return true;
    }
    return false;
}

ATank* ATower::GetClosestTank()
{
    TArray<AActor*> Tanks;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATank::StaticClass(), Tanks);

    ATank* ClosestTank = nullptr;
    float MinDistance = FLT_MAX;

    for (AActor* TankActor : Tanks)
    {
        ATank* Tank = Cast<ATank>(TankActor);
        if (Tank && Tank->bAlive)
        {
            float Distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());
            if (Distance < MinDistance)
            {
                MinDistance = Distance;
                ClosestTank = Tank;
            }
        }
    }

    return ClosestTank;
}
