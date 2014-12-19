// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ProjectSky.h"
#include "Array.h"
#include "TileMap/TileBase.h"
#include "GameFramework/Actor.h"
#include "TileMapGenerator.generated.h"

/**
 * 
 */



class PROJECTSKY_API TileMapData
{
public:
    struct ColorSetup
    {
        int32 Red = 0;
        int32 Green = 0;
        int32 Blue = 0;
    };
    struct NumColorTile
    {
        int32 numRed = 0;
        int32 numGreen = 0;
        int32 numBlue =0;
    };
    
private:
    // members
    int32 mTotalNumTiles = 0;
    NumColorTile mNumColorTile;
    TArray<TileColorType> mArrColorTypes;
    
public:
    ColorSetup mColorSetup ;
    
    // constructor
    TileMapData(FVector2D tileMapSize); // constructor
    ~TileMapData(); //Destructor
    // methods
    NumColorTile getNumColorTile();
    TileColorType getTileColorType();
    void generateTileMapData();
private:
    TArray<TileColorType> getSelectedColorTypeArr(TileColorType tileColorType , int32 size = 1);
};
UCLASS()
class PROJECTSKY_API ATileMapGenerator : public AActor
{
	GENERATED_UCLASS_BODY()

	//member
protected:
    
    TileMapData* mTileMapData = nullptr;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AdvancedDisplay, Category = "TileMapGenerator")
	FVector2D m_tileMapSize = FVector2D(10, 10); // this is size of tile map

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category = "TileMapGenerator")
	UClass* m_tileBP; // tile bluePrint
	
public:
	//method
	UFUNCTION(BlueprintCallable, Category = "TileMapGenerator")
	void setSize(FVector2D tileMapSize); // set size of tile map

	UFUNCTION(BlueprintCallable, Category = "TileMapGenerator")
	FVector2D getSizeSetup(); // get current size setup

	UFUNCTION(BlueprintCallable, Category = "TileMapGenerator")
	virtual void generateTileMap(int32 red , int32 green , int32 blue); // generate tile map

private :

	UFUNCTION(BlueprintCallable, Category = "TileMapGenerator")
    ATileBase* spawnTile(UClass *tileBP, FVector2D spawnLocIndex , int32  tileColrType ); // spawn tile base
};


