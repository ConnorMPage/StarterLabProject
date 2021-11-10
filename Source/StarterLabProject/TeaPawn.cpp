// Fill out your copyright notice in the Description page of Project Settings.


#include "TeaPawn.h"

// Sets default values
ATeaPawn::ATeaPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TeaPawnMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Tea Pawn Mesh"));
	SetRootComponent(TeaPawnMesh);
}

// Called when the game starts or when spawned
void ATeaPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATeaPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddActorLocalOffset(DeltaLocation);
	AddActorLocalRotation(DeltaRotation);
}

// Called to bind functionality to input
void ATeaPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("Drive", this, &ATeaPawn::SetMoveAmount);
	PlayerInputComponent->BindAxis("Turn", this, &ATeaPawn::SetRotateAmount);
	PlayerInputComponent->BindAxis("Strafe", this, &ATeaPawn::SetStrafeAmount);


}
void ATeaPawn::SetMoveAmount(float Value)
{
	DeltaLocation = FVector(Value * MoveSpeed * GetWorld()->DeltaTimeSeconds, 0.0f, 0.0f);
}
void ATeaPawn::SetRotateAmount(float Value)
{
	float RotateAmount = Value * RotationSpeed * GetWorld()->DeltaTimeSeconds;
	FRotator Rotation = FRotator(0.0f, RotateAmount, 0.0f);
	DeltaRotation = FQuat(Rotation);

}
void ATeaPawn::SetStrafeAmount(float Value)
{
	DeltaLocation += FVector(0.0f, Value * MoveSpeed * GetWorld()->DeltaTimeSeconds, 0.0f);
}

