

#pragma once

#include "GameFramework/HUD.h"
#include "MainHUD.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTSKY_API AMainHUD : public AHUD
{
	GENERATED_UCLASS_BODY()
    
public :
    
    virtual void PostInitializeComponents() override;
    
    UFUNCTION(BlueprintImplementableEvent , Caetegory = "Menus|Main Menu")
    void PlayGameClicked();
    
    UFUNCTION(BlueprintImplementableEvent , Caetegory = "Menus|Main Menu")
    void QuitGameClicked();

private:
    
    TsharedPtr<class SMainMenu> MainMenuUI;
	
};
