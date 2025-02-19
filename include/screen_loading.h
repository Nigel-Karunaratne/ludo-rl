#pragma once

#include "raylib-cpp.hpp"

namespace rl=raylib;

#include "applicationstate.h"
#include "inputmanager.h"

#include "audiomanager.h"
#include "spritemanager.h"

#include <vector>
#include <string>

class LoadingScreen
{
private:
    SpriteManager& spriteManager;
    AudioManager& audioManager;

    int loadedFiles;
    int filesToLoad;

    std::vector<std::string> audioFilesToLoad;
    std::vector<std::string> textureFilesToLoad;
public:
    LoadingScreen(SpriteManager& spriteManager, AudioManager& audioManager);
    ~LoadingScreen();

    void FindFilesToLoad();

    void Draw(rl::Window& window);
    void Update(rl::Window& window, InputManager& input, ApplicationState& modifiedState);
};
