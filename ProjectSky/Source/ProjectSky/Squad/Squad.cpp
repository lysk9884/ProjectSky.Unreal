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

void ASquad::createSquad(int32 numberOfUnit , FVector initLoc , ESquadFormation::Type squadFormation)
{
	if (numberOfUnit < m_minUnitNum)
		numberOfUnit = m_minUnitNum;

	if (numberOfUnit > m_maxUnitNum)
		numberOfUnit = m_maxUnitNum;
    
    this->SetActorLocation(initLoc);
    
    this->setTargetLoc(initLoc);
    
    this->setSquadFormation(squadFormation);

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
//        unit->AttachRootComponentToActor(this);
        unit->SetActorLocation(unitLoc);
        unit->SpawnDefaultController();
        unit->initUnitData(mSquadSide, formationIndex , 100, 100);
    }
    
	return unit;
}

void ASquad::setSquadFormation(ESquadFormation::Type squadFormation)
{
    mSquadFormation = (ESquadFormation::Type)squadFormation;
}

ESquadFormation::Type ASquad::getSquadFormation() const
{
    return mSquadFormation;
}

void ASquad::setLeaderUnit(AUnit* leaderUnit)
{
	// set leader unit;
	m_leaderUnit = leaderUnit;
}

FVector ASquad::getUnitPos(AUnit* unit, int32 unitPosIndex) const
{
    float unitCapsuleRadious = unit->GetCapsuleComponent()->GetScaledCapsuleRadius();
    float distToUnit = 150.0f + unitCapsuleRadious;
    
    float yOffset = 0;
    float xOffset = 0;
    
    FVector unitLoc = mTargetLoc;
    FVector squadLoc = this->GetActorLocation();
    
    float degree = FMath::Atan2((float)(mTargetLoc.Y - squadLoc.Y), (float)(mTargetLoc.X - squadLoc.X)) * 180 / 3.1415f;
    
    int32 numUnitCol = 0;

    switch (mSquadFormation)
    {
    case ESquadFormation::ThreeRow:

        break;
    case ESquadFormation::TwoRow:

        numUnitCol = m_maxUnitNum / 2;
            
        yOffset = distToUnit * (unitPosIndex );//% numUnitCol);
        yOffset = FMath::Cos(degree + 90) * yOffset;
            
        unitLoc.Y += yOffset;
        
//        xOffset = (int)(unitPosIndex / numUnitCol) * distToUnit;
        xOffset = distToUnit * (unitPosIndex );
        xOffset = FMath::Sign(degree + 90) * xOffset;
        unitLoc.X -= xOffset;
            
        break;
    case ESquadFormation::Diamond:

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
    {
        this->SetActorLocation(m_leaderUnit->GetActorLocation());
//        this->SetActorRotation(m_leaderUnit->GetActorRotation());
    }
}





