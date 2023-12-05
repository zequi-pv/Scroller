#include "screenGameplay.h"

namespace game
{
	void drawGame(Player player) 
	{
		BeginDrawing();
		ClearBackground(BLACK);
		drawPlayer(player);
		EndDrawing();
	}
}