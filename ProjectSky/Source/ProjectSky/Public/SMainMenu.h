

#pragma once

#include "Slate.h"
#include "MyGameResources.h"
#include "SlateGameResources.h"

/**
 * 
 */
class PROJECTSKY_API SMainMenu : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMainMenu) : _mainHUD()
	{
    }
    
    SLATE_ARGUMENT(TWeakObjectPtr<class AMainHUD>, mainHUD);
    
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
    
private:
    
    FReply PlayGameClicked();
    
    FReply QuitGameClicked();
    
    TWeakObjectPtr<class AMainHUD> p_mainHUD;
    
    // pointer to Resource in Game Module
    
    TSharedPtr<FSlateGameResources> MyUIResources;
	
    
    
};



