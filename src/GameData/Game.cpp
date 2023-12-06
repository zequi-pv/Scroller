#include "Game.h"
#include "ScreenManager/ScreenManager.h"
#include "ScreenManager/screenGameplay.h"
#include "Elements/Enemy.h"
#include "Elements/Player.h"
#include "Utils.h"
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

    const int maxEnemies = 6;
    Player player;
    Enemy enemy;
    Enemy enemies[maxEnemies];

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

        for (int i = 0; i < maxEnemies; i++)
        {
            enemy = initEnemy();
            enemy.id = i;
            if (enemy.id == 1)
            {
                enemy.pos.x = 154.0f;
            }
            if (enemy.id == 2)
            {
                enemy.pos.x = 308.0f;
            }
            if (enemy.id == 3)
            {
                enemy.pos.x = 462.0f;
            }
            if (enemy.id == 4)
            {
                enemy.pos.x = 616.0f;
            }
            if (enemy.id == 5)
            {
                enemy.pos.x = 770.0f;
            }
            if (enemy.id == 6)
            {
                enemy.pos.x = 924.0f;
            }
            enemies[i] = enemy;
        }
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
        SetExitKey(NULL);
        if (IsKeyPressed(KEY_ESCAPE))
        {
            gameScreen = GameScreen::Menu;
        }
        movePlayer(player);
        moveEnemies(enemies, maxEnemies);
        drawGame(player, enemies, maxEnemies);
        screenCollision(player);
        if (EnemyCollision(enemies, maxEnemies))
        {
            for (int i = 0; i < maxEnemies; i++)
            {
                enemies[i].pos.y = 0 - enemies[i].size.y;
            }
        }
    }

    void close() 
    {
        CloseWindow();
    }
}