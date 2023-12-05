#include "Menu.h"
#include "GameData/Game.h"

namespace game
{
	extern bool isGameRunning;

	void ScenesSwitch()
	{
		Vector2 mouse = { static_cast<float>(GetMouseX()), static_cast<float>(GetMouseY()) };

		switch (gameScreen)
		{
		case game::GameScreen::Menu:
			break;
		case game::GameScreen::GamePlay:
			break;
		case game::GameScreen::Credits:
			break;
		case game::GameScreen::Exit:
			isGameRunning = true;
			break;
		default:
			break;
		}
	}
}