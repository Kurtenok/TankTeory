#include "Tank.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Net/UnrealNetwork.h"

ATank::ATank()
{
    SpringArm = CreateDefaultSubobject<USpringArmComponent>("Spring Arm");
    SpringArm->SetupAttachment(RootComponent);

    Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
    Camera->SetupAttachment(SpringArm);

    bReplicates = true;
    SetReplicatingMovement(true);
}

void ATank::BeginPlay()
{
    Super::BeginPlay();
    PlayerController = Cast<APlayerController>(GetController());
}

void ATank::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (PlayerController)
    {
        FHitResult HitResult;
        PlayerController->GetHitResultUnderCursor(ECC_Visibility, false, HitResult);
        DrawDebugSphere(GetWorld(), HitResult.ImpactPoint, 25.f, 16, FColor::Blue, false, -1.f);
        RotateTurret(HitResult.ImpactPoint);
    }
}

void ATank::HandleDestruction()
{
    Super::HandleDestruction();
    SetActorHiddenInGame(true);
    SetActorTickEnabled(false);
    bAlive = false;
}

void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis("MoveForward", this, &ATank::Move);
    PlayerInputComponent->BindAxis("Turn", this, &ATank::Turn);
    PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &ATank::Fire);
}

void ATank::Move(float Value)
{
    if (HasAuthority())
    {
        FVector DeltaLocation(0.f);
        DeltaLocation.X = Value;
        AddActorLocalOffset(DeltaLocation * MoveSpeed * UGameplayStatics::GetWorldDeltaSeconds(this), true);
        CurrentLocation = GetActorLocation();
    }
    else
    {
        ServerMove(Value);
    }
}

void ATank::Turn(float Value)
{
    if (HasAuthority())
    {
        FRotator DeltaRotation(0.f);
        DeltaRotation.Yaw = Value * RotationSpeed * UGameplayStatics::GetWorldDeltaSeconds(this);
        AddActorLocalRotation(DeltaRotation, true);
        CurrentRotation = GetActorRotation();
    }
    else
    {
        ServerTurn(Value);
    }
}

void ATank::ServerMove_Implementation(float Value)
{
    Move(Value);
    MulticastMove(CurrentLocation); // Добавляем вызов мультикаст-функции
}

bool ATank::ServerMove_Validate(float Value)
{
    return true;
}

void ATank::ServerTurn_Implementation(float Value)
{
    Turn(Value);
    MulticastTurn(CurrentRotation); // Добавляем вызов мультикаст-функции
}

bool ATank::ServerTurn_Validate(float Value)
{
    return true;
}

void ATank::MulticastMove_Implementation(const FVector& NewLocation)
{
    if (!HasAuthority())
    {
        SetActorLocation(NewLocation);
    }
}

void ATank::MulticastTurn_Implementation(const FRotator& NewRotation)
{
    if (!HasAuthority())
    {
        SetActorRotation(NewRotation);
    }
}

void ATank::OnRep_CurrentLocation()
{
    SetActorLocation(CurrentLocation);
}

void ATank::OnRep_CurrentRotation()
{
    SetActorRotation(CurrentRotation);
}

void ATank::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(ATank, CurrentLocation);
    DOREPLIFETIME(ATank, CurrentRotation);
}
