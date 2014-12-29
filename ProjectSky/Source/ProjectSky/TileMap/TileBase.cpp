// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectSky.h"
#include "TileBase.h"



ATileBase::ATileBase(const class FObjectInitializer& PCIP )
	: Super(PCIP)
{
	UE_LOG(LogTemp, Warning, TEXT("Tile base is generated"));
	USceneComponent* sceneComponent = PCIP.CreateDefaultSubobject<USceneComponent>(this, TEXT("RootCompo_Dummy"));

	this->RootComponent = sceneComponent;    
}

void ATileBase::init(TileColorType tileColortype)
{
	this->mColorType = tileColortype;
}

void ATileBase::setTileColrType(TileColorType tileColorType)
{
	this->mColorType = tileColorType;
}

TileColorType ATileBase::getTileColorType()
{
	return mColorType;
}

