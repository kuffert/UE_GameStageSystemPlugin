// Fill out your copyright notice in the Description page of Project Settings.


#include "GS_GameStage.h"

// Sets default values
AGS_GameStage::AGS_GameStage()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGS_GameStage::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGS_GameStage::PreBeginStage()
{
	OnPreBeginStage();
}

void AGS_GameStage::BeginStage()
{
	OnBeginStage();
}

void AGS_GameStage::EndStage()
{
	OnEndStage();
}

void AGS_GameStage::OnPreBeginStage_Implementation()
{
}

void AGS_GameStage::OnBeginStage_Implementation()
{
}

void AGS_GameStage::OnEndStage_Implementation()
{
}

// Called every frame
void AGS_GameStage::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

