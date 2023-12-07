#include "screenGameplay.h"

namespace game
{
	void drawGame(Player player, Enemy enemies[], int maxEnemies, Parallax& parallax, Bullet bullets[], int maxBullets, bool endMatch, Vector2 mouse, Button& buttonBack, Button& buttonRestart, GameScreen& gameScreen)
	{
		BeginDrawing();
		ClearBackground(BLACK);
		
		DrawTextureEx(parallax.background, Vector2{ 0, parallax.scrollingBack }, 0.0f, 2.0f, WHITE);
		DrawTextureEx(parallax.background, Vector2{ 0, parallax.background.height * 2 + parallax.scrollingBack }, 0.0f, 2.0f, WHITE);
		DrawTextureEx(parallax.background, Vector2{ 0, static_cast<float>((parallax.background.height * 3 + parallax.scrollingBack) + (GetScreenHeight() / 4.0f)) }, 0.0f, 2.0f, WHITE);

		DrawTextureEx(parallax.midground, Vector2{ 400.0f, parallax.scrollingMid }, 0.0f, 2.0f, WHITE);
		DrawTextureEx(parallax.midground, Vector2{ 400.0f, parallax.midground.height * 2 + parallax.scrollingMid }, 0.0f, 2.0f, WHITE);
		DrawTextureEx(parallax.midground, Vector2{ 400.0f, static_cast<float>((parallax.midground.height * 3 + parallax.scrollingMid) + (GetScreenHeight() /*/ 4.0f*/)) }, 0.0f, 2.0f, WHITE);

		DrawTextureEx(parallax.foreground, Vector2{ 400.0f, parallax.scrollingFore }, 0.0f, 2.0f, WHITE);
		DrawTextureEx(parallax.foreground, Vector2{ 400.0f, static_cast<float>((parallax.foreground.height * 2 + parallax.scrollingFore)) }, 0.0f, 2.0f, WHITE);
		DrawTextureEx(parallax.foreground, Vector2{ 400.0f, static_cast<float>((parallax.foreground.height * 3 + parallax.scrollingFore) + (GetScreenHeight() /*/ 2.91f*/)) }, 0.0f, 2.0f, WHITE);

		drawEnemies(enemies, maxEnemies);
		drawPlayer(player);

		if (!endMatch)
		{
			parallax.scrollingBack -= 10.0f * GetFrameTime();
			parallax.scrollingMid -= 50.0f * GetFrameTime();
			parallax.scrollingFore -= 100.0f * GetFrameTime();

			if (parallax.scrollingBack <= -parallax.background.height * 2) parallax.scrollingBack = 0;
			if (parallax.scrollingMid <= -parallax.midground.height * 2) parallax.scrollingMid = 0;
			if (parallax.scrollingFore <= -parallax.foreground.height * 2) parallax.scrollingFore = 0;


			DrawText("SCORE: ", 50, 100, 30, YELLOW);
			DrawText(TextFormat("%i", player.score), 170, 100, 30, YELLOW);
		}
		
		if (endMatch)
		{
			DrawText("GAME OVER", (GetScreenWidth() / 2) - 100, (GetScreenHeight() / 2) - 50, 40, YELLOW);
			DrawText("SCORE: ", (GetScreenWidth() / 2) - 150, (GetScreenHeight() / 2) + 10, 30, YELLOW);
			DrawText(TextFormat("%i", player.score), (GetScreenWidth() / 2) - 25, (GetScreenHeight() / 2) + 10, 30, YELLOW);

			buttonBack.pos.x = static_cast<float>(((GetScreenWidth() / 2) - buttonBack.size.x) - 50);
			buttonBack.pos.y = static_cast<float>((GetScreenHeight() / 2) + 40);
			drawButton(mouse, buttonBack);
			DrawText("BACK", static_cast<int>(buttonBack.pos.x) + 20, static_cast<int>(buttonBack.pos.y) + 10, 20, BLACK);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && buttonBack.isSelected)
			{
				gameScreen = GameScreen::Menu;
				resetGame();
			}

			buttonRestart.pos.x = static_cast<float>(((GetScreenWidth() / 2) + buttonRestart.size.x / 2) + 10);
			buttonRestart.pos.y = static_cast<float>((GetScreenHeight() / 2) + 40);
			drawButton(mouse, buttonRestart);
			DrawText("RESTART", static_cast<int>(buttonRestart.pos.x) + 20, static_cast<int>(buttonRestart.pos.y) + 10, 20, BLACK);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && buttonRestart.isSelected)
			{
				resetGame();
			}
		}

		for (int i = 0; i < maxBullets; i++)
		{
			if (bullets[i].isActive)
			{
				DrawTexture(bullets[i].texture, static_cast<int>(bullets[i].pos.x), static_cast<int>(bullets[i].pos.y), RAYWHITE);
			}
		}
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