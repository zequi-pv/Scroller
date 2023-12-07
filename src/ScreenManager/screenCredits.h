#pragma once
#include "raylib.h"
#include "Elements/Button.h"
#include "GameData/Game.h"

namespace game 
{
	struct ButtonCredits 
	{
		Button buttonOne;
		Button buttonTwo;
		Button buttonThree;
		Button buttonFour;
	};

	ButtonCredits initButtonCredits(Button buttonOne, Button buttonTwo, Button buttonThree, Button buttonFour);
	void drawCredits(Vector2 mouse, ButtonCredits buttonCredits, Button buttonBack, GameScreen& gameScreen);
}