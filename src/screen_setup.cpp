#include "screen_setup.h"
#include "window_constants.h"
#include "applicationstate.h"

#include <string>

#define SETUP_OPT_SPACING 50

const std::string BoolToString(bool value);

SetupScreen::SetupScreen() : cursorPosition(0), numOfPlayers(1), exactNeededForGoal(true), rollSixWhenNoPiecesOut(false) {};
SetupScreen::~SetupScreen() {}

void SetupScreen::Draw(rl::Window& window)
{
    std::string numberOfPlayersText = cursorPosition==0 ? ("> Number of Players: " + std::to_string(numOfPlayers) + " <") : ("Number of Players: " + std::to_string(numOfPlayers));
    rl::Text opt_numofplayers = rl::Text(numberOfPlayersText, 32, rl::Color::White(), ::GetFontDefault(), 3.0f);

    std::string exactNeededForGoalText = cursorPosition==1 ? ("> Exact roll needed for goal: " + BoolToString(exactNeededForGoal) + " <") : ("Exact roll needed for goal: " + BoolToString(exactNeededForGoal));
    rl::Text opt_exactNeededForGoalText = rl::Text(exactNeededForGoalText, 32, rl::Color::White(), ::GetFontDefault(), 3.0f);

    std::string rollSixWhenNoPiecesOutText = cursorPosition==2 ? ("> Roll 6 when no pieces out: " + BoolToString(rollSixWhenNoPiecesOut) + " <") : ("Roll 6 when no pieces out: " + BoolToString(rollSixWhenNoPiecesOut));
    rl::Text opt_rollSixWhenNoPiecesOutText = rl::Text(rollSixWhenNoPiecesOutText, 32, rl::Color::White(), ::GetFontDefault(), 3.0f);

    rl::Text opt_start = rl::Text( (cursorPosition==3 ? "> Start Game <" : "Start Game"), 32, rl::Color::White(), ::GetFontDefault(), 3.0f);

    rl::Text opt_exit = rl::Text( (cursorPosition==4 ? "> Back <" : "Back"), 32, rl::Color::White(), ::GetFontDefault(), 3.0f);

    opt_numofplayers.Draw(WINDOW_WIDTH/2 - opt_numofplayers.Measure()/2, 100);
    opt_exactNeededForGoalText.Draw(WINDOW_WIDTH/2 - opt_exactNeededForGoalText.Measure()/2, 100 + SETUP_OPT_SPACING);
    opt_rollSixWhenNoPiecesOutText.Draw(WINDOW_WIDTH/2 - opt_rollSixWhenNoPiecesOutText.Measure()/2, 100 + 2 * SETUP_OPT_SPACING);
    opt_start.Draw(WINDOW_WIDTH/2 - opt_start.Measure()/2, 100 + 3 * SETUP_OPT_SPACING);
    opt_exit.Draw(WINDOW_WIDTH/2 - opt_exit.Measure()/2, 100 + 4 * SETUP_OPT_SPACING);
}

void SetupScreen::Update(rl::Window &window, InputManager& input, ApplicationState& modifiedState)
{
    if (input.IsUiUpPressed())
    {
        cursorPosition--;
        if(cursorPosition < 0)
            cursorPosition = 4;
    }
    else if (input.IsUiDownPressed())
    {
        cursorPosition++;
        if(cursorPosition > 4)
            cursorPosition = 0;
    }

    if (input.IsUiLeftPressed())
    {
        switch(cursorPosition)
        {
            case 0:
                numOfPlayers--;
                if(numOfPlayers < 1) numOfPlayers = 4;
                break;
            case 1:
                exactNeededForGoal = !exactNeededForGoal;
                break;
            case 2:
                rollSixWhenNoPiecesOut = !rollSixWhenNoPiecesOut;
                break;
        }
    }
    if (input.IsUiRightPressed())
    {
        switch(cursorPosition)
        {
            case 0:
                numOfPlayers++;
                if(numOfPlayers > 4) numOfPlayers = 1;
                break;
            case 1:
                exactNeededForGoal = !exactNeededForGoal;
                break;
            case 2:
                rollSixWhenNoPiecesOut = !rollSixWhenNoPiecesOut;
                break;
        }
    }
    else if (input.IsUiEnterPressed())
    {
        switch(cursorPosition)
        {
            case 0:
                numOfPlayers++;
                if(numOfPlayers > 4) numOfPlayers = 1;
                break;
            case 1:
                exactNeededForGoal = !exactNeededForGoal;
                break;
            case 2:
                rollSixWhenNoPiecesOut = !rollSixWhenNoPiecesOut;
                break;
            case 3:
                modifiedState = ApplicationState::GAME;
                break;
            case 4:
                modifiedState = ApplicationState::TITLE;
                break;
        }
    }
    else if (input.IsUiBackPressed())
        modifiedState = ApplicationState::TITLE;
}

LudoConfig SetupScreen::GetConfiguration()
{
    LudoConfig returnValue;
    returnValue.playerCount = this->numOfPlayers;
    returnValue.exactNeededForGoal = this->exactNeededForGoal;
    returnValue.rollSixWhenNoPiecesOut = this->exactNeededForGoal;
    return returnValue;
}

inline const std::string BoolToString(bool value)
{
  return value ? "True" : "False";
}
