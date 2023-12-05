#pragma once
#include "raylib.h"

namespace game
{
	enum class GameScreen
	{
		Menu,
		GamePlay,
		Credits,
		Exit
	};
	extern GameScreen gameScreen;

	void ScenesSwitch();
}