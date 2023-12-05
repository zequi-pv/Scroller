#pragma once
#include "raylib.h"
#include "Elements/Button.h"
#include "GameData/Game.h"

namespace game
{
	void ScenesSwitch(GameScreen& gameScreen, Button& buttonPlay, Button& buttonCredits, Button& buttonExit, bool& isGameRunning);
}