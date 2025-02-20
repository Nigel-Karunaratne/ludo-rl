#pragma once

#include "ludoconfig.h"

class LudoInstance
{
private:
    LudoConfig config;
public:
    LudoInstance() : config() {};
    LudoInstance(LudoConfig config) : config(config) {};
    ~LudoInstance() {};
    inline void SetConfig(LudoConfig config) { this->config = config; };
};
