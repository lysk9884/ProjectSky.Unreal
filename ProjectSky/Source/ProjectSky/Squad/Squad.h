// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Squad/Unit.h"
#include "GameFramework/Pawn.h"
#include "Squad.generated.h"


UENUM()
namespace ESquadFormation
{
    enum Type
    {
        TwoRow,
        ThreeRow,
        Diamond,
        Wedge
    };
}
/**
 *
 */
UCLASS()
class PROJECTSKY_API ASquad : public APawn
{
	GENERATED_UCLASS_BODY()

// fields
private:
	int m_minUnitNum = 1;
	int m_maxUnitNum = 6;
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AdvancedDisplay, Category = "Squad Member")
	TArray<AUnit*> m_unitPtrs;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AdvancedDisplay, Category = "Squad Member")
	AUnit* m_leaderUnit;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AdvancedDisplay, Category = "Squad Member")
	UClass* m_potentialBP;
    
    UPROPERTY(EditDefaultsOnly , BlueprintReadOnly , AdvancedDisplay , Category ="Squad Member")
    FVector mTargetLoc;
    
	UPROPERTY(EditDefaultsOnly , BlueprintReadOnly , AdvancedDisplay , Category = "Squad Member")
    FVector2D mSquadVolume = FVector2D::ZeroVector;
    
private :
    ESquadFormation::Type mSquadFormation = ESquadFormation::Diamond;
    int32 mSquadSide = 0;
    
public:
// method
    UFUNCTION(BlueprintCallable , Category = "Squad Method")
    virtual void createSquad(int32 numberOfUnit = 1 , FVector initLoc = FVector::ZeroVector , ESquadFormation::Type squadFormation = ESquadFormation::Diamond);
	
    UFUNCTION(BlueprintCallable, Category = "Squad Method")
    void setSquadFormation(ESquadFormation::Type squadFormation);

    UFUNCTION(BlueprintCallable, Category = "Squad Method")
    ESquadFormation::Type getSquadFormation() const;

    UFUNCTION(BlueprintCallable, Category = "Squad Method")
	void setLeaderUnit(AUnit* leaderUnit);

    UFUNCTION(BlueprintCallable , Category = "Squad Method")
    FVector getUnitPos(AUnit* unit ,int32 unitPosIndex) const;
    
    UFUNCTION(BlueprintCallable , Category = "Squad Method")
    void setTargetLoc(FVector targetLoc);
    
    UFUNCTION(BlueprintCallable , Category = "Squad Method")
    int32 getSquadSide() const;
    
    UFUNCTION(BlueprintCallable , Category = "Squad Method")
    FVector2D getSquadVolume() const;
    
    UFUNCTION(BlueprintCallable , Category = "Squad Method")
    virtual void Tick(float DeltaSeconds) override;

private:
	AUnit* spawnUnit(UClass* targetUnitBP, int32 formationIndex = 0);

    void calSquadVolume();
};

