// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/**
 * 
 */
class PROJECTSKY_API Utility
{
public:
	Utility();
	~Utility();

	template <typename type> static FORCEINLINE type* findSelectedTypeObject(UWorld* world)
	{
		for (TActorIterator<type> actorItr(world); actorItr; ++actorItr)
		{

			type* Object = Cast<type>(*actorItr);

			if (Object != NULL)
			{
				return Object;

			}

		}
	};

	template <typename type> static FORCEINLINE type* SpawnBP(UWorld* TheWorld, UClass* TheBP, const FVector& Loc, const FRotator& Rot, const bool bNoCollisionFail = true , AActor* Owner = NULL, APawn* Instigator = NULL)
	{
		if (!TheWorld)
			return NULL;
		if (!TheBP)
			return NULL;

		FActorSpawnParameters SpawnInfo;
		SpawnInfo.bNoCollisionFail = bNoCollisionFail;
		SpawnInfo.Owner = Owner;
		SpawnInfo.Instigator = Instigator;
		SpawnInfo.bDeferConstruction = false;

		return TheWorld->SpawnActor<type>(TheBP, Loc, Rot, SpawnInfo);
	};
	

};
