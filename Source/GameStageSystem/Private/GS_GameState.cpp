// Fill out your copyright notice in the Description page of Project Settings.


#include "GS_GameState.h"
#include "CoreMinimal.h"
#include "GS_GameStageManager.h"
#include "GS_GameStage.h"

bool AGS_GameState::GetActiveGameStageData_Implementation(FGS_GameStageData& ActiveStageData) {
	if (GameStageManager) {
		return GameStageManager->GetActiveGameStageData(ActiveStageData);
	}
	else {
		ActiveStageData = FGS_GameStageData();
		return false;
	}
}

// Called when the game starts or when spawned
void AGS_GameState::BeginPlay()
{
	Super::BeginPlay();

	GameStageManager = GetWorld()->SpawnActor<AGS_GameStageManager>();
	if (GameStageManager) {
		GameStageManager->Initialize(GameStagesTable);
	}
}