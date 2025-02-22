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
    gameInstance.DrawBoard();
    gameInstance.DrawOverlayOnState();
}

void GameScreen::Update(rl::Window& window, InputManager& input, ApplicationState& modifiedState)
{
    gameInstance.Update(window, input, modifiedState); 
}
