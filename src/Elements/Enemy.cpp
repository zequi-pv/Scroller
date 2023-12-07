#include "Enemy.h"
#include <iostream>

using namespace std;
namespace game 
{
	Enemy initEnemy(Texture2D enemyTex)
	{
		Enemy enemy;
		enemy.pos.x;
		enemy.pos.y = -100.0f;
		enemy.size = { 50.0f, 50.0f };
		enemy.speed = 150.0f;
		enemy.isActive = true;
		enemy.isDead = false;
		enemy.givenPoints = false;
		enemy.pointsToGive = 100;
		enemy.texture = enemyTex;
		return enemy;
	}

	void moveEnemies(Enemy enemies[], int maxEnemies)
	{
		for (int i = 0; i < maxEnemies; i++)
		{
			if (enemies[i].isActive && !enemies[i].isDead)
			{
				//cout << enemies[i].pos.x << enemies[i].pos.y << endl;
				enemies[i].pos.y += enemies[i].speed * GetFrameTime();
			}
		}
	}

	void drawEnemies(Enemy enemies[], int maxEnemies) 
	{
		for (int i = 0; i < maxEnemies; i++)
		{
			if (enemies[i].isActive && !enemies[i].isDead)
			{
				DrawTexture(enemies[i].texture, static_cast<int>(enemies[i].pos.x), static_cast<int>(enemies[i].pos.y), RAYWHITE);
			}
		}
	}
}