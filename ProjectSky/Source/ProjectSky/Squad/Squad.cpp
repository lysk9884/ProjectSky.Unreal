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

void ASquad::createSquad(int32 numberOfUnit , FVector initLoc)
{
	if (numberOfUnit < m_minUnitNum)
		numberOfUnit = m_minUnitNum;

	if (numberOfUnit > m_maxUnitNum)
		numberOfUnit = m_maxUnitNum;
    
    this->SetActorLocation(initLoc);
    
    this->setTargetLoc(initLoc);

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
    
    mSquadSide = FMath::RandRange(0, 1);
}

// spawn bp unit
AUnit* ASquad::spawnUnit(UClass* targetUnitBP, int32 formationIndex /* = 0 */)
{
	// spawn Bp unit here
	AUnit* unit = NULL;

	UE_LOG(LogTemp, Log, TEXT("unit is generated"));

	unit = Utility::SpawnBP<AUnit>(this->GetWorld(), targetUnitBP, this->GetActorLocation() , FRotator(0, 0, 0), false);
    
    if(unit != NULL)
    {
        FVector unitLoc = getUnitPos(unit , formationIndex);
        unit->SetActorLocation(unitLoc);
        unit->SpawnDefaultController();
        
        unit->initUnitData(mSquadSide, 100, 100);
    }
    
	return unit;
}

void ASquad::setSquadFormation(int32 squadFormation)
{
    mSquadFormation = (SquadFormation)squadFormation;
}

int32 ASquad::getSquadFormation() const
{
    return (int32)mSquadFormation;
}

void ASquad::setLeaderUnit(AUnit* leaderUnit)
{
	// set leader unit;
	m_leaderUnit = leaderUnit;
}

FVector ASquad::getUnitPos(AUnit* unit, int32 unitPosIndex) const
{
    float   unitCapsuleRadious = unit->GetCapsuleComponent()->GetScaledCapsuleRadius();
    float	distToUnit = 150.0f + unitCapsuleRadious;
    
    FVector unitLoc = mTargetLoc;
    int32 numUnitCol = 0;


    switch (mSquadFormation)
    {
    case ASquad::SquadFormation::ThreeRow:

        break;
    case ASquad::SquadFormation::TwoRow:

        numUnitCol = m_maxUnitNum / 2;

        unitLoc.Y += distToUnit * unitPosIndex;

        if (unitPosIndex >= numUnitCol)
        {
            unitLoc.X += distToUnit;
        }

        break;
    case ASquad::SquadFormation::OneRow:

        //unitLoc = FVector(unitLoc.X, unitLoc.Y + (distToUnit * formationIndex), unitLoc.Z);
        unitLoc.Y += distToUnit * unitPosIndex;

        break;
    case ASquad::SquadFormation::Diamond:

        if (unitPosIndex < 1)
            break;

        if (unitPosIndex <= 2)
        {
            unitLoc.X += distToUnit;
            unitLoc.Y += (distToUnit / 2) * (unitPosIndex> 1 ? 1 : -1);
        }
        else if (unitPosIndex <= 4)
        {
            unitLoc.Y += distToUnit *(unitPosIndex == 4 ? 1 : -1);
        }
        else
        {
            unitLoc.X -= distToUnit;
        }

        break;
    }

    return unitLoc;
}

void ASquad::setTargetLoc(FVector targetLoc)
{
    mTargetLoc = targetLoc;
}

int32 ASquad::getSquadSide() const
{
    return mSquadSide;
}


void ASquad::Tick(float DeltaSeconds)
{
    if(m_leaderUnit != NULL)
        this->SetActorLocation(m_leaderUnit->GetActorLocation());
}





