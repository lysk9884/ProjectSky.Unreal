//
//  MyGameResources.cpp
//  ProjectSky
//
//  Created by Ilseob lee on 5/9/14.
//  Copyright (c) 2014 EpicGames. All rights reserved.
//

#include "ProjectSky.h"
#include "MyGameResources.h"

void FMyUIResources::Initialize()
{
	if (!MyUIResources.IsValid())
	{
		MyUIResources = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*MyUIResources);
	}
}

TSharedPtr<FSlateGameResources> FMyUIResources::GetSlateGameResources()
{
	return MyUIResources;
}

TSharedRef<class FSlateGameResources> FMyUIResources::Create()
{
	return FSlateGameResources::New(FName("MyUIResources"), m_path, m_path);
}

/*Unregister resources/styles with Slate, cleanup, free memory*/
void FMyUIResources::Shutdown()
{
	//Unregister *MyUIResources with Slate
	FSlateStyleRegistry::UnRegisterSlateStyle(*MyUIResources);
    
	//Debugging
	ensure(MyUIResources.IsUnique());
    
	//Removes reference to resources, decrements refcount, destroys resources if refcount=0
	//Do this to all SharedPtrs on Shutdown() or SomethingSimilar() to avoid memory leak
	MyUIResources.Reset();
}
