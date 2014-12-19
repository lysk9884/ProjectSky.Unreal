// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectSky.h"
#include "Utility.h"
#include "Squad.h"


ASquad::ASquad(const class FObjectInitializer& PCIP)
	: Super(PCIP)
{
	UE_LOG(LogTemp, Warning, TEXT("Squad is generated"));
    
    USceneComponent* sceneComponent = PCIP.CreateDefaultSubobject<USceneComponent>(this, TEXT("Root"));
    
    this->RootComponent = sceneComponent;
}

void ASquad::initSquad()
{
	// initialize squad here
}

void ASquad::createSquad(int32 numberOfUnit)
{
	if (numberOfUnit < m_minUnitNum)
		numberOfUnit = m_minUnitNum;

	if (numberOfUnit > m_maxUnitNum)
		numberOfUnit = m_maxUnitNum;

	APlayerStart* playerStart = NULL;

	for (TActorIterator<APlayerStart> actorItr(GetWorld()); actorItr; ++actorItr)
	{
		UE_LOG(LogTemp, Warning, TEXT("actor name in the iterator : %s"),  *actorItr->GetName() );
		UE_LOG(LogTemp, Warning, TEXT("actor name in the iterator : %s"), *actorItr->GetActorClass()->GetName());
		playerStart = Cast<APlayerStart>(*actorItr);

		if (playerStart != NULL)
		{
			break;
		}
	}
	
	FVector squadLoc = FVector(ForceInitToZero);

	if (playerStart != NULL)
	{
		UE_LOG(LogTemp, Warning, TEXT("player start location:{0}"), *playerStart->GetActorLocation().ToString());
		squadLoc = playerStart->GetActorLocation();
		this->SetActorLocation(squadLoc);
	}

	for (int i = 0; i < numberOfUnit; i++)
	{
		
		//spawn bp unit here
		AUnit* unit = ASquad::spawnUnit(m_potentialBP,i);
		
		m_unitPtrs.Add(unit);

		if (unit == NULL)
			continue;

		unit->setSquadActor(this);

		if (i == 0) // first unit as leader Unit
		{
			AUnit* leaderUnit = m_unitPtrs[0];
			setLeaderUnit(leaderUnit );
		}

	}

	UE_LOG(LogTemp, Log, TEXT("number of unit in this squad is %d"),m_unitPtrs.Num());
}

// spawn bp unit
AUnit* ASquad::spawnUnit(UClass* targetUnitBP, int32 formationIndex /* = 0 */)
{
	// spawn Bp unit here
	AUnit* unit = NULL;
	FVector squadLoc = this->GetActorLocation();
	
	UE_LOG(LogTemp, Log, TEXT("unit is generated"));

	unit = Utility::SpawnBP<AUnit>(this->GetWorld(), targetUnitBP, this->GetActorLocation() , FRotator(0, 0, 0), false);

	float   unitCapsuleRadious = unit->GetCapsuleComponent()->GetScaledCapsuleRadius();
	float	distToUnit = 150.0f + unitCapsuleRadious;

	FVector unitLoc = FVector(squadLoc.X, squadLoc.Y, squadLoc.Z);

	switch (m_squadFormation)
	{
	case ASquad::SquadFormation::ThreeRow:

		break;
	case ASquad::SquadFormation::TwoRow:

		break;
	case ASquad::SquadFormation::OneRow:

		unitLoc = FVector(squadLoc.X, squadLoc.Y + (distToUnit * formationIndex), squadLoc.Z);

		break;
	case ASquad::SquadFormation::Diamond:

		if (formationIndex < 1)
			break;

		if (formationIndex <= 2)
		{
			unitLoc.X += distToUnit;
			unitLoc.Y += (distToUnit / 2) * (formationIndex > 1 ? 1 : -1);
		}
		else if (formationIndex <= 4)
		{
			unitLoc.Y += distToUnit *(formationIndex == 4 ? 1 : -1);
		}
		else
		{
			unitLoc.X -= distToUnit;
		}

		break;
	}

	unit->SetActorLocation(unitLoc);
//    unit->AttachRootComponentToActor(this);
    
	return unit;

}

void ASquad::setLeaderUnit(AUnit* leaderUnit)
{
	// set leader unit;
	m_leaderUnit = leaderUnit;
}





