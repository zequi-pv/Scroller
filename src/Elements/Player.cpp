#include "Player.h"

namespace game
{
	Player initPlayer()
	{
		Player player;
		player.size = { 50.0f, 50.0f };
		player.pos = { static_cast<float>((GetScreenWidth() / 2) - (player.size.x / 2)), static_cast<float>(GetScreenHeight() - 100) };
		player.speed = 200.0f;
		return player;
	}

	void movePlayer(Player& player)
	{
		if (IsKeyDown(KEY_UP))
		{
			player.pos.y -= player.speed * GetFrameTime();
		}
		if (IsKeyDown(KEY_LEFT))
		{
			player.pos.x -= player.speed * GetFrameTime();
		}
		if (IsKeyDown(KEY_DOWN))
		{
			player.pos.y += player.speed * GetFrameTime();
		}
		if (IsKeyDown(KEY_RIGHT))
		{
			player.pos.x += player.speed * GetFrameTime();
		}
	}

	void drawPlayer(Player& player)
	{
		DrawRectangle(static_cast<int>(player.pos.x), static_cast<int>(player.pos.y), static_cast<int>(player.size.x), static_cast<int>(player.size.y), RAYWHITE);
	}
}