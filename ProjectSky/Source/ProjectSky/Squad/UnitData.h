// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/**
 * 
 */
class PROJECTSKY_API UnitData
{
public:
	UnitData(int32 squadSide , int32 hpMax , int32 stamMax);
	~UnitData();
    
    UFUNCTION(BlueprintCallable , Category = "UnitData")
    int32 getCurrentHP() const;
    UFUNCTION(BlueprintCallable , Category = "UnitData")
    int32 getCurrentStam() const;
    UFUNCTION(BlueprintCallable , Category = "UnitData")
    int32 getSide() const;
    
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
};
