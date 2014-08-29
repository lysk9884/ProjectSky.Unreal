

#include "ProjectSky.h"
#include "MyHUD.h"
#include "SMainMenuUI.h"



AMyHUD::AMyHUD(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{

}

void AMyHUD::PostInitializeComponents()
{
    Super::PostInitializeComponents();
    
    if(GEngine && GEngine->GameViewport)
    {
        UE_LOG(LogTemp , Log, TEXT(" GEngine and game view port is not null"));
        UGameViewportClient* Viewport = GEngine->GameViewport;
        
        SAssignNew(MainMenuUI, SMainMenuUI).MenuHUD(TWeakObjectPtr<AMyHUD>(this));
        
        Viewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(MainMenuUI.ToSharedRef()));
    }

}

void AMyHUD::PlayGameClicked()
{
    UE_LOG(LogTemp, Log, TEXT("Play Game is clciekd! "));
}

void AMyHUD::QuitGameClicked()
{

}


