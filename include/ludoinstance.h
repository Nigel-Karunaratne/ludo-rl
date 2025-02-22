#pragma once

#include "ludoconfig.h"
#include "ludostate.h"

#include <vector>

class LudoInstance
{
private:
    LudoConfig config;
    LudoState* current_state;
public:
    LudoInstance();
    LudoInstance(LudoConfig config);
    ~LudoInstance() {};
    
    // void UpdateShowTurnOrder();   //timer
    // void UpdateInputPlayerRoll(); //use timer to show roll animation. every x frames, generate new number for dice to show
    // void UpdateShowPlayerRoll();  //use timer to slow roll animation?
    // void UpdateInputPlayerMove(); //highlight pieces
    // void UpdateShowPlayerMove();  //use timers to show player movement
    
    void DrawBoard(); //draws the board
    void DrawOverlayOnState(); //draws a certain overlay, based on the game state
    
    void Update(rl::Window& window, InputManager& input, ApplicationState& modifiedState);
    
    inline void SetConfig(LudoConfig config) { this->config = config; };
    const LudoConfig& GetConfig() { return config; };
};
