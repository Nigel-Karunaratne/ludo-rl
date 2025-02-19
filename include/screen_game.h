#pragma once

#include "raylib-cpp.hpp"

namespace rl=raylib;

#include "applicationstate.h"
#include "inputmanager.h"

#include "ludoinstance.h"

class GameScreen
{
private:
    LudoInstance gameInstance;
public:
    GameScreen();
    ~GameScreen();

    void Draw(rl::Window& window);
    void Update(rl::Window& window, InputManager& input, ApplicationState& modifiedState);
};
