#include "Game.h"
#include "ScreenManager/ScreenManager.h"
#include "ScreenManager/screenGameplay.h"
#include "Elements/Button.h"
#include "Elements/Player.h"
#include <iostream>

using namespace std;

namespace game
{
    void init();
    void mainLoop();
    void close();

    bool isGameRunning = false;
    bool exitWindow = false;

    Button buttonPlay;
    Button buttonCredits;
    Button buttonExit;

    Player player;

    GameScreen gameScreen = GameScreen::Menu;

    Vector2 size = { 200, 43 };

	void runGame()
	{
        init();
        mainLoop();
        close();
	}

    void init()
    {
        const int screenWidth = 1024;
        const int screenHeight = 768;

        InitWindow(screenWidth, screenHeight, "Scroller Prieto");

        buttonPlay = initButton(size);
        buttonCredits = initButton(size);
        buttonExit = initButton(size);

        player = initPlayer();
    }

    void mainLoop() 
    {
        while (!exitWindow)
        {
            while (!WindowShouldClose() && !isGameRunning)
            {
                ScenesSwitch(gameScreen,buttonPlay, buttonCredits, buttonExit, isGameRunning);
                exitWindow = true;
            }
        }
        
    }

    void gameLoop() 
    {
        movePlayer(player);
        drawGame(player);
    }

    void close() 
    {
        CloseWindow();
    }
}