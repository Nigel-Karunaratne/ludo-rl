#pragma once

#include "raylib-cpp.hpp"

namespace rl=raylib;

#include "applicationstate.h"
#include "inputmanager.h"

#include "ludoinstance.h"
#include "ludoconfig.h"

class GameScreen
{
private:
    LudoConfig config;
    LudoInstance gameInstance;
public:
    GameScreen();
    GameScreen(LudoConfig config);
    ~GameScreen();

    void Draw(rl::Window& window);
    void Update(rl::Window& window, InputManager& input, ApplicationState& modifiedState);
    
    // constexpr GameScreen &GameScreen::operator=(const GameScreen &);
};
