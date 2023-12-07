#pragma once
#include "raylib.h"
#include "Player.h"

namespace game 
{
	struct Bullet
	{
		Vector2 pos;
		Vector2 size;
		Texture2D texture;
		float speed;
		bool isActive;
	};

	Bullet initBullet(Texture2D bulletTex);
	void moveBullets(Bullet bullets[], int maxBullets);
	void drawBullets(Bullet bullets[], int maxBullets);
}