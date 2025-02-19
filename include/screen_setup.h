#pragma once

#include "raylib-cpp.hpp"

namespace rl=raylib;

#include "applicationstate.h"
#include "inputmanager.h"

class SetupScreen
{
private:
    char cursorPosition;
    int numOfPlayers;
public:
    SetupScreen();
    ~SetupScreen();

    void Draw(rl::Window& window);
    void Update(rl::Window& window, InputManager& input, ApplicationState& modifiedState);
};
