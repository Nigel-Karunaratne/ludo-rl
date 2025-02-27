#pragma once

#include "raylib-cpp.hpp"
namespace rl=raylib;

// enum InputType
// {
//     ANY = 0,
//     P1 = 1,
//     P2 = 2,    
//     P3 = 3,
//     P4 = 4
// };

class InputManager
{
private:
    rl::Gamepad gamepad;
public:
    InputManager();
    ~InputManager();

    bool IsUiEnterPressed();
    bool IsUiBackPressed();
    bool IsUiUpPressed();
    bool IsUiDownPressed();
    bool IsUiLeftPressed();
    bool IsUiRightPressed();

    bool IsRollPressed();
};
