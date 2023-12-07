#include "Game.h"
#include "ScreenManager/ScreenManager.h"
#include "ScreenManager/screenGameplay.h"
#include "Elements/Enemy.h"
#include "Elements/Player.h"
#include "Elements/Bullet.h"
#include "Utils.h"
#include <iostream>

using namespace std;

namespace game
{
    static void init();
    static void mainLoop();
    static void close();
    void resetGame();
    void bulletScreenCollision();
    /*void resetBullets();*/

    bool isGameRunning = false;
    bool exitWindow = false;

    Button buttonPlay;
    Button buttonCredits;
    Button buttonExit;

    Parallax parallax;

    const int maxEnemies = 6;
    const int maxBullet = 500;
    Player player;
    Enemy enemy;
    Enemy enemies[maxEnemies];
    Bullet bullet;
    Bullet bullets[maxBullet];

    float scrollingBack = 0.0f;
    float scrollingMid = 0.0f;
    float scrollingFore = 0.0f;

    Texture2D backGround, midGround, foreGround, playerTex, enemyTex, bulletTex;

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

        backGround = LoadTexture("res/textures/background.png");
        midGround = LoadTexture("res/textures/midground.png");
        foreGround = LoadTexture("res/textures/foreground.png");

        playerTex = LoadTexture("res/textures/player.png");
        enemyTex = LoadTexture("res/textures/enemy.png");
        bulletTex = LoadTexture("res/textures/bullet.png");

        player = initPlayer(playerTex);

        parallax = initParallax(backGround, midGround, foreGround, scrollingBack, scrollingMid, scrollingFore);

        for (int i = 0; i < maxEnemies; i++)
        {
            enemy = initEnemy(enemyTex);
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

        for (int i = 0; i < maxBullet; i++)
        {
            bullet = initBullet(bulletTex);
            bullets[i] = bullet;
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
            resetGame();
        }
        movePlayer(player);
        moveEnemies(enemies, maxEnemies);
        /*moveBullets(bullets, maxBullet);*/
        drawGame(player, enemies, maxEnemies, parallax, bullets, maxBullet);
        //drawBullets(bullets, maxBullet);
        screenCollision(player);
        bulletScreenCollision();
        bulletCollision(enemies, maxEnemies, bullets, maxBullet, player);
        if (EnemyCollision(enemies, maxEnemies))
        {
            for (int i = 0; i < maxEnemies; i++)
            {
                enemies[i].pos.y = 0 - enemies[i].size.y;
            }
        }
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            for (int i = 0; i < maxBullet; i++)
            {
                if (!bullets[i].isActive)
                {
                    bullets[i].pos = { player.pos.x + (player.size.x - 30), player.pos.y };
                    bullets[i].isActive = true;
                }
            }
        }
        for (int i = 0; i < maxBullet; i++)
        {
            if (bullets[i].isActive)
            {
                bullets[i].pos.y -= bullets[i].speed * GetFrameTime();
            }
        }
        resetEnemy(enemies, maxEnemies);
        /*resetBullets();*/
    }

    /*void resetBullets() 
    {
        if (!bullets[maxBullet].isActive == maxBullet)
        {
            for (int i = 0; i < maxBullet; i++)
            {
                bullets[i].isActive = true;
            }
        }

        if (bullets[i].pos.y < 0)
                {
                    bullets[i].isActive = false;
                }
    }*/

    void bulletScreenCollision() 
    {
        for (int i = 0; i < maxBullet; i++)
        {
            if (bullets[i].pos.y <= 0) 
            {
                bullets[i].isActive = false;
            }
        }
    }

    

    void resetGame() 
    {
        player = initPlayer(playerTex);
        for (int i = 0; i < maxEnemies; i++)
        {
            enemy = initEnemy(enemyTex);
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

        for (int i = 0; i < maxBullet; i++)
        {
            bullet = initBullet(bulletTex);
            bullets[i] = bullet;
        }
    }

    void close() 
    {
        UnloadTexture(backGround);
        UnloadTexture(midGround); 
        UnloadTexture(foreGround);
        UnloadTexture(playerTex);
        UnloadTexture(enemyTex);
        CloseWindow();
    }
}