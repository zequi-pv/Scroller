#pragma once
#include "Elements/Player.h"
#include "raylib.h"
#include "Elements/Enemy.h"
#include "Elements/Bullet.h"

namespace game
{
	void screenCollision(Player& player);
	bool EnemyCollision(Enemy enemies[], int maxEnemies);
	void bulletCollision(Enemy enemies[], int maxEnemies, Bullet bullets[], int maxBullets, Player& player);
	void resetEnemy(Enemy enemies[], int maxEnemies);
}