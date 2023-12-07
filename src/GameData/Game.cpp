#include "Game.h"
#include "ScreenManager/ScreenManager.h"
#include "ScreenManager/screenGameplay.h"
#include "ScreenManager/screenCredits.h"
#include "Elements/Enemy.h"
#include "Elements/Player.h"
#include "Elements/Bullet.h"
#include "Utils.h"

namespace game
{
    static void init();
    static void mainLoop();
    static void close();
    void bulletScreenCollision();
    void resetMusic(Music& music);
    /*void resetBullets();*/

    bool isGameRunning = false;
    bool exitWindow = false;
    bool endMatch = false;

    Button buttonPlay, buttonCredits, buttonExit, buttonBack, buttonRestart, buttonCreditsOne, buttonCreditsTwo, buttonCreditsThree, buttonCreditsFour;

    ButtonCredits buttonCredit;

    Music menuMusic;

    Sound shootS;

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

    Texture2D backGround, midGround, foreGround, playerTex, enemyTex, bulletTex, backGroundMenu;

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
        InitAudioDevice();
        buttonPlay = initButton(size);
        buttonCredits = initButton(size);
        buttonExit = initButton(size);
        buttonBack = initButton(size);
        buttonRestart = initButton(size);

        buttonCredit = initButtonCredits(buttonCreditsOne, buttonCreditsTwo, buttonCreditsThree, buttonCreditsFour);

        menuMusic = LoadMusicStream("res/audio/menuMusic.wav");

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

        PlayMusicStream(menuMusic);
        SetMusicVolume(menuMusic, 0.5f);

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
                ScenesSwitch(gameScreen,buttonPlay, buttonCredits, buttonExit, isGameRunning, backGroundMenu, menuMusic, buttonCredit, buttonBack);
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
            movePlayer(player);
            moveEnemies(enemies, maxEnemies);
            moveBullets(bullets, maxBullet);
            
            drawGame(player, enemies, maxEnemies, parallax, bullets, maxBullet, endMatch, mouse, buttonBack, buttonRestart, gameScreen );

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
            
            crashCollision(player, enemies, maxEnemies, endMatch);

            resetEnemy(enemies, maxEnemies);
        }
        else
        {
            drawGame(player, enemies, maxEnemies, parallax, bullets, maxBullet, endMatch, mouse, buttonBack, buttonRestart, gameScreen);
            
        }
        
        
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

    void resetMusic(Music& music) 
    {
        StopMusicStream(music);
        PlayMusicStream(music);
    }

    void resetGame() 
    {
        resetMusic(menuMusic);
        endMatch = false;
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