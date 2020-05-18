// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "ArenaLevel.generated.h"

class ABreakableBlocks;

UCLASS()
class BUDGETBOMBERMAN_API AArenaLevel : public ALevelScriptActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Properties")
	float SpawnChance = 75.f;

	// Block spawning
	UPROPERTY(EditDefaultsOnly, Category = "Spawning")
	TSubclassOf<ABreakableBlocks> BreakableBlock;

	void GenerateMap() const;
	
private:
	void SpawnBreakableBlocks(int Row, int Column) const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
