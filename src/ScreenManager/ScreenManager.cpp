#include "ScreenManager.h"
#include "GameData/Game.h"
#include "screenGameplay.h"

#include "Menu.h"
#include <iostream>

using namespace std;

namespace game
{
	void ScenesSwitch(GameScreen& gameScreen, Button& buttonPlay, Button& buttonCredits, Button& buttonExit, bool& isGameRunning, Texture2D background, Music menuMusic, ButtonCredits& buttonCredit, Button& buttonBack)
	{

		Vector2 mouse = { static_cast<float>(GetMouseX()), static_cast<float>(GetMouseY()) };
		
		switch (gameScreen)
		{
		case GameScreen::Menu:
			drawMenu(mouse, buttonPlay, buttonCredits, buttonExit, gameScreen, background, menuMusic);
			break;
		case GameScreen::GamePlay:
			gameLoop(mouse);
			break;
		case GameScreen::Credits:
			drawCredits(mouse, buttonCredit, buttonBack, gameScreen);
			break;
		case GameScreen::Exit:
			isGameRunning = true;
			break;
		default:
			break;
		}
	}
}