#include "screen_setup.h"
#include "window_constants.h"
#include "applicationstate.h"

#include <string>

#define SETUP_OPT_SPACING 50

SetupScreen::SetupScreen() : cursorPosition(0), numOfPlayers(1) {};
SetupScreen::~SetupScreen() {}

void SetupScreen::Draw(rl::Window& window)
{
    std::string numberOfPlayersText = cursorPosition==0 ? ("> Number of Players: " + std::to_string(numOfPlayers) + " <") : ("Number of Players: " + std::to_string(numOfPlayers));
    rl::Text opt_numofplayers = rl::Text(numberOfPlayersText, 32, rl::Color::White(), ::GetFontDefault(), 3.0f);
    rl::Text opt_exit = rl::Text( (cursorPosition==1 ? "> Exit Game <" : "Exit Game"), 32, rl::Color::White(), ::GetFontDefault(), 3.0f);

    opt_numofplayers.Draw(WINDOW_WIDTH/2 - opt_numofplayers.Measure()/2, 100);
    opt_exit.Draw(WINDOW_WIDTH/2 - opt_exit.Measure()/2, 100 + SETUP_OPT_SPACING);
}

void SetupScreen::Update(rl::Window &window, InputManager& input, ApplicationState& modifiedState)
{
    if (cursorPosition == 0)
    {
        if (input.IsUiLeftPressed())
        {
            numOfPlayers--;
            if(numOfPlayers < 1) numOfPlayers = 4;
        }
        else if (input.IsUiRightPressed())
        {
            numOfPlayers++;
            if(numOfPlayers > 4) numOfPlayers = 1;
        }
    }
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
            modifiedState = ApplicationState::TITLE;
    }
    else if (input.IsUiBackPressed())
        modifiedState = ApplicationState::TITLE;
}
