#pragma once

#include "ludoconfig.h"
#include "ludostate.h"

class LudoInstance
{
private:
    LudoConfig config;
    LudoState_ENUM state;
public:
    LudoInstance() : config() {};
    LudoInstance(LudoConfig config) : config(config) {};
    ~LudoInstance() {};
    inline void SetConfig(LudoConfig config) { this->config = config; };

    void UpdateShowTurnOrder(); //timer
    void UpdateInputPlayerRoll(); //use timer to show roll animation. every x frames, generate new number for dice to show
    void UpdateShowPlayerRoll(); //use timer to slow roll animation?
    void UpdateInputPlayerMove(); //highlight pieces
    void UpdateShowPlayerMove(); //use timers to show player movement

    void DrawBoard(); //draws the board
    void DrawOverlayOnState(); //draws a certain overlay, based on the game state
};
