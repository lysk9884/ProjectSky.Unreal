

#include "ProjectSky.h"
#include "MainHUD.h"
#include "SMainMenu.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMainMenu::Construct(const FArguments& InArgs)
{
    //get handle on Resource from game Module
    MyUIResources = FModuleManager::GetModuleChecked<ProjectSky>(FName("ProjectSky")).GetSlateGameResources();
    
    //get hand one slate brush
    
    const FSlateBrush* m_icon = MyUIResources->GetBrush(FName("Ubuntu.png"));
    
    p_mainHUD =InArgs._mainHUD;
    
    
    
    
    ChildSlot
    [
        SNew(SOverlay)
         + SOverlay::Slot()
         .HAlign(HAlign_Center)
         .VAlign(VAlign_Top)
        [
              SNew(STextBlock)
              .ColorAndOpacity(FLinearColor::White)
              .ShadowColorAndOpacity(FLinearColor::Black)
              .ShadowOffset(FIntPoint(-1, 1))
              .Font(FSlateFontInfo("Arial", 26))
              .Text(FText::FromString("Main Menu"))
         ]
         + SOverlay::Slot()
         .HAlign(HAlign_Right)
         .VAlign(VAlign_Bottom)
        [
            SNew(SVerticalBox)
         
            + SVerticalBox::Slot()
            [
                SNew(SButton)
                .Text(FText::FromString("Play Game !"))
                .OnClicked(this, &SMainMenu::PlayGameClicked)
            ]
         
            + SVerticalBox::Slot()
            [
                SNew(SButton)
                .Text(FText::FromString("Quit Game"))
                .OnClicked(this, &SMainMenu::QuitGameClicked)
             ]
        ]
     
         + SOverlay::Slot()
         .HAlign(HAlign_Center)
         .VAlign(VAlign_Center)
        [
            SNew(SVerticalBox)
             + SVerticalBox::Slot()
            [
             SNew(SImage).Image(m_icon)
            ]
        ]
     ];
}

FReply SMainMenu::PlayGameClicked()
{
    // do something for play game button clciekd
    
    p_mainHUD->PlayGameClicked();
    return FReply::Handled();
}

FReply SMainMenu::QuitGameClicked()
{
    // do something for quit button clicked
    
    p_mainHUD->QuitGameClicked();
    return FReply::Handled();
}





END_SLATE_FUNCTION_BUILD_OPTIMIZATION
