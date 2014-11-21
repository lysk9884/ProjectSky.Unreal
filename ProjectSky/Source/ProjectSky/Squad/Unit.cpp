// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectSky.h"
#include "Unit.h"


ASquad* AUnit::getSquad()
{
	if (m_curSquad != NULL)
		return m_curSquad;
	else
	{
		UE_LOG(LogTemp, Error, TEXT("no squad "));
		return NULL;
	}
}

void AUnit::onUnitMoveFinished()
{
	UnitMoveFinihed.Broadcast();
}


