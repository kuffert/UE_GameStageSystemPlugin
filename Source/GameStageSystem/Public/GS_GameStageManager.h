// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GS_GameStageManager.generated.h"

USTRUCT()
struct GAMESTAGESYSTEM_API FGS_GameStageData {

	GENERATED_BODY()

	float StageLength;
	float TimeRemaining;
	float TimePassed;
};

UCLASS()
class GAMESTAGESYSTEM_API AGS_GameStageManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGS_GameStageManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
