// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "VRTemplateGameMode.generated.h"

/**
 * 
 */
UCLASS()
class VRTEMPLATE_API AVRTemplateGameMode : public AGameMode
{
	GENERATED_BODY()
	


public:
	AVRTemplateGameMode();
	/**
	* Custom VR Implementation
	* @param	NewPlayer - Controller for whom this pawn is spawned
	* @param	StartSpot - PlayerStart at which to spawn pawn
	* @return	a pawn of the default pawn class
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "Game")
	APawn* SpawnDefaultPawnFor(AController* NewPlayer, class AActor* StartSpot);
	virtual APawn* SpawnDefaultPawnFor_Implementation(AController* NewPlayer, class AActor* StartSpot) override;

	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category = "Game")
	bool ShouldUseVR();
	virtual bool ShouldUseVR_Implementation();

	UFUNCTION(BlueprintNativeEvent, Category = "Game")
	UClass* GetDefaultPawnClassForController(AController* InController);
	virtual UClass* GetDefaultPawnClassForController_Implementation(AController* InController);


	UPROPERTY(EditAnywhere, noclear, BlueprintReadOnly, Category = Classes)
		TSubclassOf<class APawn> DefaultVRPawnClass;

	UPROPERTY(EditAnywhere, noclear, BlueprintReadOnly, Category = Classes)
		bool UseVR;
};
