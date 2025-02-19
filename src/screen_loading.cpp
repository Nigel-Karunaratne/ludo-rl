#include "screen_loading.h"
#include "window_constants.h"

#include <iostream>

LoadingScreen::LoadingScreen(SpriteManager &spriteManager, AudioManager &audioManager) : spriteManager(spriteManager), audioManager(audioManager), loadedFiles(0) {}

LoadingScreen::~LoadingScreen() {}

// TODO - just load all at once? only a few files are necessary to load... (1 spritesheet, 1 board, small amount of audio files)
void LoadingScreen::FindFilesToLoad()
{
    // FIXME - not working!
    audioFilesToLoad = rl::LoadDirectoryFiles(std::string(::GetApplicationDirectory()).append("assets\\sound"));
    textureFilesToLoad = rl::LoadDirectoryFiles(std::string(::GetApplicationDirectory()).append("assets\\sprite"));

    std::cout << std::string(::GetApplicationDirectory()).append("assets\\sound") << std::endl;

    filesToLoad = audioFilesToLoad.size() + textureFilesToLoad.size();
}

void LoadingScreen::Draw(rl::Window &window)
{
    window.DrawFPS(20,20);
    rl::Text loadingText = rl::Text( "LOADING...", 100, rl::Color::RayWhite(), ::GetFontDefault(), 3.0f);
    rl::Vector2 textSize = loadingText.MeasureEx();
    loadingText.Draw(WINDOW_WIDTH/2 - textSize.GetX()/2, WINDOW_HEIGHT/2 - textSize.GetY()/2);
}

void LoadingScreen::Update(rl::Window &window, InputManager &input, ApplicationState &modifiedState)
{
    if(textureFilesToLoad.empty() && audioFilesToLoad.empty())
    {
        modifiedState = ApplicationState::TITLE;
        return;
    }
    if(textureFilesToLoad.size() > 0) //load a texture
    {
        // spriteManager.AddTexture(textureFilesToLoad.back(),)
        // textureFilesToLoad.pop_back();
    }
    else if(audioFilesToLoad.size() > 0) //load an audio file
    {
        // audioManager.AddSound(audioFilesToLoad.back(),)
        // audioFilesToLoad.pop_back();
    }
}
