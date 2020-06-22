// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GS_GameStageInterface.generated.h"

struct FGS_GameStageData;

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UGS_GameStageInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface to be implemented by a Game State that uses the Game Stage system. 
 */
class GAMESTAGESYSTEM_API IGS_GameStageInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	bool GetActiveGameStageData(FGS_GameStageData& ActiveStageData);

};
