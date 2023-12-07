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

	void drawCredits(Vector2 mouse, ButtonCredits buttonCredits, Button buttonBack, GameScreen& gameScreen)
	{
		BeginDrawing();
		ClearBackground(BLACK);
		DrawText("Programming by Ezequiel Prieto", 200, (GetScreenHeight() / 2) - 100, 20, YELLOW);
		DrawText("Planes and bullet assets by Ezequiel Prieto", 200, (GetScreenHeight() / 2) - 50, 20, YELLOW);
		DrawText("Parallax background assets by Free Game Assets", 200, (GetScreenHeight() / 2), 20, YELLOW);
		DrawText("Shoot sound by SoundByDane", 200, (GetScreenHeight() / 2) + 50, 20, YELLOW);
		DrawText("Menu music by Thatguynm", 200, (GetScreenHeight() / 2) + 100, 20, YELLOW);
		buttonCredits;
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