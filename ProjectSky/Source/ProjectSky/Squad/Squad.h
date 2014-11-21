// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Utility.h"
#include "GameFramework/Pawn.h"
#include "Squad.generated.h"


/**
 * 
 */
UCLASS()
class PROJECTSKY_API ASquad : public APawn
{
	GENERATED_BODY()

// fields

private:

	int m_minUnitNum = 1;
	int m_maxUnitNum = 6;

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AdvancedDisplay, Category = "Squad")
	TArray<ACharacter*> m_unitPtrs;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AdvancedDisplay, Category = "Squad")
	ACharacter* m_leaderUnit;
	
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

	SquadFormation m_squadFormation = SquadFormation::Diamond;

// method

	void initSquad();

	UFUNCTION(BlueprintCallable , Category="Squad Creation")
	virtual void createSquad(int32 numberOfUnit = 1);
	
	void setLeaderUnit(ACharacter* leaderUnit);

private:

	ACharacter* spawnUnit(UClass* targetUnitBP, const FVector& initLoc = FVector(0, 0, 0));
	

};

