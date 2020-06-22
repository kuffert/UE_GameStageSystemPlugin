// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GS_GameStage.h"
#include "Engine/DataTable.h"
#include "GS_GameStageManager.generated.h"

USTRUCT(BlueprintType)
struct GAMESTAGESYSTEM_API FGS_GameStageRow : public FTableRowBase {

	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AGS_GameStage> StageClass;

public:
	FGS_GameStageRow() : StageClass(nullptr) {}
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

	// Gets the active game stage's current data.
	bool GetActiveGameStageData(FGS_GameStageData& ActiveStageData);

	// Initialize this manager after it has been spawned.
	void Initialize(UDataTable* GameStagesTable);

private:
	
	UPROPERTY()
	AGS_GameStage* ActiveGameStage;

};
