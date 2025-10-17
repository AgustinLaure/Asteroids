#include "Game.h"

#include "raylib.h"

#include "Screen.h"

namespace game
{
	void game()
	{
		screen::openWindow();

		while (!WindowShouldClose())
		{
			update();
			draw();
		}

		screen::closeWindow();
	}

	void update()
	{

	}

	void draw()
	{
		BeginDrawing();
		ClearBackground(BLACK);

		EndDrawing();
	}
}
