#pragma once
#include "Elements/Player.h"
#include "raylib.h"
#include "Elements/Enemy.h"
#include "Elements/Bullet.h"

namespace game
{
	void screenCollision(Player& player);
	bool EnemyCollision(Enemy enemies[], int maxEnemies);
	bool bulletCollision(Enemy enemies[], int i, Bullet bullets[], int j);
	void resetEnemy(Enemy enemies[], int maxEnemies);
	void crashCollision(Player& player, Enemy enemies[], int maxEnemies, bool& endMatch);
}