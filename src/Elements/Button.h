#pragma once
#include "raylib.h"

namespace game
{
	struct Button
	{
		Vector2 pos;
		Vector2 size;
		bool isSelected;
	};

	Button initButton(Vector2 size);
	bool optionsCollision(Vector2 mouse, Button button);
	void drawButton(Vector2 mouse, Button& button);
}