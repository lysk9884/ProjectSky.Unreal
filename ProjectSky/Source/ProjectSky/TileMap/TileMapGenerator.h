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
        int Red = 0;
        int Green = 0;
        int Blue = 0;
    };
    struct NumColorTile
    {
        int numRed = 0;
        int numGreen = 0;
        int numBlue =0;
    };
    
private:
    // members
    ColorSetup mColorSetup ;
    NumColorTile mNumColorTile;
    TArray<TileColorType> mArrColorTypes;
    
public:
    // constructor
    TileMapData(ColorSetup colorSetup , FVector2D tileMapSize); // constructor
    ~TileMapData(); //Destructor
    // methods
    NumColorTile getNumColorTile();
    TileColorType getTileColorType();
private:
    TArray<TileColorType> getSelectedColorTypeArr(TileColorType tileColorType , int size = 1);
};
UCLASS()
class PROJECTSKY_API ATileMapGenerator : public AActor
{
	GENERATED_UCLASS_BODY()

	//member
protected:
    
    TileMapData* mTileMapData = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AdvancedDisplay, Category = "TileMapGenerator")
    TileMapData::ColorSetup  mTileMapColor;// this tile map color value
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AdvancedDisplay, Category = "TileMapGenerator")
	FVector2D m_tileMapSize = FVector2D(10, 10); // this is size of tile map

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category = "TileMapGenerator")
	UClass* m_tileBP; // tile bluePrint
	
public:
	//method
	UFUNCTION(BlueprintCallable, Category = "TileMapGenerator")
    void setColor( int red = 0, int green = 0 , int blue = 0 ); // set size of color setting

	UFUNCTION(BlueprintCallable, Category = "TileMapGenerator")
	void setSize(FVector2D tileMapSize); // set size of tile map

	UFUNCTION(BlueprintCallable, Category = "TileMapGenerator")
	FColor getCorlorSetup(); // get current color setup

	UFUNCTION(BlueprintCallable, Category = "TileMapGenerator")
	FVector2D getSizeSetup(); // get current size setup

	UFUNCTION(BlueprintCallable, Category = "TileMapGenerator")
	virtual void generateTileMap(); // generate tile map

private :

	UFUNCTION(BlueprintCallable, Category = "TileMapGenerator")
    ATileBase* spawnTile(UClass *tileBP, FVector2D spawnLocIndex , int32  tileColrType ); // spawn tile base
};


