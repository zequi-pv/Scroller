#include "Game.h"
#include "ScreenManager/Menu.h"

namespace game
{
    void init();
    void mainLoop();
    void gameLoop();

    bool isGameRunning = false;
    bool exitWindow = false;

	void runGame()
	{
        init();
        mainLoop();
	}

    void init()
    {
        const int screenWidth = 800;
        const int screenHeight = 450;

        InitWindow(screenWidth, screenHeight, "Scroller Prieto");

        ////SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
        ////--------------------------------------------------------------------------------------

        //// Main game loop

        //    // Update
        //    //----------------------------------------------------------------------------------
        //    // TODO: Update your variables here
        //    //----------------------------------------------------------------------------------

        //    // Draw
        //    //----------------------------------------------------------------------------------
        //    BeginDrawing();

        //    ClearBackground(RAYWHITE);

        //    DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        //    EndDrawing();
        //    //----------------------------------------------------------------------------------
        //}

        //// De-Initialization
        ////--------------------------------------------------------------------------------------
        //CloseWindow();
    }

    void mainLoop() 
    {
        while (!WindowShouldClose() && !isGameRunning)
        {
            ScenesSwitch();
            isGameRunning = true;
        }
    }

    void gameLoop() 
    {
        
    }
}