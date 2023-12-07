#pragma once
#include "Elements/Player.h"
#include "Elements/Enemy.h"
#include "Elements/Bullet.h"

namespace game 
{
	struct Parallax
	{
		Texture2D background;
		Texture2D midground;
		Texture2D foreground;
		float scrollingBack;
		float scrollingMid;
		float scrollingFore;
	};

	void drawGame(Player player, Enemy enemies[], int maxEnemies, Parallax& parallax, Bullet bullets[], int maxBullets);
	Parallax initParallax(Texture2D background,
	Texture2D midground,
	Texture2D foreground,
	float scrollingBack,
	float scrollingMid,
	float scrollingFore);
}