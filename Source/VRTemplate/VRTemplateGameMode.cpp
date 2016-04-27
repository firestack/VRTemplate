// Fill out your copyright notice in the Description page of Project Settings.

#include "VRTemplate.h"
#include "VRTemplateGameMode.h"

#include "VRPawn.h"


AVRTemplateGameMode::AVRTemplateGameMode() {
	DefaultVRPawnClass = AVRPawn::StaticClass();
}

APawn* AVRTemplateGameMode::SpawnDefaultPawnFor_Implementation(AController* NewPlayer, AActor* StartSpot)
{
	// Select Correct Spawn Position based on VR mode
	FVector StartLocation = StartSpot->GetActorLocation();
	if (ShouldUseVR()) {

		StartLocation.Z -= StartSpot->GetRootComponent()->Bounds.BoxExtent.Z;
	}

	// don't allow pawn to be spawned with any pitch or roll
	FRotator StartRotation(ForceInit);
	StartRotation.Yaw = StartSpot->GetActorRotation().Yaw;

	FActorSpawnParameters SpawnInfo;
	SpawnInfo.Instigator = Instigator;
	SpawnInfo.ObjectFlags |= RF_Transient;	// We never want to save default player pawns into a map
	UClass* PawnClass = GetDefaultPawnClassForController(NewPlayer);
	APawn* ResultPawn = GetWorld()->SpawnActor<APawn>(PawnClass, StartLocation, StartRotation, SpawnInfo);
	if (ResultPawn == NULL)
	{
		//UE_LOG(LogGameMode, Warning, TEXT("Couldn't spawn Pawn of type %s at %s"), *GetNameSafe(PawnClass), *StartSpot->GetName()); 
	}
	return ResultPawn;
}

bool AVRTemplateGameMode::ShouldUseVR_Implementation()
{
	return UHeadMountedDisplayFunctionLibrary::IsHeadMountedDisplayEnabled() && UseVR;
}

UClass * AVRTemplateGameMode::GetDefaultPawnClassForController_Implementation(AController * InController)
{
	return (ShouldUseVR() ? DefaultVRPawnClass : DefaultPawnClass);
}

