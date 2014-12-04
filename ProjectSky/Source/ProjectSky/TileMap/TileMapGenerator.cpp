// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectSky.h"
#include "Utility.h"
#include "TileMapGenerator.h"

// TileMapData
TileMapData::TileMapData(FColor colorSetup , FVector2D tileMapSize)
{
    mColorSetup = colorSetup;
    int totalNumOfTiles = (int)tileMapSize.X * (int)tileMapSize.Y;
    
    mNumColorTile.numRed = (colorSetup.R / 255) * totalNumOfTiles;
    mNumColorTile.numGreen = (colorSetup.G / 255) * totalNumOfTiles;
    mNumColorTile.numBlue = (colorSetup.B / 255) * totalNumOfTiles;
    
    UE_LOG(LogTemp, Warning, TEXT("number of color tiles {0}{1}{2}"), mNumColorTile.numRed , mNumColorTile.numGreen , mNumColorTile.numBlue);
    
}
// tileMapData- end

ATileMapGenerator::ATileMapGenerator(const class FObjectInitializer& PCIP)
	: Super(PCIP)
{
	UE_LOG(LogTemp, Warning, TEXT("Tile Map is Generated"));
    PCIP.CreateDefaultSubobject<USceneComponent>(this, TEXT("RootCompo_Dummy"));
}

void ATileMapGenerator::setColor(FColor tileMapColor)
{
	m_tileMapColor = tileMapColor;
}

void ATileMapGenerator::setSize(FVector2D tileMapSize)
{
	m_tileMapSize = tileMapSize;
}

FColor ATileMapGenerator::getCorlorSetup()
{
	return m_tileMapColor;
}

FVector2D ATileMapGenerator::getSizeSetup()
{
	return m_tileMapSize;
}

void ATileMapGenerator::generateTileMap() 
{
    //Generate Tile Map Data
    mTileMapData = new TileMapData(m_tileMapColor , m_tileMapSize);
    
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
	FVector2D sizeTileBase = FVector2D(400, 400);

	FColor colorTileBase = FColor(	FMath::RandRange(0, (int)m_tileMapColor.R * 100) / 100, 
									FMath::RandRange(0, (int)m_tileMapColor.G * 100) / 100,
									FMath::RandRange(0, (int)m_tileMapColor.B * 100) / 100,
									m_tileMapColor.A );

	FVector locSpawnTileBase = FVector(this->GetActorLocation().X + (int)spawnLocIndex.X * sizeTileBase.X, this->GetActorLocation().Y + (int)spawnLocIndex.Y * sizeTileBase.Y, this->GetActorLocation().Z);

	tileBase = Utility::SpawnBP<ATileBase>(this->GetWorld(), tileBP, locSpawnTileBase, this->GetActorRotation());

	if (tileBase != NULL)
	{
        tileBase->AttachRootComponentToActor(this);
		UStaticMeshComponent* meshComponent = tileBase->FindComponentByClass<UStaticMeshComponent>();
		UMaterial* mat = meshComponent->GetMaterial(0)->GetMaterial();
		UMaterialInstanceDynamic* matInst = UMaterialInstanceDynamic::Create(mat, this);
		matInst->SetVectorParameterValue(FName("Color"), colorTileBase);
		meshComponent->SetMaterial(0, matInst);

		return tileBase;

	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("tile base spawaning is failed"));

		return tileBase;
	}
}

