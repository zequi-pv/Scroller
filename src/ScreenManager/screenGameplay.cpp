#include "screenGameplay.h"

namespace game
{
	void drawGame(Player player, Enemy enemies[], int maxEnemies, Parallax& parallax) 
	{
		BeginDrawing();
		ClearBackground(BLACK);

		parallax.scrollingBack -= 10.0f * GetFrameTime();
		parallax.scrollingMid -= 50.0f * GetFrameTime();
		parallax.scrollingFore -= 100.0f * GetFrameTime();

		if (parallax.scrollingBack <= -parallax.background.height * 2) parallax.scrollingBack = 0;
		if (parallax.scrollingMid <= -parallax.midground.height * 2) parallax.scrollingMid = 0;
		if (parallax.scrollingFore <= -parallax.foreground.height * 2) parallax.scrollingFore = 0;

		DrawTextureEx(parallax.background, Vector2{ 0, parallax.scrollingBack }, 0.0f, 2.0f, WHITE);
		DrawTextureEx(parallax.background, Vector2{ 0, parallax.background.height * 2 + parallax.scrollingBack }, 0.0f, 2.0f, WHITE);
		DrawTextureEx(parallax.background, Vector2{ 0, static_cast<float>((parallax.background.height * 3 + parallax.scrollingBack) + (GetScreenHeight() /*/ 4.0f*/)) }, 0.0f, 2.0f, WHITE);

		DrawTextureEx(parallax.midground, Vector2{ 400.0f, parallax.scrollingMid }, 0.0f, 2.0f, WHITE);
		DrawTextureEx(parallax.midground, Vector2{ 400.0f, parallax.midground.height * 2 + parallax.scrollingMid }, 0.0f, 2.0f, WHITE);
		DrawTextureEx(parallax.midground, Vector2{ 400.0f, static_cast<float>((parallax.midground.height * 3 + parallax.scrollingMid) + (GetScreenHeight() /*/ 4.0f*/)) }, 0.0f, 2.0f, WHITE);

		DrawTextureEx(parallax.foreground, Vector2{ 0, parallax.scrollingFore }, 0.0f, 2.0f, WHITE);
		DrawTextureEx(parallax.foreground, Vector2{ 0, static_cast<float>((parallax.foreground.height * 2 + parallax.scrollingFore)) }, 0.0f, 2.0f, WHITE);
		DrawTextureEx(parallax.foreground, Vector2{ 0, static_cast<float>((parallax.foreground.height * 3 + parallax.scrollingFore) + (GetScreenHeight() /*/ 2.91f*/)) }, 0.0f, 2.0f, WHITE);

		drawPlayer(player);
		drawEnemies(enemies, maxEnemies);
		EndDrawing();
	}

	Parallax initParallax(Texture2D background, Texture2D midground, Texture2D foreground, float scrollingBack, float scrollingMid, float scrollingFore)
	{
		Parallax parallax;
		parallax.background = background;
		parallax.midground = midground;
		parallax.foreground = foreground;
		parallax.scrollingBack = scrollingBack;
		parallax.scrollingMid = scrollingMid;
		parallax.scrollingFore = scrollingFore;
		return parallax;
	}
}