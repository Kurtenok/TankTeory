// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"

//#include ""
ATank::ATank()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("Spring Arm");
	SpringArm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(SpringArm);

}

void ATank::BeginPlay()
{
	Super::BeginPlay();
	PlayerController =Cast<APlayerController>(GetController());
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
	//PlayerInputComponent->BindAxis("RotateTurret", this, &ABasePawn::RotateTurret);

	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &ATank::Fire);
}


void ATank::Move(float Value)
{
	FVector DeltaLocation(0.f);
	DeltaLocation.X = Value;
	AddActorLocalOffset(DeltaLocation * MoveSpeed*UGameplayStatics::GetWorldDeltaSeconds(this),true);
}

void ATank::Turn(float Value)
{
	FRotator DeltaRotation(0.f);
	DeltaRotation.Yaw = Value * RotationSpeed * UGameplayStatics::GetWorldDeltaSeconds(this);
	AddActorLocalRotation(DeltaRotation, true);
}


