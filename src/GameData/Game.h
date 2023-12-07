#pragma once
#include "raylib.h"
#include "Elements/Button.h"

namespace game
{
	enum class GameScreen
	{
		Menu,
		GamePlay,
		Credits,
		Exit
	};

	void gameLoop(Vector2 mouse);
	void runGame();
	void resetGame();
}