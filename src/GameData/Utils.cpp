#include "Utils.h"

namespace game 
{
    void screenCollision(Player& player)
    {
        if (player.pos.x + player.size.x >= GetScreenWidth())
        {
            player.pos.x = GetScreenWidth() - player.size.x;
        }
        else if (player.pos.x < 0)
        {
            player.pos.x = 0;
        }

        if (player.pos.y + player.size.y >= GetScreenHeight())
        {
            player.pos.y = GetScreenHeight() - player.size.y;
        }
        else if (player.pos.y < 0)
        {
            player.pos.y = 0;
        }
    }

    bool EnemyCollision(Enemy enemies[], int maxEnemies) 
    {
        float collision = 0;
        for (int i = 0; i < maxEnemies; i++)
        {
            collision = enemies[i].pos.y > GetScreenHeight();
        }
        return collision;
    }

    void bulletCollision(Enemy enemies[], int maxEnemies, Bullet bullets[], int maxBullets, Player& player)
    {
        for (int i = 0; i < maxBullets; i++)
        {
            for (int j = 0; j < maxEnemies; j++)
            {
                if (bullets[i].isActive && enemies[i].isActive)
                {
                    if (bullets[i].pos.x + bullets[i].size.x >= enemies[j].pos.x
                        && bullets[i].pos.x <= enemies[j].pos.x + enemies[j].size.x
                        && bullets[i].pos.y + bullets[i].size.y >= enemies[j].pos.y
                        && bullets[i].pos.y <= enemies[j].pos.y + enemies[j].size.y)
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
        }
    }

    void resetEnemy(Enemy enemies[], int maxEnemies)
    {
        for (int i = 0; i < maxEnemies; i++)
        {
            if (!enemies[i].isActive && enemies[i].isDead) 
            {
                enemies[i].isActive = true;
                enemies[i].isDead = false;
                enemies[i].givenPoints = false;
                enemies[i].pointsToGive = 100;
                enemies[i].pos.y = -100.0f;
                if (enemies[i].id == 1)
                {
                    enemies[i].pos.x = 154.0f;
                }
                if (enemies[i].id == 2)
                {
                    enemies[i].pos.x = 308.0f;
                }
                if (enemies[i].id == 3)
                {
                    enemies[i].pos.x = 462.0f;
                }
                if (enemies[i].id == 4)
                {
                    enemies[i].pos.x = 616.0f;
                }
                if (enemies[i].id == 5)
                {
                    enemies[i].pos.x = 770.0f;
                }
                if (enemies[i].id == 6)
                {
                    enemies[i].pos.x = 924.0f;
                }
            }
        }
    }

    void crashCollision(Player& player, Enemy enemies[], int maxEnemies, bool& endMatch) 
    {
        for (int i = 0; i < maxEnemies; i++)
        {
            if (player.pos.x + player.size.x >= enemies[i].pos.x
                && player.pos.x <= enemies[i].pos.x + enemies[i].size.x
                && player.pos.y + player.size.y >= enemies[i].pos.y
                && player.pos.y <= enemies[i].pos.y + enemies[i].size.y)
            {
                endMatch = true;
            }
        }
    }
}