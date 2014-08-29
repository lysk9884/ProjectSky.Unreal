

#pragma once

#include "GameFramework/HUD.h"
#include "MyHUD.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTSKY_API AMyHUD : public AHUD
{
	GENERATED_UCLASS_BODY()
    
public:
    
    /**
     * Initializes the Slate UI and adds it as widget content to the game viewport.
     **/
    virtual void PostInitializeComponents() override;
    
    /**
     * Called by SMainMenu whenever the Play Game! button has been clicked.
     **/
    UFUNCTION(BlueprintImplementableEvent, Category = "Menus|Main Menu")
    void PlayGameClicked();
    
    /**
     * Called by SMainMenu whenever the Quit Game button has been clicked.
     **/
    UFUNCTION(BlueprintImplementableEvent, Category = "Menus|Main Menu")
    void QuitGameClicked();
    
private:
    /**
     * Reference to the Main Menu Slate UI.
     **/
    TSharedPtr<class SMainMenuUI> MainMenuUI;

	
	
};
