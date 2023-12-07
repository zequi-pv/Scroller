#pragma once
#include "raylib.h"
#include "Elements/Button.h"
#include "GameData/Game.h"
#include "screenCredits.h"

namespace game
{
	void ScenesSwitch(GameScreen& gameScreen, Button& buttonPlay, Button& buttonCredits, Button& buttonExit, bool& isGameRunning, Texture2D background, Music menuMusic, ButtonCredits& buttonCredit, Button& buttonBack);
}