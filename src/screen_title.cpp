#include "screen_title.h"
#include "window_constants.h"
#include "applicationstate.h"

#define TITLE_OPT_SPACING 50

TitleScreen::TitleScreen() : cursorPosition(0) {};
TitleScreen::~TitleScreen() {}

void TitleScreen::Draw(rl::Window& window)
{
    window.DrawFPS(10,10);

    rl::Text titleText = rl::Text("LUDO",100, rl::Color::White(), ::GetFontDefault() , 27.0f);
    titleText.Draw((WINDOW_WIDTH - titleText.MeasureEx().GetX()) / 2, 140);

    rl::Text opt_start = rl::Text( (cursorPosition==0 ? "> Start Game <" : "Start Game"), 32, rl::Color::White(), ::GetFontDefault(), 3.0f);
    rl::Text opt_exit = rl::Text( (cursorPosition==1 ? "> Exit Game <" : "Exit Game"), 32, rl::Color::White(), ::GetFontDefault(), 3.0f);

    opt_start.Draw(WINDOW_WIDTH/2 - opt_start.Measure()/2, 260);
    opt_exit.Draw(WINDOW_WIDTH/2 - opt_exit.Measure()/2, 260 + TITLE_OPT_SPACING);
}

void TitleScreen::Update(rl::Window &window, InputManager& input, ApplicationState& modifiedState)
{
    if (input.IsUiUpPressed())
    {
        cursorPosition--;
        if(cursorPosition < 0)
            cursorPosition = 0;
    }
    else if (input.IsUiDownPressed())
    {
        cursorPosition++;
        if(cursorPosition > 1)
            cursorPosition = 1;
    }
    else if (input.IsUiEnterPressed())
    {
        if(cursorPosition == 0)
            modifiedState = ApplicationState::SETUP;
        else
            modifiedState = ApplicationState::QUIT;
    }
}
