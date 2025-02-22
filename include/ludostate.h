#pragma once

#include "raylib-cpp.hpp"
#include "inputmanager.h"
#include "applicationstate.h"
#include "ludoinstance.h"

class LudoState
{
public:
    virtual ~LudoState();

    // Returns nullptr if no change. If change, it creates a NEW object (must delete the old one!)
    virtual LudoState* Update(rl::Window& window, InputManager& input, ApplicationState& modifiedState, LudoInstance& instance) = 0;
};

class ShowTurnOrder : public LudoState
{
private:
    float timer;
public:
    ShowTurnOrder() : timer(0) {};
    virtual LudoState* Update(rl::Window& window, InputManager& input, ApplicationState& modifiedState, LudoInstance& instance)
    {
        timer += window.GetFrameTime();
        if(timer > 2.0)
            return new InputPlayerRoll();
        return nullptr;
    };
};

class InputPlayerRoll : public LudoState
{
public:
    InputPlayerRoll() {};
    virtual LudoState* Update(rl::Window& window, InputManager& input, ApplicationState& modifiedState, LudoInstance& instance)
    {
        
    };
};

class ShowPlayerRoll : public LudoState
{
public:
    ShowPlayerRoll() {};
    virtual LudoState* Update(rl::Window& window, InputManager& input, ApplicationState& modifiedState, LudoInstance& instance);
};

class InputPlayerMove : public LudoState
{
public:
    InputPlayerMove() {};
    virtual LudoState* Update(rl::Window& window, InputManager& input, ApplicationState& modifiedState, LudoInstance& instance);
};

class ShowPlayerMove : public LudoState
{
public:
    ShowPlayerMove() {};
    virtual LudoState* Update(rl::Window& window, InputManager& input, ApplicationState& modifiedState, LudoInstance& instance);
};
