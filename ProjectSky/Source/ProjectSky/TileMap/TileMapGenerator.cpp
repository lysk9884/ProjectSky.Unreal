// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectSky.h"
#include "TileMapGenerator.h"

// TileMapData
TileMapData::TileMapData(ColorSetup colorSetup , FVector2D tileMapSize)
{
    mColorSetup = colorSetup;
    int totalNumOfTiles = (int)tileMapSize.X * (int)tileMapSize.Y;
    
    mNumColorTile.numRed = ((int)colorSetup.Red / 100.0f) * totalNumOfTiles;
    mNumColorTile.numGreen = ((int)colorSetup.Green / 100.0f) * totalNumOfTiles;
    mNumColorTile.numBlue = ((int)colorSetup.Blue / 100.0f) * totalNumOfTiles;

    UE_LOG(LogTemp, Warning, TEXT("color setup is %d, %d, %d"), mColorSetup.R , mColorSetup.G , mColorSetup.B);

    UE_LOG(LogTemp, Warning, TEXT("number of color tiles %d , %d , %d"), mNumColorTile.numRed , mNumColorTile.numGreen , mNumColorTile.numBlue);
    
    mArrColorTypes.Append(getSelectedColorTypeArr(TileColorType::Red , mNumColorTile.numRed));
    mArrColorTypes.Append(getSelectedColorTypeArr(TileColorType::Green , mNumColorTile.numGreen));
    mArrColorTypes.Append(getSelectedColorTypeArr(TileColorType::Blue , mNumColorTile.numBlue));
    
    UE_LOG(LogTemp, Warning, TEXT("number of mArrColorTypes %d"), mArrColorTypes.Num());
}

TileColorType TileMapData::getTileColorType()
{
    int selectedIndex = FMath::RandRange(0, mArrColorTypes.Num() - 1 );
    
    if(selectedIndex < 0 )
        selectedIndex = 0;
    
    TileColorType selectedTileColorType = mArrColorTypes[selectedIndex];
    
    mArrColorTypes.RemoveAt(selectedIndex);
    
    return selectedTileColorType;
}

TArray<TileColorType> TileMapData::getSelectedColorTypeArr(TileColorType tileColorType , int size)
{
    TArray<TileColorType> arrColorType;
    
    for(int i = 0 ; i < size ; i ++)
    {
        arrColorType.Add(tileColorType);
    }
    
    return arrColorType;
}

// tileMapData- end

ATileMapGenerator::ATileMapGenerator(const class FObjectInitializer& PCIP)
	: Super(PCIP)
{
	UE_LOG(LogTemp, Warning, TEXT("Tile Map is Generated"));
    USceneComponent* sceneComponent = PCIP.CreateDefaultSubobject<USceneComponent>(this, TEXT("RootCompo_Dummy"));

	this->RootComponent = sceneComponent;
}

void ATileMapGenerator::setColor(int red = 0, int green = 0 , int blue = 0 )
{
    mTileMapColor.Red = red;
    mtileMapColor.Green = green;
    mtileMapColor.Blue = blue;
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
    mTileMapData = new TileMapData(mTileMapColor , m_tileMapSize);
    
	//Generate tile map here
	for (int i = 0; i < (int)(m_tileMapSize.X); i++)
	{
		for (int j = 0; j < (int)m_tileMapSize.Y; j++)
		{
            int32 tileColorType = (int32)(mTileMapData->getTileColorType());
			ATileBase* tileBase = spawnTile(m_tileBP, FVector2D(i, j),tileColorType); // width Index , height Index
		}
	}
	UE_LOG(LogTemp, Log, TEXT("generate Tile map is finished!"));
}

ATileBase* ATileMapGenerator::spawnTile(UClass *tileBP, FVector2D spawnLocIndex , int32  tileColrType)
{
	ATileBase* tileBase = nullptr;
	FVector2D sizeTileBase = FVector2D(400, 400);
    
    FColor colorTileBase = FColor::Red;
    
    switch (tileColrType)
    {
        case (int32)TileColorType::Red:
            colorTileBase = FColor::Red;
            break;
        case (int32)TileColorType::Green:
            colorTileBase = FColor::Green;
            break;
        case (int32)TileColorType::Blue:
            colorTileBase = FColor::Blue;
            break;
        default:
            break;
    }

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

