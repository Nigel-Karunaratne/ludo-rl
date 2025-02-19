#pragma once

#include "raylib-cpp.hpp"

namespace rl=raylib;

#include "applicationstate.h"
#include "inputmanager.h"
#include "ludoconfig.h"

class SetupScreen
{
private:
    char cursorPosition;
    int numOfPlayers;
    bool exactNeededForGoal;
    bool rollSixWhenNoPiecesOut;
public:
    SetupScreen();
    ~SetupScreen();

    void Draw(rl::Window& window);
    void Update(rl::Window& window, InputManager& input, ApplicationState& modifiedState);

    LudoConfig GetConfiguration();
};
