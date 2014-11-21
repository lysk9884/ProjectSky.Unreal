// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectSky.h"
#include "Utility.h"

Utility::Utility()
{
}

Utility::~Utility()
{
}

template <typename type> static FORCEINLINE type* Utility::findSelectedTypeObject(UWorld* world)
{
	for (TActorIterator<type> actorItr(world); actorItr; ++actorItr)
	{
	
		type* Object = Cast<type>(*actorItr);

		if (Object != NULL)
		{
			return Object;

		}

	}
}
