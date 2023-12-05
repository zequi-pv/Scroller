#pragma once
#include "raylib.h"
#include "GameData/Game.h"
#include "Elements/Button.h"
#include "ScreenManager.h"

namespace game
{
	void drawMenu(Vector2 mouse, Button& buttonPlay, Button& buttonCredits, Button& buttonExit, GameScreen& gameScreen);
}