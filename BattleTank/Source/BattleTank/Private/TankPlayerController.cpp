// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();

	if (GetControlledTank()) {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController Possesses: %s"), *GetControlledTank()->GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController Does not possess a tank"));
	}
}

void ATankPlayerController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair(){
	if (!GetControlledTank()) {
		return;
	}

	// Get world location if linetrace through crosshair
	// If it hits the landscape
		// Tell the controlled tank to aim at this point
}
