// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectSky.h"
#include "Utility.h"
#include "Unit.h"



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

//void Aunit::moveToTargetPos(FVector targetPos)
//{
//    this->ACharacter::GetMovementComponent()->mo
//}