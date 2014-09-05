// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "ProjectSky.h"





IMPLEMENT_PRIMARY_GAME_MODULE( ProjectSky, ProjectSky, "ProjectSky" );

void ProjectSky::StartupModule()
{
    FDefaultGameModuleImpl::StartupModule();
    
    MyUIResources.Initialize();
}

void ProjectSky::ShutdownModule()
{
    FDefaultGameModuleImpl::ShutdownModule();
    
    MyUIResources.Shutdown();
}

TSharedPtr<FSlateGameResources> ProjectSky::GetSlateGameResources()
{

    return MyUIResources.GetSlateGameResources();
}



DEFINE_LOG_CATEGORY(LogProjectSky)
 