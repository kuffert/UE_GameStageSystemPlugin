// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GS_GameStage.generated.h"

USTRUCT(Blueprintable)
struct GAMESTAGESYSTEM_API FGS_GameStageData {

	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	float StageLength = 0.f;
	UPROPERTY(BlueprintReadOnly)
	float TimeRemaining = 0.f;
	UPROPERTY(BlueprintReadOnly)
	float TimePassed = 0.f;

	FGS_GameStageData() {}

	FGS_GameStageData(float stageLength) {
		StageLength = stageLength;
		TimeRemaining = stageLength;
		TimePassed = 0.f;
	}
};


UCLASS(Abstract, Blueprintable)
class GAMESTAGESYSTEM_API AGS_GameStage : public AActor
{
	GENERATED_BODY()

private:

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Stage Properties", meta = (AllowPrivateAccess = "true"))
	float StageLength = 0.f;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Stage Properties", meta = (AllowPrivateAccess = "true"))
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
