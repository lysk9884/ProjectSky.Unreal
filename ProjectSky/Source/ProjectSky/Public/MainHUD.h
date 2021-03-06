

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
    
    UFUNCTION(BlueprintImplementableEvent , Category = "Menus|Main Menu")
    void PlayGameClicked();
    
    UFUNCTION(BlueprintImplementableEvent , Category = "Menus|Main Menu")
    void QuitGameClicked();

	



private:
    
    TSharedPtr<class SMainMenu> p_mainMenuUI;
	
};
