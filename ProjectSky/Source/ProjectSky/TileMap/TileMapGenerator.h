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
protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AdvancedDisplay, Category = "TileMapGenerator")
	FColor m_tileMapColor = FColor::FColor(0,0,0);// this tile map color value
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AdvancedDisplay, Category = "TileMapGenerator")
	FVector2D m_tileMapSize = FVector2D(10, 10); // this is size of tile map

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category = "TileMapGenerator")
	UClass* m_tileBP; // tile bluePrint
	
	
public:
	//method
	UFUNCTION(BlueprintCallable, Category = "TileMapGenerator")
	void setColor(FColor tileMapColor); // set size of color setting

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
	ATileBase* spawnTile(UClass *tileBP, FVector2D spawnLocIndex); // spawn tile base
};
