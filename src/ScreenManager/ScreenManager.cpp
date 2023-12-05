#include "ScreenManager.h"
#include "GameData/Game.h"
#include "screenGameplay.h"
#include "screenCredits.h"
#include "Menu.h"
#include <iostream>

using namespace std;

namespace game
{
	void ScenesSwitch(GameScreen& gameScreen, Button& buttonPlay, Button& buttonCredits, Button& buttonExit, bool& isGameRunning)
	{

		Vector2 mouse = { static_cast<float>(GetMouseX()), static_cast<float>(GetMouseY()) };
		
		switch (gameScreen)
		{
		case GameScreen::Menu:
			drawMenu(mouse, buttonPlay, buttonCredits, buttonExit, gameScreen);
			break;
		case GameScreen::GamePlay:
			gameLoop();
			break;
		case GameScreen::Credits:
			drawCredits();
			break;
		case GameScreen::Exit:
			isGameRunning = true;
			break;
		default:
			break;
		}
	}
}