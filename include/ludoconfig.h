#pragma once

typedef struct LudoConfig
{
    int playerCount; //1-4
    bool exactNeededForGoal = true;
    bool rollSixWhenNoPiecesOut = false;
} LudoConfig;
