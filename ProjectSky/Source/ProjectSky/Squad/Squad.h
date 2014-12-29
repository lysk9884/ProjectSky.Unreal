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
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AdvancedDisplay, Category = "Squad Memeber")
	TArray<AUnit*> m_unitPtrs;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AdvancedDisplay, Category = "Squad Memeber")
	AUnit* m_leaderUnit;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AdvancedDisplay, Category = "Squad Memeber")
	UClass* m_potentialBP;
    
    UPROPERTY(EditDefaultsOnly , BlueprintReadOnly , AdvancedDisplay , Category ="Squad Memeber")
    FVector mTargetLoc;

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
    UFUNCTION(BlueprintCallable , Category = "Squad Method")
    virtual void createSquad(int32 numberOfUnit = 1 , FVector initLoc = FVector::ZeroVector);
	
    UFUNCTION(BlueprintCallable, Category = "Squad Method")
    void setSquadFormation(int32 squadFormation);

    UFUNCTION(BlueprintCallable, Category = "Squad Method")
    int32 getSquadFormation() const;

    UFUNCTION(BlueprintCallable, Category = "Squad Method")
	void setLeaderUnit(AUnit* leaderUnit);

    UFUNCTION(BlueprintCallable , Category = "Squad Method")
    FVector getUnitPos(AUnit* unit ,int32 unitPosIndex) const;
    
    UFUNCTION(BlueprintCallable , Category = "Squad Method")
    void setTargetLoc(FVector targetLoc);
    
    UFUNCTION(BlueprintCallable , Category = "Squad Method")
    int32 getSquadSide() const;
    
    virtual void Tick(float DeltaSeconds) override;
    
   
    
private:
	AUnit* spawnUnit(UClass* targetUnitBP, int32 formationIndex = 0);
    
    int32 mSquadSide = 0;
    
};

