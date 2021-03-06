// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectSky.h"
#include "AIController.h"
#include "Unit.h"
#include "UnitData.h"

void AUnit::onUnitMoveFinished()
{
	UnitMoveFinihed.Broadcast();
}

AActor* AUnit::getSquadActor()
{
	return m_curSquadActor;
}

void AUnit::setSquadActor(AActor* squadActor)
{
	m_curSquadActor = squadActor;
}

void AUnit::moveToTargetPos(FVector targetPos)
{
    AController* controller = this->GetController();
    AAIController* aiCon = Cast<AAIController>(controller);
    
    EPathFollowingRequestResult::Type result = aiCon->MoveToLocation(targetPos);
    
    if( result == EPathFollowingRequestResult::RequestSuccessful)
    {
        UE_LOG(LogTemp , Warning, TEXT("success to move"));
    }
    else if(result == EPathFollowingRequestResult::Failed)
    {
        UE_LOG(LogTemp, Warning, TEXT("failed to move"));
    }
    else if(result == EPathFollowingRequestResult::AlreadyAtGoal)
    {
        UE_LOG(LogTemp, Warning, TEXT("already there "));
    }
}

void AUnit::initUnitData(int32 squadSide , int32 formationIndex , int32 hpMax, int32 stamMax)
{
    mUnitData = new UUnitData(squadSide , formationIndex , hpMax , stamMax);
}

UUnitData* AUnit::getUnitData() const
{
    return mUnitData;
}