//
//  MyGameResources.h
//  ProjectSky
//
//  Created by Ilseob lee on 4/9/14.
//  Copyright (c) 2014 EpicGames. All rights reserved.
//

#ifndef ProjectSky_MyGameResources_h
#define ProjectSky_MyGameResources_h

#include "ProjectSky.h"
//#include "MainHUD.h"
#include "Slate.h"
#include "SlateGameResources.h"

class FMyUIResources
{
public:
    FMyUIResources() : m_path("/Game/UI") , MyUIResources(NULL)
    {
        
    };
    
    /// laod resources and register the mwith Slate
    void Initialize();
    
    /// Do this when shutting down game module
    void Shutdown();
    
    /// Reload Texture used by slate renderer
    void ReloadTextures();
    
    // give caller a pointer to our fslateGameResources
    
    TSharedPtr<FSlateGameResources> GetSlateGameResources();
    
protected:
    // create Resources
    TSharedRef<class FSlateGameResources> Create();
    
    const FString m_path;
    
    TSharedPtr<FSlateGameResources> MyUIResources;
    
};


#endif
