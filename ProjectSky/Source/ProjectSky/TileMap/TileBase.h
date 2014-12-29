// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ProjectSky.h"
#include "GameFramework/Actor.h"
#include "TileBase.generated.h"


enum class TileColorType
{
	Red = 0,
	Green,
	Blue,
    Max,
};

/**
 * 
 */
UCLASS()
class PROJECTSKY_API ATileBase : public AActor
{
	GENERATED_UCLASS_BODY()
public:
	void init(TileColorType tileColorType);
	void setTileColrType(TileColorType tileColorType);
	TileColorType getTileColorType();
		
protected:
    TileColorType mColorType = TileColorType::Red;
private:

};
