

#include "ProjectSky.h"
#include "MainHUD.h"
#include "SMainMenu.h"




AMainHUD::AMainHUD(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
}



void AMainHUD::PostInitializeComponents()
{
    Super::PostInitializeComponents();
	
    
    if(GEngine && GEngine->GameViewport)
    {
        UGameViewportClient* viewPort = GEngine->GameViewport;
        
        SAssignNew(p_mainMenuUI, SMainMenu).mainHUD(TWeakObjectPtr<AMainHUD>(this));
        
        viewPort->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent((p_mainMenuUI.ToSharedRef())));
        
        
        
    }
    
  
    
}








