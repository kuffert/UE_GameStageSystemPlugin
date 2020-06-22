// Fill out your copyright notice in the Description page of Project Settings.


#include "GS_GameStageManager.h"

// Sets default values
AGS_GameStageManager::AGS_GameStageManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ActiveGameStage = nullptr;

}

// Called when the game starts or when spawned
void AGS_GameStageManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGS_GameStageManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool AGS_GameStageManager::GetActiveGameStageData(FGS_GameStageData& ActiveStageData)
{
	if (ActiveGameStage) {
		ActiveStageData = ActiveGameStage->GetStageData();
		return true;
	}
	else {
		ActiveStageData = FGS_GameStageData();
		return false;
	}
}

