#include "inputmanager.h"

InputManager::InputManager() : gamepad(0)
{
}

InputManager::~InputManager()
{
}

bool InputManager::IsUiEnterPressed()
{
    return rl::Keyboard::IsKeyPressed(KeyboardKey::KEY_ENTER) || rl::Keyboard::IsKeyPressed(KeyboardKey::KEY_SPACE) || gamepad.IsButtonPressed(GAMEPAD_BUTTON_RIGHT_FACE_DOWN);
}

bool InputManager::IsUiBackPressed()
{
    return rl::Keyboard::IsKeyPressed(KeyboardKey::KEY_ESCAPE);
}

bool InputManager::IsUiUpPressed()
{
    return rl::Keyboard::IsKeyPressed(KeyboardKey::KEY_UP) || gamepad.IsButtonPressed(GAMEPAD_BUTTON_LEFT_FACE_UP);
}

bool InputManager::IsUiDownPressed()
{
    return rl::Keyboard::IsKeyPressed(KeyboardKey::KEY_DOWN) || gamepad.IsButtonPressed(GAMEPAD_BUTTON_LEFT_FACE_DOWN);
}

bool InputManager::IsUiLeftPressed()
{
    return rl::Keyboard::IsKeyPressed(KeyboardKey::KEY_LEFT) || gamepad.IsButtonPressed(GAMEPAD_BUTTON_LEFT_FACE_LEFT);
}

bool InputManager::IsUiRightPressed()
{
    return rl::Keyboard::IsKeyPressed(KeyboardKey::KEY_RIGHT) || gamepad.IsButtonPressed(GAMEPAD_BUTTON_LEFT_FACE_RIGHT);
}

bool InputManager::IsRollPressed()
{
    return rl::Keyboard::IsKeyPressed(KeyboardKey::KEY_SPACE) || rl::Keyboard::IsKeyPressed(KeyboardKey::KEY_ENTER) || gamepad.IsButtonPressed(GAMEPAD_BUTTON_RIGHT_FACE_DOWN);
}
