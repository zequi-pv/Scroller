#include "Menu.h"
#include <iostream>

using namespace std;
namespace game
{
	void drawMenu(Vector2 mouse, Button& buttonPlay, Button& buttonCredits, Button& buttonExit, GameScreen& gameScreen)
	{
		BeginDrawing();
		ClearBackground(BLACK);
		SetExitKey(KEY_ESCAPE);
		buttonPlay.pos.x = static_cast<float>((GetScreenWidth() / 2) - buttonPlay.size.x / 2);
		buttonPlay.pos.y = static_cast<float>((GetScreenHeight() / 2) - 50);
		drawButton(mouse, buttonPlay);
		DrawText("PLAY", static_cast<int>(buttonPlay.pos.x) + 20, static_cast<int>(buttonPlay.pos.y) + 10, 20, BLACK);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && buttonPlay.isSelected)
		{
			gameScreen = GameScreen::GamePlay;
		}

		buttonCredits.pos.x = static_cast<float>((GetScreenWidth() / 2) - buttonCredits.size.x / 2);
		buttonCredits.pos.y = static_cast<float>((GetScreenHeight() / 2));
		drawButton(mouse, buttonCredits);
		DrawText("CREDITS", static_cast<int>(buttonCredits.pos.x) + 20, static_cast<int>(buttonCredits.pos.y) + 10, 20, BLACK);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && buttonCredits.isSelected)
		{
			gameScreen = GameScreen::Credits;
		}
		
		buttonExit.pos.x = static_cast<float>((GetScreenWidth() / 2) - buttonExit.size.x / 2);
		buttonExit.pos.y = static_cast<float>((GetScreenHeight() / 2) + 50);
		drawButton(mouse, buttonExit);
		DrawText("EXIT", static_cast<int>(buttonExit.pos.x) + 20, static_cast<int>(buttonExit.pos.y) + 10, 20, BLACK);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && buttonExit.isSelected == true)
		{
			gameScreen = GameScreen::Exit;
		}

		EndDrawing();
	}
}