// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GS_GameStage.generated.h"

USTRUCT(Blueprintable)
struct GAMESTAGESYSTEM_API FGS_GameStageData {

	GENERATED_BODY()

		float StageLength;
	float TimeRemaining;
	float TimePassed;
};


UCLASS(Abstract, Blueprintable)
class GAMESTAGESYSTEM_API AGS_GameStage : public AActor
{
	GENERATED_BODY()

private:
	float StageLength = 0.f;
	FName StageName = TEXT("");
	
public:	
	// Sets default values for this actor's properties
	AGS_GameStage();

	// Builds a stage data struct from the current stage state.
	FGS_GameStageData GetStageData();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// -- C++ only functionality. Overrideable Blueprint events are called from these. -- //

	// Called after the Stage has been created, but before BeginStage is called.
	virtual void PreBeginStage();
	// Begins the stage. 
	virtual void BeginStage();
	// Ends the stage.
	virtual void EndStage();

	// -- BP overridable events triggered by c++ only functions. -- //
	
	UFUNCTION (BlueprintNativeEvent, Category = "Stage Step")
	void OnPreBeginStage();
	UFUNCTION(BlueprintNativeEvent, Category = "Stage Step")
	void OnBeginStage();
	UFUNCTION(BlueprintNativeEvent, Category = "Stage Step")
	void OnEndStage();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
