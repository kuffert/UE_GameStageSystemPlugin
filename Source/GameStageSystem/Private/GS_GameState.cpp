// Fill out your copyright notice in the Description page of Project Settings.


#include "GS_GameState.h"
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