// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#ifndef __PROJECTSKY_H__
#define __PROJECTSKY_H__

#include "EngineMinimal.h"
#include "Engine.h"
#include <typeinfo.h>
#include "MyGameResources.h"



class ProjectSky : public FDefaultGameModuleImpl
{
public:
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/////Called when GameModule is loaded, load any resources game may need here
	void StartupModule();

	///////////////////////////////////////////////////////////////////////////////////////////////////
	/////Called when GameModule is unloaded, before shutdown, unload resources/cleanup here
	void ShutdownModule();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/////Give a handle to MyUIResources to anyone who asks
	TSharedPtr<FSlateGameResources> GetSlateGameResources();

protected:

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/////Data Structure and Interface for maintaining SlateGameResources on Game to Game basis
	FMyUIResources MyUIResources;

};


DECLARE_LOG_CATEGORY_EXTERN(LogProjectSky, Log, All);


#endif
