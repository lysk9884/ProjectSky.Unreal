// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Squad/Squad.h"
#include "GameFramework/Character.h"
#include "Unit.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTSKY_API AUnit : public ACharacter
{
	GENERATED_BODY()
	
		//fields
protected:
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, AdvancedDisplay, Category = "Unit")
	ASquad* m_curSquad = NULL;

	
public:

	//DECLARE_DYNAMIC_DELEGATE(FUnitAction);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FUnitAction);

	UPROPERTY(BlueprintAssignable, Category = "Unit")
	FUnitAction UnitMoveFinihed;

	// methods
	UFUNCTION(BlueprintCallable, Category = "Unit")
	virtual ASquad* getSquad();

protected:
	UFUNCTION(BlueprintCallable, Category = "Unit")
		void onUnitMoveFinished();

	
};
