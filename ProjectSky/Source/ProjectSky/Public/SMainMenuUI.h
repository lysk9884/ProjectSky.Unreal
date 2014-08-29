

#pragma once
#include "Slate.h"

/**
 * 
 */
class PROJECTSKY_API SMainMenuUI : public SCompoundWidget
{

	SLATE_BEGIN_ARGS(SMainMenuUI)
    :_MenuHUD()
	{
    }
    
     SLATE_ARGUMENT(TWeakObjectPtr<class AMyHUD>, MenuHUD);
    
	SLATE_END_ARGS()
    
public:

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& args);
    
private:
    
    FReply PlayGameClicked();
    
    FReply QuitGameClicked();
    
    TWeakObjectPtr<class AMyHUD> MenuHUD;
    
};
