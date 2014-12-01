// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "TileBase.h"
#include "TileMapGenerator.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTSKY_API ATileMapGenerator : public AActor
{
	GENERATED_UCLASS_BODY()

	//member
private:
	FColor m_tileMapColor = FColor::FColor(0,0,0);// this tile map color value
	FVector2D m_tileMapSize = FVector2D(10, 10); // this is size of tile map
	UClass* m_tileBP; // tile bluePrint
	
	
public:
	//method
	void setColor(FColor color); // set size of color setting
	void setSize(FVector2D size); // set size of tile map
	void generateTileMap(); // generate tile map
	
	FColor getCorlorSetup(); // get current color setup
	FVector2D getSizeSetup(); // get current size setup

private :
	ATileBase* spawnTile(UClass *tileBP, FVector2D spawnLocIndex); // spawn tile base
};
