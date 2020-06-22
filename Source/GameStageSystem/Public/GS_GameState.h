// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "GS_GameStageInterface.h"
#include "GS_GameStageManager.h"
#include "Engine/DataTable.h"
#include "GS_GameState.generated.h"

/**
 * 
 */
UCLASS()
class GAMESTAGESYSTEM_API AGS_GameState : public AGameStateBase, public IGS_GameStageInterface
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;



	// Data table of Game States
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Game Stage System")
	UDataTable* GameStagesTable;

	// Gets the active game stage's current state, if there is one.
	bool GetActiveGameStageData_Implementation(FGS_GameStageData& ActiveStageData) override;
	
private:
	AGS_GameStageManager* GameStageManager;

};
