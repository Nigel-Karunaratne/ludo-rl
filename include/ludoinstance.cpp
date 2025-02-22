#include "ludoinstance.h"

LudoInstance::LudoInstance() : LudoInstance((LudoConfig){}) {}

LudoInstance::LudoInstance(LudoConfig config) : config(config)
{
    current_state = new ShowTurnOrder();
};

void LudoInstance::Update(rl::Window &window, InputManager &input, ApplicationState &modifiedState)
{
    LudoState* new_state = current_state->Update(window, input, modifiedState, *this);
    if(new_state != nullptr)
    {
        delete current_state;
        current_state = new_state;
    }
}
