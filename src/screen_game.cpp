#include "screen_game.h"

GameScreen::GameScreen() : config(), gameInstance(this->config)
{
}

GameScreen::GameScreen(LudoConfig config) : config(config), gameInstance(this->config)
{
}

GameScreen::~GameScreen()
{
}

void GameScreen::Draw(rl::Window& window)
{
}

void GameScreen::Update(rl::Window& window, InputManager& input, ApplicationState& modifiedState)
{
    // if not paused, update? else, update pause screen? this would mean pause screen is owned by the game?
    // in main(), call GameScreen.Draw() and THEN call PauseScreen.Draw() from there
    // gameInstance.Update(); 
}
