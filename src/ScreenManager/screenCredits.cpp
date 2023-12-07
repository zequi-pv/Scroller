#include "screenCredits.h"

namespace game 
{
	ButtonCredits initButtonCredits(Button buttonOne, Button buttonTwo, Button buttonThree, Button buttonFour)
	{
		ButtonCredits buttonCredits;
		buttonCredits.buttonOne = buttonOne;
		buttonCredits.buttonTwo = buttonTwo;
		buttonCredits.buttonThree = buttonThree;
		buttonCredits.buttonFour = buttonFour;
		return buttonCredits;
	}

	void drawCredits(Vector2 mouse, ButtonCredits buttonCredits, Button buttonBack, GameScreen& gameScreen, Texture2D backGroundMenu)
	{
		BeginDrawing();
		ClearBackground(BLACK);
		SetExitKey(NULL);
		if (IsKeyPressed(KEY_ESCAPE))
		{
			gameScreen = GameScreen::Menu;
		}

		DrawTexture(backGroundMenu, 0, 0, RAYWHITE);

		DrawText("Programming by Ezequiel Prieto", 200, (GetScreenHeight() / 2) - 300, 20, YELLOW);
		DrawText("Planes and bullet assets by Ezequiel Prieto", 200, (GetScreenHeight() / 2) - 250, 20, YELLOW);
		DrawText("Parallax background assets by Free Game Assets", 200, (GetScreenHeight() / 2) - 150, 20, YELLOW);
		DrawText("Shoot sound by SoundByDane", 200, (GetScreenHeight() / 2) - 50, 20, YELLOW);
		DrawText("Menu music by DanzMacabre", 200, (GetScreenHeight() / 2) + 50, 20, YELLOW);
		buttonCredits;

		buttonCredits.buttonOne.pos.x = static_cast<float>(100);
		buttonCredits.buttonOne.pos.y = static_cast<float>((GetScreenHeight() / 2) - 200);
		drawButton(mouse, buttonCredits.buttonOne);
		DrawText("https://rayder01.itch.io", static_cast<int>(buttonCredits.buttonOne.pos.x) + 20, static_cast<int>(buttonCredits.buttonOne.pos.y) + 10, 20, BLACK);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && buttonCredits.buttonOne.isSelected)
		{
			OpenURL("https://rayder01.itch.io");
		}

		buttonCredits.buttonTwo.pos.x = static_cast<float>(100);
		buttonCredits.buttonTwo.pos.y = static_cast<float>((GetScreenHeight() / 2) - 100);
		drawButton(mouse, buttonCredits.buttonTwo);
		DrawText("https://free-game-assets.itch.io/free-sky-with-clouds-background-pixel-art-set", static_cast<int>(buttonCredits.buttonTwo.pos.x) + 20, static_cast<int>(buttonCredits.buttonTwo.pos.y) + 10, 20, BLACK);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && buttonCredits.buttonTwo.isSelected)
		{
			OpenURL("https://free-game-assets.itch.io/free-sky-with-clouds-background-pixel-art-set");
		}

		buttonCredits.buttonThree.pos.x = static_cast<float>(100);
		buttonCredits.buttonThree.pos.y = static_cast<float>((GetScreenHeight() / 2));
		drawButton(mouse, buttonCredits.buttonThree);
		DrawText("https://soundsbydane.itch.io/8-bit-sound-pack", static_cast<int>(buttonCredits.buttonThree.pos.x) + 20, static_cast<int>(buttonCredits.buttonThree.pos.y) + 10, 20, BLACK);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && buttonCredits.buttonThree.isSelected)
		{
			OpenURL("https://soundsbydane.itch.io/8-bit-sound-pack");
		}

		buttonCredits.buttonFour.pos.x = static_cast<float>(100);
		buttonCredits.buttonFour.pos.y = static_cast<float>((GetScreenHeight() / 2) + 100);
		drawButton(mouse, buttonCredits.buttonFour);
		DrawText("https://danzmacabre.itch.io/free-8-bit-music-asset-pack", static_cast<int>(buttonCredits.buttonFour.pos.x) + 20, static_cast<int>(buttonCredits.buttonFour.pos.y) + 10, 20, BLACK);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && buttonCredits.buttonFour.isSelected)
		{
			OpenURL("https://danzmacabre.itch.io/free-8-bit-music-asset-pack");
		}

		buttonBack.pos.x = static_cast<float>(100);
		buttonBack.pos.y = static_cast<float>(GetScreenHeight() - 100);
		drawButton(mouse, buttonBack);
		DrawText("BACK", static_cast<int>(buttonBack.pos.x) + 20, static_cast<int>(buttonBack.pos.y) + 10, 20, BLACK);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && buttonBack.isSelected)
		{
			gameScreen = GameScreen::Menu;
		}

		EndDrawing();
	}
}