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
}