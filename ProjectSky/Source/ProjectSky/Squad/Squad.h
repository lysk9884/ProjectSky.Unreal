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

protected:
	SquadFormation mSquadFormation = SquadFormation::Diamond;
public:
// method
	void initSquad();
    UFUNCTION(BlueprintCallable , Category= "Squad")
	virtual void createSquad(int32 numberOfUnit = 1);
	
    UFUNCTION(BlueprintCallable, Category = "Squad")
    void setSquadFormation(int32 squadFormation);

    UFUNCTION(BlueprintCallable, Category = "Squad")
    int32 getSquadFormation();

    UFUNCTION(BlueprintCallable, Category = "Squad")
	void setLeaderUnit(AUnit* leaderUnit);

    UFUNCTION(BlueprintCallable , Category ="Squad")
    FVector getUnitPos(AUnit* unit ,int32 unitPosIndex);
private:
	AUnit* spawnUnit(UClass* targetUnitBP, int32 formationIndex = 0);
};

