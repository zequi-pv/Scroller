#include "Bullet.h"
#include <iostream>

using namespace std;

namespace game
{
	Bullet initBullet(Texture2D bulletTex)
	{
		Bullet bullet;
		bullet.size = { 10.0f, 10.0f };
		bullet.speed = 500.0f;
		bullet.isActive = false;
		bullet.texture = bulletTex;
		return bullet;
	}

	void moveBullets(Bullet bullets[], int maxBullets)
	{
		for (int i = 0; i < maxBullets; i++)
		{
			if (bullets[i].isActive) 
			{
				bullets[i].pos.y -= bullets[i].speed * GetFrameTime();
			}
		}
	}

	void drawBullets(Bullet bullets[], int maxBullets)
	{
		for (int i = 0; i < maxBullets; i++)
		{
			if (bullets[i].isActive) 
			{
				DrawTexture(bullets[i].texture, static_cast<int>(bullets[i].pos.x), static_cast<int>(bullets[i].pos.y), RAYWHITE);
				//cout << bullets[i].pos.x << ", " << bullets[i].pos.y << endl;
			}
		}
	}
}