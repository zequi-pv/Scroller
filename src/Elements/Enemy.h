#pragma once
#include "raylib.h"

namespace game
{
	struct Enemy
	{
		Vector2 pos;
		Vector2 size;
		float speed;
		int id;
		bool isActive;
	};

	Enemy initEnemy();
	void moveEnemies(Enemy enemies[], int maxEnemies);
	void drawEnemies(Enemy enemies[], int maxEnemies);
}