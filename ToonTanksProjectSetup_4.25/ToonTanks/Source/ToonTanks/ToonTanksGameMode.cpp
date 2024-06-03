#include "ToonTanksGameMode.h"
#include "Tank.h"
#include "ToonTanksPlayerController.h"
#include "Tower.h"
#include "Kismet/GameplayStatics.h"

void AToonTanksGameMode::ActorDied(AActor* DeadActor)
{
    if (Tanks.Contains(DeadActor))
    {
        UE_LOG(LogTemp, Warning, TEXT("Destroy Tank"));

        ATank* DestroyedTank = Cast<ATank>(DeadActor);
        if (DestroyedTank)
        {
            DestroyedTank->HandleDestruction();
        }

        for (FConstPlayerControllerIterator Iterator = GetWorld()->GetPlayerControllerIterator(); Iterator; ++Iterator)
        {
            AToonTanksPlayerController* Controller = Cast<AToonTanksPlayerController>(*Iterator);
            if (Controller && Controller->GetPawn() == DeadActor)
            {
                Controller->SetPlayerEnabledState(false);
                break;
            }
        }

        GameOver(false);
    }
    else if (ATower* DestroyedTower = Cast<ATower>(DeadActor))
    {
        if (DestroyedTower)
        {
            DestroyedTower->HandleDestruction();
        }

        TargetTowers--;
        if (TargetTowers <= 0)
        {
            GameOver(true);
        }
    }
}

void AToonTanksGameMode::BeginPlay()
{
    Super::BeginPlay();
    HandleGameStart();
}

void AToonTanksGameMode::HandleGameStart()
{
    
    GetWorldTimerManager().SetTimer(FindTanksTimerHandle,this,&AToonTanksGameMode::FindAllTanksInScene, 2.f,false);

    ToonTanksPlayerController = Cast<AToonTanksPlayerController>(UGameplayStatics::GetPlayerController(this, 0));

    TargetTowers = GetTargetTowerCount();
    if (TargetTowers <= 0)
    {
        GameOver(true);
    }

    StartGame();

    if (ToonTanksPlayerController)
    {
        ToonTanksPlayerController->SetPlayerEnabledState(false);

        FTimerHandle PlayerEnableTimerHandle;

        FTimerDelegate Delegate = FTimerDelegate::CreateUObject(ToonTanksPlayerController, &AToonTanksPlayerController::SetPlayerEnabledState, true);

        GetWorldTimerManager().SetTimer(PlayerEnableTimerHandle, Delegate, StartDelay, false);
    }
}

int32 AToonTanksGameMode::GetTargetTowerCount()
{
    TArray<AActor*> Towers;
    UGameplayStatics::GetAllActorsOfClass(this, ATower::StaticClass(), Towers);
    return Towers.Num();
}
void AToonTanksGameMode::FindAllTanksInScene()
{
    UGameplayStatics::GetAllActorsOfClass(this, ATank::StaticClass(), Tanks);

    // Логирование количества танков для отладки
    UE_LOG(LogTemp, Warning, TEXT("Handle game start"));
    UE_LOG(LogTemp, Warning, TEXT("Tanks Count: %d"), Tanks.Num());
}
//