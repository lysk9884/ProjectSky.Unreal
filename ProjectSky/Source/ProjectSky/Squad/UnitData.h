// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UnitData.generated.h"

/**
 * 
 */
UCLASS(CustomConstructor)
class PROJECTSKY_API UUnitData : public UObject
{
    GENERATED_BODY()
    
public:
    
    UUnitData();
    
    UUnitData(int32 squadSide ,int32 formationIndex ,  int32 hpMax , int32 stamMax);

    UFUNCTION(BlueprintCallable , Category = "UnitData")
    int32 getCurrentHP() const;
    
    UFUNCTION(BlueprintCallable , Category = "UnitData")
    int32 getCurrentStam() const;
    
    UFUNCTION(BlueprintCallable , Category = "UnitData")
    int32 getSide() const;
    
    UFUNCTION(BlueprintCallable , Category = "UnitData")
    int32 getFormationIndex() const;
    
    UFUNCTION(BlueprintCallable , Category = "UnitData")
    void addHP(int32 value);
    
    UFUNCTION(BlueprintCallable , Category = "UnitData")
    void addStam(int32 value);
    
private:
    int32 mSquadSide = 1;
    
    int32 mHpMax = 100;
    int32 mHp = 100;
    
    int32 mStamMax = 100;
    int32 mStam = 100;
    
    int32 mFormationIndex = 0;
};
