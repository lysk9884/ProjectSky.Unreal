

#include "ProjectSky.h"
#include "SMainMenu.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMainMenu::Construct(const FArguments& InArgs)
{
	MainHUD =InArgs._MainHUD;
    
    ChildSlot
    [
    SNew(SOverlay)
     + SOverlay::Slot()
     .HAlign(HAlign_Center)
     .VAlig(VAlign_Top)
     [
      SNew(STextBlock)
      .ColorAndOpacity(FLinearColor::White)
      .ShadowColorAndOpacity(FLinearColor::Black)
      .ShadowOffset(FIntPoint(-1, 1))
      .font(FSlateFontInfo("Arial", 26))
      .Text(FText::FromString("Main Menu"))
     ]
    ]
}


END_SLATE_FUNCTION_BUILD_OPTIMIZATION
