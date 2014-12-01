// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Squad/Unit.h"
#include "GameFramework/Pawn.h"
#include "Squad.generated.h"


/**
 * 
 */
UCLASS()
class PROJECTSKY_API ASquad : public APawn
{
	GENERATED_UCLASS_BODY()

// fields

private:

	int m_minUnitNum = 1;
	int m_maxUnitNum = 6;

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AdvancedDisplay, Category = "Squad")
	TArray<AUnit*> m_unitPtrs;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AdvancedDisplay, Category = "Squad")
	AUnit* m_leaderUnit;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AdvancedDisplay, Category = "Squad")
	UClass* m_potentialBP;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AdvancedDisplay, Category = "Squad")
	UClass* m_playerStart;

public:

	enum class SquadFormation
	{
		ThreeRow,
		TwoRow,
		OneRow,
		Diamond,
	};

	SquadFormation m_squadFormation = SquadFormation::OneRow;

// method

	void initSquad();

	UFUNCTION(BlueprintCallable , Category="Squad Creation")
	virtual void createSquad(int32 numberOfUnit = 1);
	
	void setLeaderUnit(AUnit* leaderUnit);

private:

	AUnit* spawnUnit(UClass* targetUnitBP, int32 formationIndex = 0);
	

};

