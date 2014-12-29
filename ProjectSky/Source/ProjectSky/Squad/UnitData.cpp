// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectSky.h"
#include "UnitData.h"

UnitData::UnitData(int32 squadSide , int32 hpMax , int32 stamMax)
{
    mSquadSide = squadSide;
    
    mHpMax = hpMax;
    mHp = hpMax;
    
    mStamMax = stamMax;
    mStam = stamMax;
    
}

UnitData::~UnitData()
{
}

int32 UnitData::getCurrentHP() const
{
    return mHp;
}

int32 UnitData::getCurrentStam() const
{
    return mStam;
}

int32 UnitData::getSide() const
{
    return mSquadSide;
}

void UnitData::addHP(int32 value)
{
    mHp += value;
    
    if(mHp < 0)
        mHp = 0;
}

void UnitData::addStam(int32 value)
{
    mStam += value;
    
    if(mStam < 0)
        mStam = 0;
}