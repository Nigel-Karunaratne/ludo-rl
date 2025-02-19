#pragma once

typedef struct LudoConfig
{
    int playerCount; //1-4
    bool exactNeededForGoal = true; //default: true
    bool rollSixWhenNoPiecesOut = false; //default: false
} LudoConfig;
