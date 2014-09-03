

#pragma once

#include "Slate.h"
/**
 * 
 */
class PROJECTSKY_API SMainMenu : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMainMenu) :_MainHUD()
	{
    }
    
    SLATE_ARGUMENT(TWeakObjectPtr<class AMainHUD>, MainHUD);
    
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
    
private:
    
    FReply PlayGameClicked();
    
    FReply QuitGameClicked();
    
    TWeakObjectPtr<class AMainHUD> MainHUD;
};
