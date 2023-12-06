#pragma once
#include "raylib.h"

namespace game
{
	struct Player
	{
		Vector2 pos;
		Vector2 size;
		float speed;
		Texture2D texture;
	};

	Player initPlayer(Texture2D playerTex);
	void movePlayer(Player& player);
	void drawPlayer(Player& player);
}