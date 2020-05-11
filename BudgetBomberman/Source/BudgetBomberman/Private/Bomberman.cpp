// Fill out your copyright notice in the Description page of Project Settings.


#include "Bomberman.h"

// Sets default values
ABomberman::ABomberman()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Controller does not control pawn rotation
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}

// Called when the game starts or when spawned
void ABomberman::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABomberman::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABomberman::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward",this, &ABomberman::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ABomberman::MoveRight);

}

void ABomberman::MoveForward(float Axis)
{
	FRotator Rotation = Controller->GetControlRotation();
	FRotator YawRotation(0.f, Rotation.Yaw, 0.f);
	FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

	SetActorLocation(GetActorLocation() + Direction * Axis * MovementSpeed, true);

	UE_LOG(LogTemp, Warning, TEXT("MoveForward being called! %f"), Axis);
}

void ABomberman::MoveRight(float Axis)
{
	FRotator Rotation = Controller->GetControlRotation();
	FRotator YawRotation(0.f, Rotation.Yaw, 0.f);
	FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	SetActorLocation(GetActorLocation() + Direction * Axis * MovementSpeed, true);

	UE_LOG(LogTemp, Warning, TEXT("MoveRight being called! %f"), Axis);
}