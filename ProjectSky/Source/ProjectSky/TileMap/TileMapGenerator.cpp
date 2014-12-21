// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectSky.h"
#include "TileMapGenerator.h"

// TileMapData
TileMapData::TileMapData(FVector2D tileMapSize)
{
    mTotalNumTiles = (int32)tileMapSize.X * (int)tileMapSize.Y;
}

TileColorType TileMapData::getTileColorType()
{
    int selectedIndex = FMath::RandRange(0, mArrColorTypes.Num() - 1 );
    
    if(selectedIndex < 0 )
        selectedIndex = 0;
    
    TileColorType selectedTileColorType = mArrColorTypes[selectedIndex];
    
    //mArrColorTypes.RemoveAt(selectedIndex);
    
    return selectedTileColorType;
}

void TileMapData::generateTileMapData()
{
    int32 totalColorValue = mColorSetup.Red + mColorSetup.Green + mColorSetup.Blue;
    
    mColorSetup.Red = (mColorSetup.Red / (float)totalColorValue) * 100;
    mColorSetup.Green = (mColorSetup.Green / (float)totalColorValue) * 100;
    mColorSetup.Blue = (mColorSetup.Blue / (float)totalColorValue) * 100;
    
    mNumColorTile.numRed = ((int32)mColorSetup.Red / 100.0f) * mTotalNumTiles;
    mNumColorTile.numGreen = ((int32)mColorSetup.Green / 100.0f) * mTotalNumTiles;
    mNumColorTile.numBlue = ((int32)mColorSetup.Blue / 100.0f) * mTotalNumTiles;
    
    UE_LOG(LogTemp, Warning, TEXT("color setup is %d, %d, %d"), mColorSetup.Red , mColorSetup.Green , mColorSetup.Blue);
    
    UE_LOG(LogTemp, Warning, TEXT("number of color tiles %d , %d , %d"), mNumColorTile.numRed , mNumColorTile.numGreen , mNumColorTile.numBlue);
    
    if(mNumColorTile.numRed > 0 )
        mArrColorTypes.Append(getSelectedColorTypeArr(TileColorType::Red , mNumColorTile.numRed));
    if(mNumColorTile.numGreen > 0 )
        mArrColorTypes.Append(getSelectedColorTypeArr(TileColorType::Green , mNumColorTile.numGreen));
    if(mNumColorTile.numBlue > 0)
        mArrColorTypes.Append(getSelectedColorTypeArr(TileColorType::Blue , mNumColorTile.numBlue));
    
    UE_LOG(LogTemp, Warning, TEXT("number of mArrColorTypes %d"), mArrColorTypes.Num());
}

TArray<TileColorType> TileMapData::getSelectedColorTypeArr(TileColorType tileColorType , int32 size)
{
    TArray<TileColorType> arrColorType;
    
    for(int32 i = 0 ; i < size ; i ++)
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
    USceneComponent* sceneComponent = PCIP.CreateDefaultSubobject<USceneComponent>(this, TEXT("Root"));

	this->RootComponent = sceneComponent;
}

void ATileMapGenerator::setSize(FVector2D tileMapSize)
{
	m_tileMapSize = tileMapSize;
}

FVector2D ATileMapGenerator::getSizeSetup()
{
	return m_tileMapSize;
}

void ATileMapGenerator::generateTileMap(int32 red , int32 green , int32 blue)
{
    mTileMapData = new TileMapData(m_tileMapSize);
    mTileMapData->mColorSetup.Red = red;
    mTileMapData->mColorSetup.Green = green;
    mTileMapData->mColorSetup.Blue = blue;
    mTileMapData->generateTileMapData();
    
	//Generate tile map here
	for (int i = 0; i < (int)(m_tileMapSize.X); i++)
	{
		for (int j = 0; j < (int)m_tileMapSize.Y; j++)
		{
            int32 tileColorType = (int32)(mTileMapData->getTileColorType());
			ATileBase* tileBase = spawnTile(m_tileBP, FVector2D(i, j),tileColorType); // width Index , height Index
		}
	}
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
    
    UE_LOG(LogTemp, Warning, TEXT("selected color type %d"),tileColrType);

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

