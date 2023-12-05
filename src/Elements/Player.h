#pragma once
#include "raylib.h"

namespace game
{
	struct Player
	{
		Vector2 pos;
		Vector2 size;
		float speed;
	};

	Player initPlayer();
	void movePlayer(Player& player);
	void drawPlayer(Player& player);
}