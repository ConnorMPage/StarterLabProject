// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TeaPawn.generated.h"

UCLASS()
class STARTERLABPROJECT_API ATeaPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATeaPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
private:
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* TeaPawnMesh;
	void SetMoveAmount(float Value);
	void SetRotateAmount(float Value);
	void SetStrafeAmount(float Value);
	FVector DeltaLocation;
	FQuat DeltaRotation;
	float MoveSpeed = 100.0f;
	float RotationSpeed = 50.0f;

};
