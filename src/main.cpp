#include "raylib-cpp.hpp"

#include "board.h"
#include "applicationstate.h"

#include "window_constants.h"
#include "screen_title.h"
#include "screen_setup.h"
#include "screen_game.h"

#include "inputmanager.h"

#include <iostream>

namespace rl=raylib;

#define UNUSED(expr) do {(void)(expr);} while (0)
#define MIN(a, b) ((a)<(b) ? (a) : (b))
#define MAX(a, b) ((a)>(b) ? (a) : (b))

int main(int argc, char* argv[])
{
    UNUSED(argc);
    UNUSED(argv);
    ApplicationState applicationState = ApplicationState::TITLE;

    rl::Window window(WINDOW_WIDTH, WINDOW_HEIGHT, "ludo-rl", FLAG_WINDOW_RESIZABLE);
    window.SetTargetFPS(60);
    // window.SetExitKey(KeyboardKey::KEY_NULL);
    rl::RenderTexture2D targetTexture = rl::RenderTexture2D(WINDOW_WIDTH, WINDOW_HEIGHT);
    targetTexture.GetTexture().SetFilter(TextureFilter::TEXTURE_FILTER_POINT);
    int windowScale = MIN((float)GetScreenWidth()/WINDOW_WIDTH, (float)GetScreenHeight()/WINDOW_HEIGHT);

    InputManager input = InputManager();

    // TODO - abstract to Screen abstract class w/ virtual voids Draw and Update? can replace these w/ smart pointers
    // Actually, see how the game screen class functions. May need to inherit pause screen from it!
    TitleScreen titleScreen = TitleScreen();
    SetupScreen setupScreen = SetupScreen();
    GameScreen gameScreen;
    

    while(!window.ShouldClose() && applicationState != ApplicationState::QUIT)
    {
        windowScale = MIN((float)GetScreenWidth()/WINDOW_WIDTH, (float)GetScreenHeight()/WINDOW_HEIGHT);
        // Update

        // place pieces on board
        // determine turn order (store in gameboard)
        // create turn for first player in order

        ApplicationState newState = ApplicationState::STATE_EMPTY;
        switch (applicationState)
        {
        case ApplicationState::LOADING:
            // UpdateLoading();
            break;
        case ApplicationState::TITLE:
            titleScreen.Update(window, input, newState);
            break;
        case ApplicationState::SETUP:
            setupScreen.Update(window, input, newState);
            break;
        case ApplicationState::GAME:
            gameScreen.Update(window, input, newState);
        default:
            break;
        }

        // Change State if necessary (can setup other things depending on state change)
        if(newState != ApplicationState::STATE_EMPTY)
        {
            if(applicationState == ApplicationState::SETUP && newState == ApplicationState::GAME)
            {
                // Create LudoInstance and pass in configuration?
            }
            
            applicationState = newState;
        }

        // Draw
        targetTexture.BeginMode();
            window.ClearBackground(rl::Color::Black());
            switch (applicationState)
            {
            case ApplicationState::LOADING:
                break;
            case ApplicationState::TITLE:
                titleScreen.Draw(window);
                break;
            case ApplicationState::SETUP:
                setupScreen.Draw(window);
                break;
            
            default:
                break;
            }
        targetTexture.EndMode();

        //Draw framebuffer texture to Window (see raylib example core_window_letterbox.c)
        window.BeginDrawing();
            window.ClearBackground(rl::Color::Black());
            targetTexture.GetTexture().Draw(rl::Rectangle(0.0f, 0.0f, (float)targetTexture.GetTexture().GetWidth(), (float)-targetTexture.GetTexture().GetHeight()),
                                            rl::Rectangle((window.GetWidth() - ((float)WINDOW_WIDTH * windowScale))*0.5f, (window.GetHeight() - ((float)WINDOW_HEIGHT * windowScale)) * 0.5f,
                                            (float)WINDOW_WIDTH * windowScale, (float)WINDOW_HEIGHT * windowScale), rl::Vector2::Zero(), 0, rl::Color::White());
        window.EndDrawing();
    }

    window.Close();
    return 0;
}
