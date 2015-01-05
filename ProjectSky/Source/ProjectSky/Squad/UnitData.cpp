// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectSky.h"
#include "UnitData.h"

UUnitData::UUnitData()
{
}

UUnitData::UUnitData(int32 squadSide ,int32 formationIndex ,  int32 hpMax , int32 stamMax) : UUnitData::UUnitData()
{
    mSquadSide = squadSide;
    
    mFormationIndex = formationIndex;
    
    mHpMax = hpMax;
    mHp = hpMax;
    
    mStamMax = stamMax;
    mStam = stamMax;

}

int32 UUnitData::getCurrentHP() const
{
    return mHp;
}

int32 UUnitData::getCurrentStam() const
{
    return mStam;
}

int32 UUnitData::getSide() const
{
    return mSquadSide;
}

int32 UUnitData::getFormationIndex() const
{
    return mFormationIndex;
}

void UUnitData::addHP(int32 value)
{
    mHp += value;
    
    if(mHp < 0)
        mHp = 0;
}

void UUnitData::addStam(int32 value)
{
    mStam += value;
    
    if(mStam < 0)
        mStam = 0;
}