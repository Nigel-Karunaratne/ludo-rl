#pragma once

#include "raylib-cpp.hpp"

namespace rl=raylib;

#include "applicationstate.h"
#include "inputmanager.h"

class TitleScreen
{
private:
    char cursorPosition;
public:
    TitleScreen();
    ~TitleScreen();

    void Draw(rl::Window& window);
    void Update(rl::Window& window, InputManager& input, ApplicationState& modifiedState);
};
