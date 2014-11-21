// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectSky.h"
#include "Squad.h"


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
	}
	for (int i = 0; i < numberOfUnit; i++)
	{
		
		
		//spawn bp unit here
		ACharacter* unit = spawnUnit(m_potentialBP, squadLoc);
		m_unitPtrs.Add(unit);

		if (i == 0) // first unit as leader Unit
		{
			ACharacter* leaderUnit = Cast<ACharacter>(m_unitPtrs[0]);
			setLeaderUnit(leaderUnit );
		}

		FVector unitWorldScale = unit->GetActorScale3D();
		FVector unitLocalScale = unit->GetActorRelativeScale3D();
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
			
			unitLoc = FVector(squadLoc.X, squadLoc.Y + (distToUnit * i), squadLoc.Z);
			
			break;
		case ASquad::SquadFormation::Diamond:
			
			if (i < 1)
				break;

			if (i <= 2)
			{
				unitLoc.X += distToUnit;
				unitLoc.Y += (distToUnit / 2) * ( i > 1 ? 1 : -1);
			}
			else if (i <= 4)
			{
				unitLoc.Y += distToUnit *(i == 4 ? 1 : -1);
			}
			else
			{
				unitLoc.X -= distToUnit;
			}

			break;
		}

		
		unit->SetActorLocation(unitLoc);
	}

	UE_LOG(LogTemp, Log, TEXT("number of unit in this squad is %d"),m_unitPtrs.Num());
}

// spawn bp unit
 ACharacter* ASquad::spawnUnit(UClass* targetUnitBP, const FVector& initLoc /* = FVector(0, 0, 0) */)
{
	// spawn Bp unit here
	

	AActor* unit = NULL;
		

	unit = Utility::SpawnBP<AActor>(this->GetWorld(), targetUnitBP, initLoc, FRotator(0, 0, 0), false );

	ACharacter* unitChar = Cast<ACharacter>(unit);

	if (unitChar != NULL)
		return unitChar;
	else
		return NULL;
	

}

void ASquad::setLeaderUnit(ACharacter* leaderUnit)
{
	// set leader unit;
	m_leaderUnit = leaderUnit;
}





