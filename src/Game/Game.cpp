#include "Game.h"

#include "raylib.h"

#include "Screen.h"
#include "Ship.h"

namespace game
{
	void game()
	{
		screen::openWindow();

		ship::Ship ship;

		ship::init(ship);

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
