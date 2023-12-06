#include "Enemy.h"

namespace game 
{
	Enemy initEnemy()
	{
		Enemy enemy;
		enemy.pos.x;
		enemy.pos.y = -100.0f;
		enemy.size = { 50.0f, 50.0f };
		enemy.speed = 150.0f;
		enemy.isActive = true;
		return enemy;
	}

	void moveEnemies(Enemy enemies[], int maxEnemies)
	{
		for (int i = 0; i < maxEnemies; i++)
		{
			enemies[i].pos.y += enemies[i].speed * GetFrameTime();
		}
	}

	void drawEnemies(Enemy enemies[], int maxEnemies) 
	{
		for (int i = 0; i < maxEnemies; i++)
		{
			if (enemies[i].isActive)
			{
				DrawRectangle(static_cast<int>(enemies[i].pos.x), static_cast<int>(enemies[i].pos.y), static_cast<int>(enemies[i].size.x), static_cast<int>(enemies[i].size.y), RAYWHITE);
			}
		}
	}
}