#include "ScreenManager.h"
#include "GameData/Game.h"
#include "screenGameplay.h"
#include "Menu.h"

namespace game
{
	void ScenesSwitch(GameScreen& gameScreen, Button& buttonPlay, Button& buttonCredits, Button& buttonExit, bool& isGameRunning, Texture2D background, ButtonCredits& buttonCredit, Button& buttonBack)
	{

		Vector2 mouse = { static_cast<float>(GetMouseX()), static_cast<float>(GetMouseY()) };
		
		switch (gameScreen)
		{
		case GameScreen::Menu:
			drawMenu(mouse, buttonPlay, buttonCredits, buttonExit, gameScreen, background);
			break;
		case GameScreen::GamePlay:
			gameLoop(mouse);
			break;
		case GameScreen::Credits:
			drawCredits(mouse, buttonCredit, buttonBack, gameScreen, background);
			break;
		case GameScreen::Exit:
			isGameRunning = true;
			break;
		default:
			break;
		}
	}
}