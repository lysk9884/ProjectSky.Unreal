// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectSky.h"
#include "Utility.h"
#include "TileMapGenerator.h"

ATileMapGenerator::ATileMapGenerator(const class FObjectInitializer& PCIP)
	: Super(PCIP)
{
	UE_LOG(LogTemp, Warning, TEXT("Tile Map is Generated"));
}

void ATileMapGenerator::setColor(FColor color)
{
	m_tileMapColor = color;
}

void ATileMapGenerator::setSize(FVector2D size)
{
	m_tileMapSize = size;
}

void ATileMapGenerator::generateTileMap()
{
	//Generate tile map here
	for (int i = 0; i < (int)(m_tileMapSize.X); i++)
	{
		for (int j = 0; j < (int)m_tileMapSize.Y; j++)
		{
			ATileBase* tileBase = spawnTile(m_tileBP, FVector2D(i, j)); // width Index , height Index
		}
	}
	UE_LOG(LogTemp, Log, TEXT("generate Tile map is finished!"));
}

ATileBase* ATileMapGenerator::spawnTile(UClass *tileBP, FVector2D spawnLocIndex)
{
	ATileBase* tileBase = nullptr;

	tileBase = Utility::SpawnBP<ATileBase>(this->GetWorld(), tileBP, this->GetActorLocation(), this->GetActorRotation());

	if (tileBase != NULL)
		return tileBase;
	else
	{
		UE_LOG(LogTemp, Error, TEXT("tile base spawaning is failed"));

		return tileBase;
	}
}