#include "screenGameplay.h"

namespace game
{
	void drawGame(Player player, Enemy enemies[], int maxEnemies) 
	{
		BeginDrawing();
		ClearBackground(BLACK);
		drawPlayer(player);
		drawEnemies(enemies, maxEnemies);
		EndDrawing();
	}
}