#pragma once
#include "raylib.h"

namespace game
{
	struct Enemy
	{
		Vector2 pos;
		Vector2 size;
		bool isActive;

		Enemy initEnemy();
	};
}