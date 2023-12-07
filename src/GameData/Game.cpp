#include "Game.h"
#include "ScreenManager/ScreenManager.h"
#include "ScreenManager/screenGameplay.h"
#include "ScreenManager/screenCredits.h"
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
    void bulletScreenCollision();
    void resetMusic(Music& music);

    bool isGameRunning = false;
    bool exitWindow = false;
    bool endMatch = false;

    Button buttonPlay, buttonCredits, buttonExit, buttonBack, buttonRestart, buttonCreditsOne, buttonCreditsTwo, buttonCreditsThree, buttonCreditsFour;

    ButtonCredits buttonCredit;

    Music gameplayMusic;

    Sound shootS;

    Parallax parallax;

    const int maxEnemies = 6;
    const int maxBullet = 1000;
    Player player;
    Enemy enemy;
    Enemy enemies[maxEnemies];
    Bullet bullet;
    Bullet bullets[maxBullet];

    float scrollingBack = 0.0f;
    float scrollingMid = 0.0f;
    float scrollingFore = 0.0f;

    Texture2D backGround, midGround, foreGround, playerTex, enemyTex, bulletTex, backGroundMenu;

    GameScreen gameScreen = GameScreen::Menu;

    Vector2 sizeOne, sizeTwo, sizeThree, sizeFour;
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
        InitAudioDevice();
        buttonPlay = initButton(size);
        buttonCredits = initButton(size);
        buttonExit = initButton(size);
        buttonBack = initButton(size);
        buttonRestart = initButton(size);

        sizeOne = { 300, 43 };
        sizeTwo = { 900, 43 };
        sizeThree = { 550, 43 };
        sizeFour = { 650, 43 };

        buttonCreditsOne = initButton(sizeOne);
        buttonCreditsTwo = initButton(sizeTwo);
        buttonCreditsThree = initButton(sizeThree);
        buttonCreditsFour = initButton(sizeFour);

        buttonCredit = initButtonCredits(buttonCreditsOne, buttonCreditsTwo, buttonCreditsThree, buttonCreditsFour);

        gameplayMusic = LoadMusicStream("res/audio/gamePlayMusic.wav");

        shootS = LoadSound("res/audio/Shoot.wav");

        backGround = LoadTexture("res/textures/background.png");
        midGround = LoadTexture("res/textures/midground.png");
        foreGround = LoadTexture("res/textures/foreground.png");

        backGroundMenu = LoadTexture("res/textures/backgroundMenu.png");

        playerTex = LoadTexture("res/textures/player.png");
        enemyTex = LoadTexture("res/textures/enemy.png");
        bulletTex = LoadTexture("res/textures/bullet.png");

        player = initPlayer(playerTex);

        parallax = initParallax(backGround, midGround, foreGround, scrollingBack, scrollingMid, scrollingFore);

        PlayMusicStream(gameplayMusic);
        SetMusicVolume(gameplayMusic, 0.5f);

        for (int i = 0; i < maxEnemies; i++)
        {
            enemy = initEnemy(enemyTex);
            enemy.id = i;
            if (enemy.id == 0)
            {
                enemy.pos.x = 154.0f;
            }
            if (enemy.id == 1)
            {
                enemy.pos.x = 308.0f;
            }
            if (enemy.id == 2)
            {
                enemy.pos.x = 462.0f;
            }
            if (enemy.id == 3)
            {
                enemy.pos.x = 616.0f;
            }
            if (enemy.id == 4)
            {
                enemy.pos.x = 770.0f;
            }
            if (enemy.id == 5)
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
                ScenesSwitch(gameScreen,buttonPlay, buttonCredits, buttonExit, isGameRunning, backGroundMenu, buttonCredit, buttonBack);
                exitWindow = true;
            }
        }
        
    }

    void gameLoop(Vector2 mouse)
    {
        SetExitKey(NULL);
        if (IsKeyPressed(KEY_ESCAPE))
        {
            gameScreen = GameScreen::Menu;
            resetGame();
        }
        if (!endMatch)
        {
            UpdateMusicStream(gameplayMusic);
            movePlayer(player);
            moveEnemies(enemies, maxEnemies);
            for (int i = 0; i < maxBullet; i++)
            {
                for (int j = 0; j < maxEnemies; j++)
                {
                    if (bulletCollision(enemies, i, bullets, j))
                    {
                        bullets[i].isActive = false;
                        enemies[j].isActive = false;
                        enemies[j].isDead = true;
                        player.score += enemies[j].pointsToGive;
                        enemies[j].givenPoints = true;

                        if (enemies[j].givenPoints)
                        {
                            enemies[j].pointsToGive = 0;
                        }
                    } 

                }
            }
            moveBullets(bullets, maxBullet);
            drawGame(player, enemies, maxEnemies, parallax, bullets, maxBullet, endMatch, mouse, buttonBack, buttonRestart, gameScreen );

            screenCollision(player);
            bulletScreenCollision();
            if (EnemyCollision(enemies, maxEnemies))
            {
                for (int i = 0; i < maxEnemies; i++)
                {
                    enemies[i].pos.y = 0 - enemies[i].size.y;
                }
            }
            if (IsKeyPressed(KEY_SPACE))
            {
                for (int i = 0; i < maxBullet; i++)
                {
                    PlaySound(shootS);
                    if (!bullets[i].isActive)
                    {
                        bullets[i].pos = { player.pos.x + (player.size.x - 30), player.pos.y };
                        bullets[i].isActive = true;
                    }
                }
            }
            /*for (int i = 0; i < maxBullet; i++)
            {
                cout << bullets[i].isActive << endl;
            }*/
            crashCollision(player, enemies, maxEnemies, endMatch);

            resetEnemy(enemies, maxEnemies);
        }
        else
        {
            drawGame(player, enemies, maxEnemies, parallax, bullets, maxBullet, endMatch, mouse, buttonBack, buttonRestart, gameScreen);
            
        }
    }

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

    void resetMusic(Music& music) 
    {
        StopMusicStream(music);
        PlayMusicStream(music);
    }

    void resetGame() 
    {
        resetMusic(gameplayMusic);
        endMatch = false;
        player = initPlayer(playerTex);
        for (int i = 0; i < maxEnemies; i++)
        {
            enemy = initEnemy(enemyTex);
            enemy.id = i;
            if (enemy.id == 0)
            {
                enemy.pos.x = 154.0f;
            }
            if (enemy.id == 1)
            {
                enemy.pos.x = 308.0f;
            }
            if (enemy.id == 2)
            {
                enemy.pos.x = 462.0f;
            }
            if (enemy.id == 3)
            {
                enemy.pos.x = 616.0f;
            }
            if (enemy.id == 4)
            {
                enemy.pos.x = 770.0f;
            }
            if (enemy.id == 5)
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
        UnloadMusicStream(gameplayMusic);
        UnloadSound(shootS);
        UnloadTexture(backGround);
        UnloadTexture(midGround); 
        UnloadTexture(foreGround);
        UnloadTexture(playerTex);
        UnloadTexture(enemyTex);
        UnloadTexture(bulletTex);
        CloseWindow();
    }
}