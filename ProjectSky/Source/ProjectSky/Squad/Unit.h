// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "GameFramework/Character.h"
#include "Unit.generated.h"

class UUnitData;

/**
 * 
 */
UCLASS()
class PROJECTSKY_API AUnit : public ACharacter
{
	GENERATED_BODY()
	
		//fields
protected:
	
public:
	//DECLARE_DYNAMIC_DELEGATE(FUnitAction);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FUnitAction);

	// members
	UPROPERTY(BlueprintAssignable, Category = "Unit")
    FUnitAction UnitMoveFinihed;
protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AdvancedDisplay, Category = "Unit")
    AActor* m_curSquadActor;
    
    UUnitData* mUnitData;
    
	//methods
	UFUNCTION(BlueprintCallable, Category = "Unit")
    void onUnitMoveFinished();
public:
	UFUNCTION(BlueprintCallable, Category = "Unit")
    AActor* getSquadActor();

	UFUNCTION(BlueprintCallable, Category = "Unit")
    void setSquadActor(AActor* squadActor);
    
    UFUNCTION(BlueprintCallable , Category = "Unit")
    void moveToTargetPos(FVector targetPos);
    
    UFUNCTION(BlueprintCallable , Category = "Unit")
    void initUnitData(int32 squadSide , int32 formationIndex , int32 hpMax, int32 stamMax);
    
    UFUNCTION(BlueprintCallable , Category = "Unit")
    UUnitData* getUnitData() const;

};
