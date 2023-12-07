#include "Button.h"
#include <iostream>

using namespace std;
namespace game
{
	Button initButton(Vector2 size)
	{
		Button button;
		button.size = size;
		button.isSelected = false;
		button.colorOne = RAYWHITE;
		button.colorTwo = GRAY;
		return button;
	}

	bool optionsCollision(Vector2 mouse, Button button)
	{
		return	mouse.x > button.pos.x
			&& mouse.x < button.pos.x + button.size.x
			&& mouse.y > button.pos.y
			&& mouse.y < button.pos.y + button.size.y;
	}

	void drawButton(Vector2 mouse, Button& button)
	{
		DrawRectangle(static_cast<int>(button.pos.x), static_cast<int>(button.pos.y), static_cast<int>(button.size.x), static_cast<int>(button.size.y), button.colorOne);
		if (optionsCollision(mouse, button))
		{
			button.isSelected = true;
			DrawRectangle(static_cast<int>(button.pos.x), static_cast<int>(button.pos.y), static_cast<int>(button.size.x), static_cast<int>(button.size.y), button.colorTwo);
		}
		else if (!optionsCollision(mouse, button))
		{
			button.isSelected = false;
		}
	}
}