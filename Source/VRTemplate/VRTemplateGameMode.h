// Uhh, Writen by Firestack. Please don't remove?

#pragma once

#include "GameFramework/GameMode.h"
#include "VRTemplateGameMode.generated.h"

/**
* This class is used to Spawn the Pawn for a VR Game or Default Game
* The Overridden Functions are the ones needed to spawn a pawn into the world
* at the specified player start
*
* This class provides another variable that can be set to allow for a default VR pawn and
* A function that can be overridden to provide a bool of whether or not to spawn in a VR mode
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

	UPROPERTY(EditAnywhere, noclear, BlueprintReadOnly, AdvancedDisplay, Category = Classes)
		bool UseVR = true;

	UPROPERTY(EditAnywhere, noclear, BlueprintReadOnly, AdvancedDisplay, Category = Classes)
		bool ForceVR = false;

	UPROPERTY(EditAnywhere, noclear, BlueprintReadOnly, AdvancedDisplay, Category = Classes)
		bool DebugVR = false;
};
