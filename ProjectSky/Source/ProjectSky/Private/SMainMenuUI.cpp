

#include "ProjectSky.h"
#include "SMainMenuUI.h"
#include "MyHUD.h"




void SMainMenuUI::Construct(const FArguments& args)
{
	MenuHUD = args._MenuHUD;
    
    ChildSlot
    [
     SNew(SOverlay)
        + SOverlay::Slot()
        .HAlign(HAlign_Center)
        .VAlign(VAlign_Top)
                            [
                                SNew(STextBlock)
                                .ColorAndOpacity(FLinearColor::White)
                                .ShadowOffset(FIntPoint(-1, 1))
                                .Font(FSlateFontInfo("Arial", 26))
                                .Text(FText::FromString("Main Menu"))
                            ]
         +SOverlay::Slot()
         .HAlign(HAlign_Right)
         .VAlign(VAlign_Bottom)
                            [
                              SNew(SVerticalBox)
                              + SVerticalBox::Slot()
                              [
                                SNew(SButton)
                                .Text(FText::FromString("Play Game!"))
                               .OnClicked(this, &SMainMenuUI::PlayGameClicked)
                               ]
                              + SVerticalBox::Slot()
                              [
                               SNew(SButton)
                               .Text(FText::FromString("Quit Game"))
                               .OnClicked(this, &SMainMenuUI::QuitGameClicked)
                               ]
                            ]
//         +SOverlay::Slot()
//        .HAlign(HAlign_Center)
//        .VAlign(VAlign_Center)
//                            [
//                                SNew(SHorizontalBox)
//                             + SHorizontalBox::slot()
//                             [
//                                SNew(SBox).
//                             ]
//                            ]
    ];
}



FReply SMainMenuUI::PlayGameClicked()
{
    MenuHUD->PlayGameClicked();
    return FReply::Handled();
}

FReply SMainMenuUI::QuitGameClicked()
{
    MenuHUD->QuitGameClicked();
    return FReply::Handled();

}

