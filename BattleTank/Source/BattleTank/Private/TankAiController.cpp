// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAiController.h"

void ATankAiController::BeginPlay() {
	Super::BeginPlay();

	if (GetPlayerTank()) {
		UE_LOG(LogTemp, Warning, TEXT("TankAI %s found: %s"), *(GetControlledTank()->GetName()), *(GetPlayerTank()->GetName()));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("TankAI Possesses: NO TANK"));
	}

}

ATank* ATankAiController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

ATank* ATankAiController::GetPlayerTank() const {
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!PlayerPawn) {
		return nullptr;
	}
	
	return Cast<ATank>(PlayerPawn);
}


