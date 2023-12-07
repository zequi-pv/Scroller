#pragma once
#include "Elements/Player.h"
#include "Elements/Enemy.h"
#include "Elements/Bullet.h"
#include "Elements/Button.h"
#include "GameData/Game.h"

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

	void drawGame(Player player, Enemy enemies[], int maxEnemies, Parallax& parallax, Bullet bullets[], int maxBullets, bool endMatch, Vector2 mouse, Button& buttonBack, Button& buttonRestart, GameScreen& gameScreen);
	Parallax initParallax(Texture2D background,
	Texture2D midground,
	Texture2D foreground,
	float scrollingBack,
	float scrollingMid,
	float scrollingFore);
}